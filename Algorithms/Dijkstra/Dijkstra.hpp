#pragma once

#include <unordered_map>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

template<typename T>
struct Node {
    T to;
    T weight;

    bool operator>(const Node &other) const {
        return this->weight > other.weight;
    }
};

template<typename T>
void findShortestPath(const unordered_map<T, vector<Node<T>>> &graph, const T &startNode, unordered_map<T, T> &distances) {
    for (const auto &pair : graph) {
        distances[pair.first] = numeric_limits<T>::max();
    }
    distances[startNode] = T();

    priority_queue<Node<T>, vector<Node<T>>, greater<Node<T>>> pq;
    pq.push({startNode, T()});

    while (!pq.empty()) {
        T currNode = pq.top().to;
        T currDist = pq.top().weight;
        pq.pop();

        if (currDist > distances[currNode]) {
            continue;
        }

        for (const auto &neighbour : graph.at(currNode)) {
            T nextNode = neighbour.to;
            T distanceToNextStop = neighbour.weight;
            T newDistance = distances[currNode] + distanceToNextStop;

            if (distances[nextNode] > newDistance) {
                distances[nextNode] = newDistance;
                pq.push({nextNode, newDistance});
            }
        }
    }
}
