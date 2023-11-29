#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    string s1, s2;
    unordered_map<string, int> s;

    cin >> s1 >> s2;

    int firstSize = s1.size();
    int secondSize = s2.size();

    for (int i = 0; i < secondSize; i++) {
        string s3 = s2.substr(i, firstSize);
        if (!s.count(s3))
            s[s3] = 0;

        s[s3]++;
    }

    cout << s[s1];

    return 0;
}