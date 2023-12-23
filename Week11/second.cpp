#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct Edge {
    int targetNode;
    int weight;
};

bool relax(const Edge& edge, int currentNode, vector<int>& distances) {
    int newDistance = distances[currentNode] + edge.weight;
    if (distances[edge.targetNode] > newDistance) {
        distances[edge.targetNode] = newDistance;
        return true;
    }
    return false;
}

void shortestPath(vector<vector<Edge>>& graph, int rows, int columns, vector<int>& distances, vector<int>& initialDistances, vector<bool>& visited) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
 
    for (int i = 0; i < columns; i++) {
        pq.push({ 0, i });
        distances[i] = initialDistances[i];
    }

    int gridArea = rows * columns;
    for (int i = columns; i < gridArea; i += columns) {
        pq.push({ 0, i });
        distances[i] = initialDistances[i];
    }
 
    for (int i = 2 * columns - 1; i < gridArea; i += columns) {
        pq.push({ 0, i });
        distances[i] = initialDistances[i];
    }
 
    for (int i = gridArea - columns + 1; i < gridArea - 1; i++) {
        pq.push({ 0, i });
        distances[i] = initialDistances[i];
    }
 
    while (!pq.empty()) {
        int currentNode = pq.top().second;
        pq.pop();
        if (visited[currentNode]) continue;
        visited[currentNode] = true;
        for (const Edge& edge : graph[currentNode]) {
            if (relax(edge, currentNode, distances)) {
                pq.push({ distances[edge.targetNode], edge.targetNode });
            }
        }
    }
}

int main() {
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<int>> grid(rows, vector<int>(columns));
    vector<int> distances(rows * columns, INT_MAX);
    vector<int> initialDistances(rows * columns, 0);
    vector<bool> visited(rows * columns, false);

    int cellIndex = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            char cell;
            cin >> cell;
            grid[i][j] = (cell == '.') ? 0 : 1;
            initialDistances[cellIndex] = grid[i][j];
            cellIndex++;
        }
    }

    vector<vector<Edge>> adjacencyList(rows * columns);
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i != 0)
                adjacencyList[index].push_back({ index - columns, grid[i - 1][j] });
            if (i != rows - 1)
                adjacencyList[index].push_back({ index + columns, grid[i + 1][j] });
            if (j != 0)
                adjacencyList[index].push_back({ index - 1, grid[i][j - 1] });
            if (j != columns - 1)
                adjacencyList[index].push_back({ index + 1, grid[i][j + 1] });
            index++;
        }
    }

    shortestPath(adjacencyList, rows, columns, distances, initialDistances, visited);

    int maxDistance = 0;
    for (int i = 0; i < distances.size(); i++) {
        if (initialDistances[i] == 0 && maxDistance < distances[i])
            maxDistance = distances[i];
    }

    int countMaxDistance = 0;
    for (int i = 0; i < rows * columns; i++) {
        if (maxDistance == distances[i] && initialDistances[i] == 0) {
            countMaxDistance++;
        }
    }

    cout << countMaxDistance << endl;

    return 0;
}
