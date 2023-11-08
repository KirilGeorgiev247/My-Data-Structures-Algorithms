#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
    Point() : x(0), y(0) {}
};

struct Node {
    int key;
    Point point;
    Node* left;
    Node* right;
};

void setPoints(Node* root, int x, int y) {
    if (!root)
        return;

    root->point = Point(x, y);

    setPoints(root->left, x - 1, y + 1);
    setPoints(root->right, x + 1, y + 1);
}

void setSums(Node* root, vector<long>& negSums, vector<long>& posSums) {
    if (!root)
        return;

    if (root->point.x < 0)
        negSums[root->point.x * -1] += root->key;
    else
        posSums[root->point.x] += root->key;

    setSums(root->left, negSums, posSums);
    setSums(root->right, negSums, posSums);
}

int main() {
    int N;
    int key;
    int leftIndex;
    int rightIndex;

    cin >> N;

    vector<long> positiveSums(N);
    vector<long> negativeSums(N);
    vector<Node> nodes(N);

    for (int i = 0; i < N; i++) {
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

    setPoints(&nodes[0], 0, 0);
    setSums(&nodes[0], negativeSums, positiveSums);

    for (int i = negativeSums.size() - 1; i > 0; i--) {
        if (negativeSums[i] != 0)
            cout << negativeSums[i] << " ";
    }

    for (int i = 0; i < positiveSums.size(); i++) {
        if (positiveSums[i] != 0)
            cout << positiveSums[i] << " ";
    }
}
