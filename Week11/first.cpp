#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> busWaitTime(10000000, 0);
vector<bool> isVisited(10000000, false);
vector<int> shortestDist(10000000, INT_MAX);

struct BusRoute {
    int origin;
    int destination;
    int travelTime;
    BusRoute(int origin, int destination, int travelTime) 
        : origin(origin), destination(destination), travelTime(travelTime) {}
};

bool tryRelaxEdge(BusRoute route, int finalStop) {
    int currentStop = route.origin;
    int nextStop = route.destination;
    int travelTime = route.travelTime;
    int updatedTravelTime = shortestDist[currentStop] + travelTime;
    int waitTime = 0;

    if (finalStop != nextStop) {
        waitTime = updatedTravelTime % busWaitTime[nextStop];
        if (waitTime != 0) {
            waitTime = busWaitTime[nextStop] - waitTime;
        }
    }

    updatedTravelTime += waitTime;
    if (shortestDist[nextStop] > updatedTravelTime) {
        shortestDist[nextStop] = updatedTravelTime;
        return true;
    }
    return false;
}

void computeShortestPath(vector<vector<BusRoute>>& routesGraph, int startStop, int finalStop) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    shortestDist[startStop] = 0;
    minHeap.push({0, startStop});

    while (!minHeap.empty()) {
        int currentStop = minHeap.top().second;
        minHeap.pop();

        if (!isVisited[currentStop]) {
            isVisited[currentStop] = true;
            for (BusRoute& route : routesGraph[currentStop]) {
                if (tryRelaxEdge(route, finalStop)) {
                    minHeap.push({shortestDist[route.destination], route.destination});
                }
            }
        }
    }
}

int main() {
    int totalStops, totalRoutes, startingStop, finalStop;
    cin >> totalStops >> totalRoutes >> startingStop >> finalStop;
    vector<vector<BusRoute>> routesGraph(totalStops);

    for (int i = 0; i < totalStops; i++) {
        cin >> busWaitTime[i];
    }

    for (int i = 0; i < totalRoutes; i++) {
        int origin, destination, travelTime;
        cin >> origin >> destination >> travelTime;
        routesGraph[origin].push_back(BusRoute(origin, destination, travelTime));
    }

    computeShortestPath(routesGraph, startingStop, finalStop);

    if (shortestDist[finalStop] == INT_MAX) {
        cout << -1;
    } else {
        cout << shortestDist[finalStop];
    }

    return 0;
}
