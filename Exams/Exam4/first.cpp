#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    long long N, S, P;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    cin >> N >> S;
    
    for(int i = 0; i < N; i++) {
        cin >> P;
        pq.push(P);
    }
    
    int count = 0;
    
    while(!pq.empty()) {
        if(pq.top() >= S) {
            cout << count;
            break;
        }
        
        if(pq.size() < 2) {
            cout << -1;
            return 0;
        }
        
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        long long c = a + 2*b;
        pq.push(c);
        count++;
    }
    
    return 0;
}