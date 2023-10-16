#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getIndex(char ch) {
    /*bool isDigit = ;
    bool isSmallLetter = ;*/

    if (ch >= '0' && ch <= '9') return ch - '0';
    else if (ch >= 'a' && ch <= 'z') return ch - 'a' + 11;
    else return ch - 'A' + 37;
}

int main() {

    int N;
    string s;

    cin >> N;
    cin >> s;

    string sc = s;

    int count[62 + 1]; // max + 1

    for (int i = 0; i <= 62; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < N; ++i) {
        count[getIndex(s[i])]++;
    }

    for (int i = 1; i <= 62; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = N - 1; i >= 0; --i) {
        s[count[getIndex(sc[i])] - 1] = sc[i];
        count[getIndex(sc[i])]--;
    }

    cout << s;
}