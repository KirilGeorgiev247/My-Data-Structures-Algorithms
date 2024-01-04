#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;
int parentsContainer[MAX_N + 1];
int sizes[MAX_N + 1];

int getParent(int vertex) {
    if (parentsContainer[vertex] == vertex) {
        return vertex;
    }
    return parentsContainer[vertex] = getParent(parentsContainer[vertex]);
}

bool areInOneSet(int first, int second) {
    return getParent(first) == getParent(second);
}

void unionVertices(int first, int second) {
    int parentOfFirst = getParent(first);
    int parentOfSecond = getParent(second);

    if(parentOfFirst == parentOfSecond) {
        return;
    }

    if (sizes[parentOfFirst] < sizes[parentOfSecond]) {
        swap(parentOfFirst, parentOfSecond);
    }
    parentsContainer[parentOfSecond] = parentOfFirst;
    sizes[parentOfFirst] += sizes[parentOfSecond];
}

int main() {
    int N, M, Q;
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        parentsContainer[i] = i;
        sizes[i] = 1;
    }

    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        unionVertices(u, v);
    }

    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int p, from, to;
        cin >> p >> from >> to;
        if(p == 1) {
            cout << (areInOneSet(from, to) ? 1 : 0);
        } else if(p == 2) {
            unionVertices(from, to);
        }
    }
    return 0;
}