#include <bits/stdc++.h>
using namespace std;

int getIndex(char ch) {
    if(ch >= '0' && ch <= '9') {
        return 9 - ('9' - ch);
    }
    
    if(ch >= 'a' && ch <= 'z') {
        return (26 - ('z' - ch)) + 10;
    }
    
    if(ch >= 'A' && ch <= 'Z') {
        return (26 - ('Z' - ch)) + 36;
    }
    
    return 0;
}

int main() {
    string s;
    
    cin >> s;
    
    const int MAX_SIZE = 2*1e7;
    
    int count[62] = {0};
    
    for(int i = 0; i < s.size(); i++) {
        count[getIndex(s[i])]++;
    }
    
    int counter = 0;
    
    for(int i = 0; i < s.size(); i++) {
        if(count[getIndex(s[i])] == 1)
            counter++;
    }
    
    int sCounter = 0;
    
    for(int i = 0; i < s.size(); i++) {
        if(count[getIndex(s[i])] == 1) {
            if(sCounter + 1 == counter) cout << i;
            else {
                sCounter++;
                cout << i << " ";
            }
        }
    }
    
    return 0;
}