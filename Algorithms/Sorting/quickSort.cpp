#include <algorithm>

using namespace std;

size_t partition(int* arr, size_t size) {
    int pivot = arr[size / 2];
    int i = 0;
    int j = size - 1;

    while (true) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

void quickSort(int* arr, size_t size) {
    if (size < 2)
        return;

    size_t pivotIndex = partition(arr, size);

    quickSort(arr, pivotIndex + 1); // Sort the left part
    quickSort(arr + pivotIndex + 1, size - pivotIndex - 1); // Sort the right part
}