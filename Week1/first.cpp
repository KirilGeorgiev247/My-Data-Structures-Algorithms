#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main() {
    string str;
    unsigned int N;
    char S;

    cin >> str;
    cin >> N;
    cin >> S;

    if (strlen(str.c_str()) > 100 || strlen(str.c_str()) < 1) return 0;

    unsigned int letCount = 0;
    unsigned int counter = 0;
    unsigned int index = 0;

    while (true) {
        if (str[index] == S) letCount++;
        if (str[index++] == '\0') {
            index = 0;
            --counter;
        }
        if (++counter == N) break;
    }

    cout << letCount;
    return 0;
}