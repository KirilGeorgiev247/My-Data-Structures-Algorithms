#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    int N;
    vector<tuple<double, double, double, int>> v;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        tuple<double, double, double, int> t;
        cin >> get<1>(t) >> get<2>(t);
        get<0>(t) = pow((get<1>(t) / 2), 2) / get<2>(t);
        get<3>(t) = i + 1;
        v.push_back(t);
    }

    sort(v.rbegin(), v.rend());

    for (int i = 0; i < N; i++)
    {
        cout << get<3>(v[i]);
        if (N - 1 != i) cout << " ";
    }
}