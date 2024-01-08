#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

template <typename T>
class DisjointSet {
public:
    unordered_map<T, T> parent;
    unordered_map<T, int> size;

    DisjointSet(const vector<T>& nodes) {
        for (const T& node : nodes) {
            parent[node] = node;
            size[node] = 1;
        }
    }

    T Find(T node) {
        if (node == parent[node]) return node;
        return parent[node] = Find(parent[node]);
    }

    bool Union(T u, T v) {
        T uParent = Find(u);
        T vParent = Find(v);

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

template <typename T>
class Edge {
public:
    int from;
    int to;
    T weight;

    Edge(int from, int to, T weight) : from(from), to(to), weight(weight) {}

    bool operator<(const Edge& other) const {
        return this->weight < other.weight;
    }
};

// find minimal spanning tree
template <typename T>
vector<Edge<T>> kruskal(vector<Edge<T>>& edges, int nodesCount) {
    sort(edges.begin(), edges.end());

    vector<int> nodes;
    for (int i = 0; i < nodesCount; i++) {
        nodes.push_back(i);
    }

    DisjointSet<int> ds(nodes);
    vector<Edge<T>> tree;

    for (const Edge<T>& edge : edges) {
        int from = edge.from;
        int to = edge.to;

        // check if adding this edge creates a cycle
        if (ds.Find(from) != ds.Find(to)) {
            ds.Union(from, to);
            tree.push_back(edge);
        }
    }

    return tree;
}
