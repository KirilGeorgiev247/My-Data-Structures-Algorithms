const int MAX_SIZE = 1e5;

void countingSort(int* arr, size_t length) {
    int arrCopy[MAX_SIZE];

    int max = arr[0];
    for (int i = 0; i < length; ++i) {
        if (max < arr[i]) {
            max = arr[i];
        }
        arrCopy[i] = arr[i];
    }

    int count[MAX_SIZE];
    for (int i = 0; i < max + 1; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < length; ++i) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = length - 1; i >= 0; --i) {
        arr[count[arrCopy[i]] - 1] = arrCopy[i];
        count[arrCopy[i]]--;
    }
}