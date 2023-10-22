#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int GetNumsCountInInterval(vector<int>& v, int N, int a, int b) {
    int aIndex = lower_bound(v.begin(), v.end(), a) - v.begin();

    int bIndex = upper_bound(v.begin(), v.end(), b) - v.begin();

    if (aIndex == -1 || bIndex == -1)
        return 0;

    return bIndex - aIndex;
}

int main() {
    int N;
    int Q;
    int a;
    int b;

    cin >> N >> Q;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    for (int i = 0; i < Q; i++)
    {
        cin >> a >> b;

        int count = GetNumsCountInInterval(v, N, a, b);
        if (count > 0)
            cout << count;
        else
            cout << 0;

        if (i != Q - 1)
            cout << '\n';
    }
}
