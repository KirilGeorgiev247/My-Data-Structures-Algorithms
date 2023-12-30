#pragma once

#include <iostream>
#include <queue>

template <typename T>
struct Node;

template <typename T>
class BinarySearchTree {
private:
	Node<T>* root;

	Node<T>* insertwithRoot(Node<T>* current, const T& value) {
		if (!current) {
			return new Node<T>(value);
		}

		if (current->value < value) {
			current->right = _insert(current->right, value);
		}
		else if (value < current->value) {
			current->left = _insert(current->left, value);
		}

		return current;
	}

	bool containsWithRoot(const Node<T>* current, const T& value) const {
		if (!current) {
			return false;
		}

		if (current->value == value) {
			return true;
		}

		return current->value > value ? contains(current->left, value) : contains(current->right, value);
	}

	Node<T>* removeWithRoot(Node<T>* current, const T& value) {
		if (!current) {
			return nullptr;
		}

		if (value < current->value) {
			current->left = _remove(current->left, value);
		}
		else if (current->value < value) {
			current->right = _remove(current->right, value);
		}
		else {
			if (!current->left && !current->right) {
				return nullptr;
			}
			if (!current->left) {
				return current->right;
			}
			if (!current->right) {
				return current->left;
			}

			Node<T>* iter = current->right;

			while (iter->left) {
				iter = iter->left;
			}

			current->value = iter->value;
			current->right = _remove(current->right, current->value);
		}

		return current;
	}

	void dfsWithRoot(const Node<T>* current) const {
		if (!current) {
			return;
		}
		
		// do something before visiting the two children
		dfsWithRoot(current->left);
		// do something in the middle
		dfsWithRoot(current->right);
		// do something after visiting the two children
	}
public:
	BinarySearchTree() {
		root = nullptr;
	}

	BinarySearchTree(const BinarySearchTree<T>& other) {
		copyFrom(other);
	}

	BinarySearchTree<T>& operator=(const BinarySearchTree<T>& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}

		return *this;
	}

	~BinarySearchTree() {
		free();
	}

	bool contains(const T&) const {
		return containsWithRoot(root, value);
	}
	void insert(const T&) {
		root = insertwithRoot(root, value);
	}
	void remove(const T&) {
		root = removeWithRoot(root, value);
	}

	void dfs() const {
		dfsWithRoot(root);
	}
	void bfs() const {
		queue<Node<T>*> level;
		level.push(root);

		while (!level.empty()) {
			Node<T>* current = level.front();
			level.pop();

			if (current) {
				// do something with the current node

				level.push(current->left);
				level.push(current->right);
			}
		}
	}

private:
	void copyFrom(const BinarySearchTree&) {
		root = new Node<T>(*other.root);
	}

	void free() {
		delete root;
	}
};

template <typename T>
struct Node {
	T value;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(const T& value) : value(value) { }

	Node(const Node<T>& other) {
		copyFrom(other);
	}

	Node& operator=(const Node<T>& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}

		return *this;
	}

	~Node() {
		free();
	}

private:
	void free() {
		delete left;
		delete right;
		left = right = nullptr;
	}

	void copyFrom(const Node<T>& other) {
		value = other.value;

		if (other.right) {
			right = new Node(*other.right);
		}

		if (other.left) {
			left = new Node(*other.left);
		}
	}
};