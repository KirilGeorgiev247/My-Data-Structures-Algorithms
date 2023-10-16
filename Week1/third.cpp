#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    int K;
    int min = 1000000001;
    int all[10000] = { 0 };
    int group[2500] = { 0 };

    cin >> N;
    cin >> K;

    for (int i = 0; i < N; i++) {
        cin >> all[i];
    }

    sort(all, all + N);

    for (int i = 0; i < N; i++)
    {
        if (N - i < K) break;

        int diff = all[K + i - 1] - all[i];

        if (diff < min) min = diff;
    }
    cout << min;

    return 0;
}