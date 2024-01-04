#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class DisjointSet {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;

    DisjointSet(const vector<int>& nodes) {
        for (const int& node : nodes) {
            parent[node] = node;
            size[node] = 1;
        }
    }

    int Find(int node) {
        if (node == parent[node]) return node;
        return parent[node] = Find(parent[node]);
    }

    bool Union(int u, int v) {
        int uParent = Find(u);
        int vParent = Find(v);

        if (uParent == vParent) return false;

        if (size[uParent] < size[vParent]) {
            parent[uParent] = vParent;
            size[vParent]++;
        }
        else {
            parent[vParent] = uParent;
            size[uParent]++;
        }
        return true;
    }
};

class Edge {
public:
    int ind;
    int from;
    int to;
    unsigned long long effort;
    long long winnings;

    Edge(int ind, int from, int to, unsigned long long effort, long long winnings) 
        : ind(ind), from(from), to(to), effort(effort), winnings(winnings) {}

    bool operator<(const Edge& other) const {
        return this->effort != other.effort ?
            this->effort < other.effort : this->winnings > other.winnings;
    }
};

void kruskal(vector<Edge>& edges, int nodesCount) {
    sort(edges.begin(), edges.end());

    vector<int> nodes;
    for (int i = 0; i < nodesCount; i++) {
        nodes.push_back(i);
    }

    DisjointSet ds(nodes);
    vector<Edge> tree;

    for (Edge& edge : edges) {
        int from = edge.from;
        int to = edge.to;

        if (ds.Find(from) != ds.Find(to)) {
            ds.Union(from, to);
            tree.push_back(edge);
        }
    }

    for(const Edge& edge: tree) {
        cout << edge.ind << '\n';
    }
}

int main() {
    int N, M;
    
    cin >> N >> M;
    int u, v;
    unsigned long long e;
    long long w;
    vector<Edge> edges;
    
    for(int i = 0; i < M; i++) {
        cin >> u >> v >> e >> w;
        edges.emplace_back(i + 1, u, v, e, w);
    }
    
    kruskal(edges, N);
    
    return 0;
}