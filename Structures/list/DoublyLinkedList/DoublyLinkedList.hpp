#pragma once

#include <optional>
#include <utility>

template<class T>
class DoublyLinkedList {
public:
	class Node {
	public:
		T data;
		Node* next;
		Node* prev;

	public:
		Node(const T& data, Node* prev = nullptr, Node* next = nullptr)
			: data(data), prev(prev), next(next) { }

		bool hasSuccessor() const {
			return next != nullptr;
		}

		bool hasPredecessor() const {
			return prev != nullptr;
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
			if (curr != nullptr) {
				curr->data = newValue;
			}
		}

		void moveNext() {
			if (curr) {
				curr = curr->next;
			}
		}

		void movePrev() {
			if (curr) {
				curr = curr->prev;
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
	Node* tail = nullptr;
	size_t size = 0;
public:
	DoublyLinkedList() {
		head = tail = nullptr;
	}

	DoublyLinkedList(const DoublyLinkedList<T>& other) {
		copyFrom(other);
	}

	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other) {
		if (this != &other)
		{
			copyFrom(other);
			free();
		}

		return *this;
	}

	~DoublyLinkedList() {
		free();
	}

	void pushFront(const T& data) {
		if (!head) {
			head = tail = new Node(data);
			size = 1;
			return;
		}

		Node* newNode = new Node(data, nullptr, head);
		head->prev = newNode;
		head = newNode;
		size++;
	}

	void pushBack(const T& data) {
		if (!tail) {
			head = tail = new Node(data);
			size = 1;
			return;
		}

		Node* newNode = new Node(data, tail);
		tail->next = newNode;
		tail = newNode;
		size++;
	}

	template<typename... Args>
	void emplaceFront(Args&&... args) {
		Node* newNode = 
			new Node(T(std::forward<Args>(args)...), nullptr, head);

		if (!head) tail = newNode;
		else head->prev = newNode;

		head = newNode;
		size++;
	}

	template<typename... Args>
	void emplaceBack(Args&&... args) {
		Node* newNode = 
			new Node(T(std::forward<Args>(args)...), tail, nullptr);

		if (!tail) head = newNode;
		else tail->next = newNode;

		tail = newNode;
		size++;
	}

	void popFront() {
		if (!head) return;

		Node* toBeDeleted = head;

		if (head == tail) head = tail = nullptr;
		else {
			head = head->next;
			head->prev = nullptr;
		}

		delete toBeDeleted;
		size--;
	}

	void popBack() {
		if (!tail) return;

		Node* toBeDeleted = tail;

		if (head == tail) head = tail = nullptr;
		else {
			tail = tail->prev;
			tail->next = nullptr;
		}

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

	std::optional<T> back() const {
		return tail ? tail->data : std::nullopt;
	}

	size_t getSize() const {
		return size;
	}

	Iterator iterator() const {
		return Iterator(head);
	}

private:
	void copyFrom(const DoublyLinkedList<T>& other) {
		Node* iter = other.head;
		while (iter) {
			pushBack(iter->value);
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
		head = tail = nullptr;
	}
};