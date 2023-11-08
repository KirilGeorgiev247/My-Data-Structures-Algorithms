#include <bits/stdc++.h>

using namespace std;

struct Node {
    long long key;
    Node* left;
    Node* right;
};

long long getMaxSum(Node* root, long long& result) {
    if (!root)
        return 0;

    long long leftSum = getMaxSum(root->left, result);
    long long rightSum = getMaxSum(root->right, result);
    
    long long maxSumWithRightOrLeft
        = max(max(leftSum, rightSum) + root->key, root->key);

    long long maxSumBetweenSingleAndWithBoth = 
        max(maxSumWithRightOrLeft, leftSum + rightSum + root->key);

    result = 
        max(result, maxSumBetweenSingleAndWithBoth);

    return maxSumWithRightOrLeft;
}

int N;
int leftIndex;
int rightIndex;
int key;
long long result = LLONG_MIN;
vector<Node> nodes(4000000);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> key >> leftIndex >> rightIndex;

        nodes[i].key = key;

        if (leftIndex != -1)
            nodes[i].left = &nodes[leftIndex];
        else
            nodes[i].left = nullptr;

        if (rightIndex != -1)
            nodes[i].right = &nodes[rightIndex];
        else
            nodes[i].right = nullptr;
    }

    getMaxSum(&nodes[0], result);

    cout << result;
}