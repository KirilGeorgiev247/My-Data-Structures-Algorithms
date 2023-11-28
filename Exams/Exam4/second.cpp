#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

void insert(priority_queue<int, vector<int>, greater<int>>& minHeap, 
            priority_queue<int, vector<int>, less<int>>& maxHeap, int N) {
    
    if(maxHeap.empty() || maxHeap.top() > N) {
        maxHeap.push(N);
    }
    else {
        minHeap.push(N);
    }
    
    if(maxHeap.size() - minHeap.size() == 2) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    
    if(minHeap.size() - maxHeap.size() == 2) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}

double findMedian(priority_queue<int, vector<int>, greater<int>>& minHeap, 
            priority_queue<int, vector<int>, less<int>>& maxHeap) {
    if(minHeap.size() == maxHeap.size()) {
        return (minHeap.top() + maxHeap.top()) / 2.0;
    }
    
    return maxHeap.size() > minHeap.size() ?
        maxHeap.top() : minHeap.top();
}

int main() {
    cout << fixed << setprecision(1);
    int N, M;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> M;
        insert(minHeap, maxHeap, M);
        cout << findMedian(minHeap, maxHeap) << '\n';
    }
    
    return 0;
}
