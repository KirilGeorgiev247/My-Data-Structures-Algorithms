void merge(int* arr, size_t firstSize, int* arr2, size_t secondSize, int* buffer) {
    int firstInd = 0;
    int secondInd = 0;
    int bufferIndex = 0;

    // Merge arrays into buffer
    while (firstInd < firstSize && secondInd < secondSize) {
        if (arr[firstInd] <= arr2[secondInd])
            buffer[bufferIndex++] = arr[firstInd++];
        else
            buffer[bufferIndex++] = arr2[secondInd++];
    }

    // Copy remaining elements from arr
    while (firstInd < firstSize)
        buffer[bufferIndex++] = arr[firstInd++];

    // Copy remaining elements from arr2
    while (secondInd < secondSize)
        buffer[bufferIndex++] = arr2[secondInd++];

    // Copy back the merged elements to original array
    for (int i = 0; i < firstSize + secondSize; i++)
        arr[i] = buffer[i];
}

void mergeSortStep(int* arr, size_t size, int* buffer) {
    if (size < 2)
        return;

    size_t mid = size / 2;
    mergeSortStep(arr, mid, buffer); // Sort left half
    mergeSortStep(arr + mid, size - mid, buffer); // Sort right half
    merge(arr, mid, arr + mid, size - mid, buffer); // Merge sorted halves
}

void mergeSort(int* arr, size_t size) {
    if (!arr || size == 0)
        return;

    int* buffer = new int[size];

    mergeSortStep(arr, size, buffer);

    delete[] buffer;
}