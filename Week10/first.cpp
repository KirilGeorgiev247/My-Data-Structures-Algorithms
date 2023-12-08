#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <algorithm>
using namespace std;

int N;

//0 1 1 0 0 0
//1 1 1 0 0 0
//0 0 1 0 0 0
//0 0 1 0 0 0
//0 0 0 0 1 1
//0 0 0 0 1 0

void dfs(int i, int j, int& up, int& down, int& left, int& right,
    const vector<vector<int>>& matrix, vector<vector<bool>>& visited) {

    if (i < 0 || i >= N || j < 0 || j >= N || visited[i][j] || !matrix[i][j])
        return;

    up = min(up, i);
    down = max(down, i);
    left = min(left, j);
    right = max(right, j);

    visited[i][j] = true;

    dfs(i + 1, j, up, down, left, right, matrix, visited);
    dfs(i - 1, j, up, down, left, right, matrix, visited);
    dfs(i, j + 1, up, down, left, right, matrix, visited);
    dfs(i, j - 1, up, down, left, right, matrix, visited);
}

int main() {
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<int> areas;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix[i][j] && !visited[i][j])
            {
                int up, down, left, right;

                up = down = i;
                left = right = j;

                dfs(i, j, up, down, left, right, matrix, visited);

                int area = (right - left + 1) * (down - up + 1);

                areas.push_back(area);
            }
        }
    }

    sort(areas.rbegin(), areas.rend());

    for (int i = 0; i < areas.size(); i++)
    {
        cout << areas[i] << " ";
    }

    return 0;
}
