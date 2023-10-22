#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isPartionable(int* arr, long long currSum, int subsets, int size) {
    int currSubsetsCount = 1;
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > currSum)
            return false;

        sum += arr[i];
        if (sum > currSum) {
            sum = arr[i];
            currSubsetsCount++;
        }
    }

    if (currSubsetsCount <= subsets)
        return true;

    return false;

}

int getMaxValue(int* arr, int size) {
    int maxValue = arr[0];
    for (int i = 0; i < size; i++)
        maxValue = max(maxValue, arr[i]);

    return maxValue;
}

long long MinMaxValueOfSubset(int* arr, int subsets, int size) {
    long long left = getMaxValue(arr, size);
    long long right = 0;

    for (int i = 0; i < size; i++)
        right += arr[i];

    long long result = right;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (isPartionable(arr, mid, subsets, size)) {
            result = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return result;
}

int main() {
    int arr[100000];
    int N;
    int T;
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << MinMaxValueOfSubset(arr, T, N);

    return 0;
}