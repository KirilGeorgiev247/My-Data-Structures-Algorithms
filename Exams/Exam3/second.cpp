#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    int count;
    vector<Node*> children;
};

int N;
int x;
int y;

vector<Node> nodes(1000000);

int setChildren(Node* root) {
    if(!root) {
        return 0;
    }
    
    for(int i = 0; i < root->children.size(); i++) {
        int count = setChildren(root->children[i]);
        root->count += count;
    }
    
    return root->count + 1;
}

int main() {
    
    cin >> N;
    
    for(int i = 0; i < N - 1; i++) {
        cin >> x >> y;
        nodes[x].children.push_back(&nodes[y]);
    }
    
    setChildren(&nodes[0]);
    
    for(int i = 0; i < N; i++) {
        cout << nodes[i].count << " ";
    }
    
    return 0;
}
