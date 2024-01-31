#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <stack>
using namespace std;

const int MAX_SIZE = 1e6;

bool visited[MAX_SIZE];

void dfs(const char& value, unordered_map<char, set<char>>& graph, stack<char>& result) {
    visited[value] = true;

    if (graph.count(value)) {
        for (const auto& element : graph[value]) {
            if (!visited[element]) {
                dfs(element, graph, result);
            }
        }
    }
    result.push(value);
}

void topologicalSort(unordered_map<char, set<char>>& graph, stack<char>& result) {
    for (const auto& element : graph) {
        if (!visited[element.first]) {
            dfs(element.first, graph, result);
        }
    }
}