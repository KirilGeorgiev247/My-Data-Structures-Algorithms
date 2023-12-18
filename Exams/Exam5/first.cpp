#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    string s;
    int F, S;
    
    for(int i = 0; i < T; i++) {
        bool isPos = true;
        cin >> F >> S;
        unordered_map<string, int> fm;

        
        for(int j = 0; j < F; j++) {
            cin >> s;
            fm[s]++;
        }
        
        for(int j = 0; j < S; j++) {
            cin >> s;
            if(!fm.count(s) || fm[s] <= 0) {
                isPos = false;
            }
            
            fm[s]--;
        }
        
        cout << (isPos ? "Yes" : "No") << '\n';
        isPos = true;
        fm.clear();
    }
    
    return 0;
}