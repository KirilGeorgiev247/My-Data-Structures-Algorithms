#include <algorithm>

using namespace std;

void bubbleSort(int* arr, int length) {
    int endIndex = length - 1;

    for (int i = 0; i < length; i++)
    {
        int lastSwappedIndex = 0;

        for (int j = 0; j < endIndex; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                lastSwappedIndex = j;
            }
        }

        endIndex = lastSwappedIndex;
        if (lastSwappedIndex == 0)
            return;
    }
}