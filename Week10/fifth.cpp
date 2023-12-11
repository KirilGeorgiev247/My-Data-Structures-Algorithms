#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

unordered_map<int, set<int>> graph;
int N;
int M;
int startCity;
int endCity;
int U;
int V;
 
int bfs(int startCity, int endCity) {
    int minPath = 0;
    queue<int> level;
    level.push(startCity);
 
    while (!level.empty()) {
 
        int size = level.size();
        while (size != 0) {
            int curr = level.front();
            if (curr == endCity) {
                return minPath;
            }
            level.pop();
            for (int it : graph.at(curr)) {
                level.push(it);
            }
            size--;
        }
        minPath++;
 
    }
    return -1;
}
 
 
int main() {
    cin >> N;
    cin >> M;
    int counter = -1;
    
    for (int i = 0; i < M; i++) {
        cin >> U;
        cin >> V;
        int weight;
        cin >> weight;
        if (weight == 2) {
 
            int temp = counter--;
 
            graph[U].insert(temp);
            graph[temp].insert(U);
            graph[temp].insert(V);
            graph[V].insert(temp);
 
        }
        else {
            graph[U].insert(V);
            graph[V].insert(U);
        }
    }
 
    cin >> startCity;
    cin >> endCity;
    cout << bfs(startCity, endCity);
 
    return 0;
}