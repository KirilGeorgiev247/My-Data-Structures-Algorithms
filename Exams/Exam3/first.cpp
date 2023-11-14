#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int N;
int K;
int num;

int main() {
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> K;
        stack<int> nums;
        bool isValid = true;
        
        for(int j = 0; j < K; j++) {
            cin >> num;
            if(num == 0) {
                isValid = false;
            }
            
            if(!nums.empty() && num == -nums.top()) {
                nums.pop();
            }
            else {
                nums.push(num);
            }
        }
        
        if(nums.empty() && isValid)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}
