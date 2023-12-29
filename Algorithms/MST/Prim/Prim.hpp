#pragma once

#include <vector>
#include <limits>
#include <queue>
#include <utility>

using namespace std;

template <typename T>
class Edge {
public:
    int from;
    int to;
    T weight;

    Edge(int from, int to, T weight) : from(from), to(to), weight(weight) {}
};

template <typename T>
class Graph {
public:
    vector<vector<Edge<T>>> adjacencyList;

    Graph(int nodesCount) {
        adjacencyList.resize(nodesCount);
    }

    void addEdge(int src, int dest, T weight) {
        adjacencyList[src].push_back(Edge<T>(src, dest, weight));
        adjacencyList[dest].push_back(Edge<T>(dest, src, weight)); // for undirected graph
    }
};

// find minimal spanning tree
template <typename T>
vector<Edge<T>> prim(const Graph<T>& graph) {
    int nodesCount = graph.adjacencyList.size();
    vector<bool> includedInMST(nodesCount, false);
    vector<Edge<T>> minEdgeToNode(nodesCount, Edge<T>(-1, -1, numeric_limits<T>::max()));
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> minEdgePQ;

    minEdgeToNode[0].weight = 0;
    minEdgePQ.push({ 0, 0 });

    while (!minEdgePQ.empty()) {
        int currentNode = minEdgePQ.top().second;
        minEdgePQ.pop();

        if (includedInMST[currentNode]) continue;
        includedInMST[currentNode] = true;

        for (const Edge<T>& edge : graph.adjacencyList[currentNode]) {
            int currTo = edge.to;
            T currWeigth = edge.weight;

            if (!includedInMST[currTo] &&
                currWeigth < minEdgeToNode[currTo].weight) {
                minEdgeToNode[currTo] = edge;
                minEdgePQ.push({ currWeigth, currTo });
            }
        }
    }

    vector<Edge<T>> tree;
    for (int i = 1; i < nodesCount; ++i) {
        if (minEdgeToNode[i].from != -1) {
            tree.push_back(minEdgeToNode[i]);
        }
    }

    return tree;
}
