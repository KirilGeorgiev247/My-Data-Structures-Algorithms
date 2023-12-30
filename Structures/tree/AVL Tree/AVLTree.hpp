#pragma once

template <typename T>
class AVLTree {
private:
    struct Node {
        T value;
        unsigned char depth;
        Node* left, * right;

        Node(T value) : value(value), depth(1), left(nullptr), right(nullptr) {}
    };

    Node* root;
    size_t size;

private:
    void copyRecursive(Node*& destNode, Node* srcNode) {
        if (srcNode) {
            destNode = new Node(srcNode->value);
            destNode->depth = srcNode->depth;
            copyRecursive(destNode->left, srcNode->left);
            copyRecursive(destNode->right, srcNode->right);
        }
    }

public:
    AVLTree() : root(nullptr), size(0) {}

    AVLTree(const AVLTree& other) : root(nullptr), size(0) {
        copyRecursive(root, other.root);
    }

    AVLTree& operator=(const AVLTree& other) {
        if (this != &other) {
            clear();
            copyRecursive(root, other.root);
            size = other.size;
        }
        return *this;
    }

    AVLTree(AVLTree&& other) noexcept : root(other.root), size(other.size) {
        other.root = nullptr;
        other.size = 0;
    }

    AVLTree& operator=(AVLTree&& other) noexcept {
        if (this != &other) {
            clear();
            root = other.root;
            size = other.size;
            other.root = nullptr;
            other.size = 0;
        }
        return *this;
    }

    unsigned char depth(Node* p) const {
        return p ? p->depth : 0;
    }

    int bFactor(Node* p) const {
        return depth(p->right) - depth(p->left);
    }

    void fixDepth(Node* p) {
        unsigned char leftDepth = depth(p->left);
        unsigned char rightDepth = depth(p->right);
        p->depth = (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }

    Node* rotateRight(Node* p) {
        Node* q = p->left;
        p->left = q->right;
        q->right = p;
        fixDepth(p);
        fixDepth(q);
        return q;
    }

    Node* rotateLeft(Node* q) {
        Node* p = q->right;
        q->right = p->left;
        p->left = q;
        fixDepth(q);
        fixDepth(p);
        return p;
    }

    Node* balance(Node* p) {
        fixDepth(p);
        if (bFactor(p) == 2) {
            if (bFactor(p->right) < 0)
                p->right = rotateRight(p->right);
            return rotateLeft(p);
        }
        if (bFactor(p) == -2) {
            if (bFactor(p->left) > 0)
                p->left = rotateLeft(p->left);
            return rotateRight(p);
        }
        return p;
    }

    Node* findMin(Node* p) {
        return p->left ? findMin(p->left) : p;
    }

    Node* removeMin(Node* p) {
        if (p->left == 0)
            return p->right;
        p->left = removeMin(p->left);
        return balance(p);
    }

    void clear() {
        clearWithRoot(root);
        root = nullptr;
        size = 0;
    }

    Node* find(T value) const {
        return findWithRoot(root, value);
    }

    bool contains(T value) const {
        return find(value) != nullptr;
    }

    void insert(T value) {
        root = insertWithRoot(root, value);
    }

    void remove(T value) {
        root = removeWithRoot(root, value);
    }

    ~AVLTree() {
        clear();
    }

private:
    Node* insertWithRoot(Node* node, T value) {
        if (!node) {
            size++;
            return new Node(value);
        }

        if (value < node->value)
            node->left = insertWithRoot(node->left, value);
        else if (value > node->value)
            node->right = insertWithRoot(node->right, value);
        else
            return node; // duplicated values are not inserted

        return balance(node);
    }

    Node* removeWithRoot(Node* node, T value) {
        if (!node) return nullptr;

        if (value < node->value)
            node->left = removeWithRoot(node->left, value);
        else if (value > node->value)
            node->right = removeWithRoot(node->right, value);
        else {
            Node* q = node->left;
            Node* r = node->right;
            delete node;
            size--;

            if (!r) return q;
            Node* min = findMin(r);
            min->right = removeMin(r);
            min->left = q;
            return balance(min);
        }

        return balance(node);
    }

    Node* findWithRoot(Node* node, T value) const {
        if (!node) return nullptr;
        if (value < node->value) return findWithRoot(node->left, value);
        if (value > node->value) return findWithRoot(node->right, value);
        return node;
    }
};