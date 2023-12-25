#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <unordered_map>
using namespace std;

int nodeCount, edgeCount, timeLimit;

struct Edge;

struct Node {
    int index = 0;
    vector<Edge*> adjacentEdges;
    int timeSpent = 0;
};

struct Edge {
    int index = 0;
    int fromNode = 0;
    int toNode = 0;
    int weight = 0;
    int time = 0;
};

bool relax(Edge* edge, vector<int>& distanceTo, vector<int>& edgeToIndex) {
    int from = edge->fromNode, to = edge->toNode;
    int currentDistance = distanceTo[from] + edge->time;
    if (currentDistance < distanceTo[to]) {
        distanceTo[to] = currentDistance;
        edgeToIndex[to] = edge->index;
        return true;
    }
    return false;
}

bool shortestPath(int startNode, vector<Node>& nodes, vector<Edge>& edges, int maxTime, vector<int>& distanceTo, vector<int>& edgeToIndex, int maxWeight) {
    vector<bool> visitedBranch(edges.size(), false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priorityQueue;
    priorityQueue.push({ 0, startNode });

    while (!priorityQueue.empty()) {
        int currentNode = priorityQueue.top().second;
        priorityQueue.pop();

        if (currentNode != 0) {
            if (visitedBranch[edgeToIndex[currentNode]]) continue;
            visitedBranch[edgeToIndex[currentNode]] = true;
        }

        for (auto edge : nodes[currentNode].adjacentEdges) {
            if (visitedBranch[edge->index] || edge->weight > maxWeight) continue;
            if (relax(edge, distanceTo, edgeToIndex)) {
                priorityQueue.push({ distanceTo[edge->toNode], edge->toNode });
            }
        }
    }
    return distanceTo[nodes.size() - 1] <= maxTime;
}

int binarySearch(int timeLimit, vector<Node> nodes, vector<Edge> edges, int maxWeight, vector<int> distanceTo, vector<int> edgeToIndex) {
    int left = 0, right = maxWeight;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (shortestPath(0, nodes, edges, timeLimit, distanceTo, edgeToIndex, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        distanceTo = vector<int>(nodeCount, INT_MAX);
        distanceTo[0] = 0;
        edgeToIndex = vector<int>(nodeCount, 0);
    }
    return result;
}

int main() {
    cin >> nodeCount >> edgeCount >> timeLimit;

    vector<Node> nodes(nodeCount);
    vector<Edge> edges(edgeCount);
    int maximumWeight = 0;

    for (int i = 0; i < nodeCount; i++) {
        nodes[i].index = i;
    }

    for (int i = 0; i < edgeCount; i++) {
        int from, to, weight, time;
        cin >> from >> to >> weight >> time;
        from--;
        to--;

        edges[i] = {i, from, to, weight, time};
        maximumWeight = max(maximumWeight, weight);

        nodes[from].adjacentEdges.push_back(&edges[i]);
    }

    vector<int> distanceTo(nodeCount, INT_MAX);
    vector<int> edgeToIndex(nodeCount, 0);
    distanceTo[0] = 0;

    cout << binarySearch(timeLimit, nodes, edges, maximumWeight, distanceTo, edgeToIndex) << endl;
}
