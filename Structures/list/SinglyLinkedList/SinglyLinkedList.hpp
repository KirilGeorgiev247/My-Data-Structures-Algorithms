#pragma once

#include <optional>
#include <utility>

template<class T>
class SinglyLinkedList {
public:
    class Node {
    public:
        T data;
        Node* next;

    public:
        Node(const T& data, Node* next = nullptr)
            : data(data), next(next) { }

        bool hasSuccessor() const {
            return next != nullptr;
        }
    };

    class Iterator {
    private:
        Node* start;
        Node* curr;

    public:
        Iterator(Node* start)
            : start(start), curr(start) { }

        std::optional<T> getCurr() const {
            if (curr) {
                return curr->data;
            }

            return std::nullopt;
        }

        void setCurr(const T& newValue) {
            if (curr) {
                curr->data = newValue;
            }
        }

        void moveNext() {
            if (curr) {
                curr = curr->next;
            }
        }

        void reset() {
            curr = start;
        }

        bool end() const {
            return curr == nullptr;
        }

        bool begin() const {
            return curr == start;
        }
    };

private:
    Node* head = nullptr;
    size_t size = 0;

public:
    SinglyLinkedList() : head(nullptr) {}

    SinglyLinkedList(const SinglyLinkedList<T>& other) {
        copyFrom(other);
    }

    SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>& other) {
        if (this != &other) {
            free();
            copyFrom(other);
        }

        return *this;
    }

    ~SinglyLinkedList() {
        free();
    }

    void pushFront(const T& data) {
        Node* newNode = new Node(data, head);
        head = newNode;
        size++;
    }

    void pushBack(const T& data) {
        if (!head) {
            head = new Node(data);
            size = 1;
            return;
        }

        Node* newNode = new Node(data);
        Node* iter = head;

        while (iter->next != nullptr) {
            iter = iter->next;
        }

        iter->next = newNode;
        size++;
    }

    template<typename... Args>
    void emplaceFront(Args&&... args) {
        Node* newNode = 
            new Node(T(std::forward<Args>(args)...), head);

        head = newNode;
        size++;
    }

    template<typename... Args>
    void emplaceBack(Args&&... args) {
        Node* newNode = 
            new Node(T(std::forward<Args>(args)...));

        if (!head) head = newNode;
        else {
            Node* iter = head;

            while (iter->next != nullptr) {
                iter = iter->next;
            }

            iter->next = newNode;
        }
        size++;
    }

    void popFront() {
        if (!head) return;

        Node* toBeDeleted = head;
        head = head->next;

        delete toBeDeleted;
        size--;
    }

    bool contains(const T& data) const {
        Node* iter = head;

        while (iter) {
            if (iter->data == data) return true;
            iter = iter->next;
        }

        return false;
    }

    std::optional<T> front() const {
        return head ? head->data : std::nullopt;
    }

    size_t getSize() const {
        return size;
    }

    Iterator iterator() const {
        return Iterator(head);
    }

private:
    void copyFrom(const SinglyLinkedList<T>& other) {
        Node* iter = other.head;

        while (iter) {
            pushBack(iter->data);
            iter = iter->next;
        }
    }

    void free() {
        Node* iter = head;

        while (iter) {
            Node* next = iter->next;
            delete iter;
            iter = next;
        }

        size = 0;
        head = nullptr;
    }
};
