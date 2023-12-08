#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX_VALUE = 1e6 + 2;

int N, M, U, V, G, S, R;

void bfs(const vector<vector<int>>& friends, vector<int>& distances, int start) {
    fill(distances.begin(), distances.end(), MAX_VALUE);
    queue<int> level;
    level.push(start);
    distances[start] = 0;

    while (!level.empty())
    {
        int curr = level.front();
        level.pop();

        for (auto& neighbor : friends[curr])
        {
            if (distances[neighbor] == MAX_VALUE)
            {
                distances[neighbor] = distances[curr] + 1;
                level.push(neighbor);
            }
        }
    }
}

int main() {
    cin >> N >> M;

    vector<vector<int>> friends(N + 1);
    vector<int> groups(N + 1);
    vector<int> distances(N + 1, MAX_VALUE);

    for (int i = 0; i < M; i++)
    {
        cin >> U >> V;
        friends[U].push_back(V);
        friends[V].push_back(U);
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> groups[i];
    }

    cin >> G;

    R = MAX_VALUE;

    for (int i = 1; i <= N; ++i) {
        if (groups[i] == G) {
            bfs(friends, distances, i);

            for (int j = 1; j <= N; ++j) {
                if (i != j && groups[j] == G && distances[j] < MAX_VALUE) {
                    R = min(R, distances[j]);
                }
            }
        }
    }

    cout << R;

    return 0;
}
