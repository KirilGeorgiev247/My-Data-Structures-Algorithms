#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;

    cin >> N;

    stack<int> removedPlayers;
    vector<int> hungerValues(N);
    vector<int> removingPlayers(N);

    for (int i = 0; i < N; i++)
        cin >> hungerValues[i];

    for (int i = N - 1; i >= 0; i--)
    {
        while (!removedPlayers.empty() && hungerValues[i] < hungerValues[removedPlayers.top()]) 
        {
            removingPlayers[i] = max(removingPlayers[removedPlayers.top()], removingPlayers[i] + 1);
            removedPlayers.pop();
        }
        removedPlayers.push(i);
    }

    auto itToAns = max_element(removingPlayers.begin(), removingPlayers.end());

    cout << *itToAns;
}