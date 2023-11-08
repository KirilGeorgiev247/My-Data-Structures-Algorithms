#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node {
    int key;
    int childrenCount;
    Node* left;
    Node* right;
};

int setChildren(Node* root) {
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return 1;

    int leftCount = setChildren(root->left);
    int rightCount = setChildren(root->right);
    root->childrenCount += (leftCount + rightCount);

    return root->childrenCount + 1;
}

void split(Node* root, long long& result, long long count) {
    if (!root)
        return;

    if (root->left && root->right)
    {
        long long rest = count - root->childrenCount == 0 ? 1 : count - root->childrenCount;
        long long leftRest = root->left->childrenCount + 1;
        long long rightRest = root->right->childrenCount + 1;

        //cout << rest * leftRest * rightRest << endl;
        
        result = max(result, rest * leftRest * rightRest);
    }
    else if (root->left) {
        long long rest = count - (root->left->childrenCount + 1);

        //cout << rest * (root->left->childrenCount + 1) << endl;
        
        result = max(result, rest * (root->left->childrenCount + 1));
    }
    else if (root->right) {
        long long rest = count - (root->right->childrenCount + 1);
        
        //cout << rest * (root->right->childrenCount + 1) << endl;
        
        result = max(result, rest * (root->right->childrenCount + 1));
    }
    else
    {
        //cout << count << endl;
        
        result = max(result, count);
    }

    split(root->left, result, count);
    split(root->right, result, count);
}

int main() {
    int N;
    int leftIndex;
    int rightIndex;
    long long result = 0;

    cin >> N;

    vector<Node> nodes(N);

    for (int i = 0; i < N; i++) {
        cin >> leftIndex >> rightIndex;

        nodes[i].key = i;

        if (leftIndex != -1)
            nodes[i].left = &nodes[leftIndex];
        else
            nodes[i].left = nullptr;

        if (rightIndex != -1)
            nodes[i].right = &nodes[rightIndex];
        else
            nodes[i].right = nullptr;
    }

    long long nodesCount = setChildren(&nodes[0]);

    split(&nodes[0], result, nodesCount - 1);

    cout << result;

    //cout << setChildren(&nodes[0]) << endl;

    //for (int i = 0; i < nodes.size(); i++)
    //{
    //    /*cout << nodes[i].key 
    //        << " left: " << (nodes[i].left == nullptr ? -1 : nodes[i].left->key) 
    //        << " right: " << (nodes[i].right == nullptr ? -1 : nodes[i].right->key);
    //    cout << endl;*/

    //    cout << nodes[i].key << " cc: " << nodes[i].childrenCount;
    //    cout << endl;
    //}
}
