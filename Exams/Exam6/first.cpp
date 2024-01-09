#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int parents[100001];
int sizes[100001];

int Find(int node) {
    if(node == parents[node]) return node;
    return parents[node] = Find(parents[node]);
}

bool Union(int first, int second) {
    int r1 = Find(first);
    int r2 = Find(second);
    
    if(r1 == r2) return false;
    
    if(sizes[r1] == sizes[r2]) {
        sizes[r1]++;
        parents[r2] = r1;
    } else if (sizes[r1] > sizes[r2]) {
        parents[r2] = r1;
    } else {
        parents[r1] = r2;
    }
    
    return true;
}

int main() {
    int N;
    cin >> N;
    
    int all = N;
    
    for(int i = 1; i < N; i++) {
        parents[i] = i;
        sizes[i] = 1;
    }
    
    int x, y;
    
    while(cin >> x >> y) {
        int root1 = Find(x);
        int root2 = Find(y);
        if(root1 != root2) {
            all--;
        }
        cout << all << " ";
        if(!Union(x, y)) {
            cout << "CYCLE FORMED!" << '\n';
        } else {
            cout << '\n';
        }
    }
    
    return 0;
}
