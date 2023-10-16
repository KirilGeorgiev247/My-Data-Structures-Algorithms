#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    int T;
    int N;
    int K;
    string str;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N >> K >> str;

        int st[26] = { 0 };

        for (int i = 0; i < N; i++) {
            if ((int)str[i] >= (int)'A' && (int)str[i] <= (int)'Z')
                st[26 - ((int)'Z' - (int)str[i]) - 1]++;
        }

        for (int i = 0; i < 26; i++) {
            if (st[i] >= K) {
                cout << (char)((int)'A' + i);
            }
        }

        if (i + 1 < T)
            cout << endl;
    }

    return 0;
}