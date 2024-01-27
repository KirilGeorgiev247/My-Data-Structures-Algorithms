#include <algorithm>

using namespace std;

void heapify(int* arr, int heapSize, int nodeIndex) {
    int largest = nodeIndex;
    int left = 2 * nodeIndex + 1;
    int right = 2 * nodeIndex + 2;

    if (left < heapSize && arr[left] > arr[largest])
        largest = left;

    if (right < heapSize && arr[right] > arr[largest])
        largest = right;

    if (largest != nodeIndex) {
        swap(arr[nodeIndex], arr[largest]);
        heapify(arr, heapSize, largest);
    }
}

void heapSort(int* arr, int arraySize) {
    for (int i = arraySize / 2 - 1; i >= 0; i--)
        heapify(arr, arraySize, i);

    for (int i = arraySize - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}
