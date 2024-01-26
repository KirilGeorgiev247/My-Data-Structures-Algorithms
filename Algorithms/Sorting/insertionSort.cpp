#include <algorithm>

using namespace std;

void insertionSort(int* arr, size_t size) {
    for (size_t i = 1; i < size; i++) {
        int insertedEl = arr[i];
        int j = i - 1;

        while (j != -1 && arr[j] > insertedEl) {
            arr[j + 1] = arr[j];
            j--;
        }

        swap(arr[j + 1], insertedEl);
    }
}