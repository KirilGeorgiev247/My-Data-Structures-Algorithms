#include <bits/stdc++.h>
using namespace std;

int getCount(int* arr, int left, int right, int D, int N) {
    if (right == N) return 0;

    if (arr[right] - arr[left] < D)
        return getCount(arr, left, right + 1, D, N);
    else if (arr[right] - arr[left] > D)
        return getCount(arr, left + 1, right, D, N);
    else
        return getCount(arr, left + 1, right + 1, D, N) + 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int D;

    int arr[100000];

    cin >> N >> D;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    cout << getCount(arr, 0 , 0, D, N);
}