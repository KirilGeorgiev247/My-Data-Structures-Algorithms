#pragma once

#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class Heap {
private:
	vector<T> dataContainer;

	size_t leftChild(size_t index) const { return index * 2 + 1; }
	size_t rightChild(size_t index) const { return index * 2 + 2; }
	size_t parent(size_t index) const { return (index - 1) / 2; }
public:
	Heap() = default;

	explicit Heap(size_t capacity) {
		dataContainer.reserve(capacity);
	}

	Heap(const vector<T>& data) : dataContainer(data) {
		for (int i = parent(dataContainer.size() - 1); i >= 0; i--) {
			siftDown(i);
		}
	}

	void Heap<T>::push(const T& data) {
		dataContainer.push_back(data);
		if (dataContainer.size() > 1) {
			siftUp(dataContainer.size() - 1);
		}
	}

	bool Heap<T>::empty() const {
		return dataContainer.size() == 0;
	}

	const T& Heap<T>::peek() const {
		return dataContainer[0];
	}

	void Heap<T>::pop() {
		if (dataContainer.size() == 1) {
			dataContainer.pop_back();
			return;
		}

		swap(dataContainer[0], dataContainer[dataContainer.size() - 1]);
		dataContainer.pop_back();
		siftDown(0);
	}

private:
	// Moves element at given index up the heap until heap property is restored
	// Adjusts the heap upwards starting from the given index
	void Heap<T>::siftUp(size_t index) {
		size_t parentIndex = parent(index);

		// Continuously swap with parent if heap property is violated
		while (dataContainer[parentIndex] < dataContainer[index]) {
			swap(dataContainer[parentIndex], dataContainer[index]);
			if (parentIndex == 0) {
				return;
			}

			index = parentIndex;
			parentIndex = parent(parentIndex);
		}
	}

	// Moves element at given index down the heap until heap property is restored
	// Adjusts the heap downwards starting from the given index
	void Heap<T>::siftDown(size_t index) {
		size_t leftChildIndex = leftChild(index);
		size_t rightChildIndex = rightChild(index);

		// Swap with the larger child if current node is smaller than either child
		if (leftChildIndex < dataContainer.size() &&
			rightChildIndex < dataContainer.size() &&
			(dataContainer[index] < dataContainer[leftChildIndex] || dataContainer[index] < dataContainer[rightChildIndex])) {
			size_t swapWithIndex = dataContainer[leftChildIndex] < dataContainer[rightChildIndex] ? rightChildIndex : leftChildIndex;
			swap(dataContainer[index], dataContainer[swapWithIndex]);
			siftDown(swapWithIndex);
		}
		// If only left child exists and is larger than current node
		else if (leftChildIndex < dataContainer.size() &&
			dataContainer[index] < dataContainer[leftChildIndex]) {
			swap(dataContainer[index], dataContainer[leftChildIndex]);
		}
	}
};