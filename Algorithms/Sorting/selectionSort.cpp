#include <algorithm>

using namespace std;

void selectionSort(int* arr, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        size_t minInd = i;

        for (size_t j = i + 1; j < size; j++)
            if (arr[j] < arr[minInd])
                minInd = j;

        if (i != minInd)
            swap(arr[i], arr[minInd]);
    }
}