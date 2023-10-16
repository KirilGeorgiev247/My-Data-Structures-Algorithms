#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int N;
    cin >> N;
    int* arr = new int[N];
    int* copyArr = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        copyArr[i] = arr[i];
    }

    sort(arr, arr + N);

    int minIndex;
    int maxIndex;

    bool isInitialized = false;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] != copyArr[i])
        {
            if (!isInitialized) {
                minIndex = i;
                isInitialized = true;
            }
            else
                maxIndex = i;
        }
    }

    if (isInitialized) cout << maxIndex - minIndex + 1;
    else cout << 0;
}