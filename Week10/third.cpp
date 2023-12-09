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

int main() {
    int N;
    cin >> N;
    unordered_map<char, set<char>> graph;
    vector<string> words;
    stack<char> result;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        words.push_back(s);
    }

    for (int i = 1; i < N; i++) {
        string first = words[i - 1];
        string second = words[i];
        int minLen = min(first.length(), second.length());
        for (int j = 0; j < minLen; j++) {
            if (first[j] != second[j]) {
                graph[first[j]].insert(second[j]);
                break;
            }
        }
    }

    topologicalSort(graph, result);

    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }

    return 0;
}