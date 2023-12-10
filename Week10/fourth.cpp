#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int bfs(vector<bool>& visited, unordered_map<unsigned long long, set<unsigned long long>>& graph, unsigned long long start) {
    unsigned long long count = 0;
    set<unsigned long long> queue;
    queue.insert(start);
    while (!queue.empty()) {
        unsigned long long current = *queue.begin();
        queue.erase(queue.begin());
        if (!visited[current]) {
            visited[current] = true;
            count++;
            for (unsigned long long neighbor : graph[current]) {
                queue.insert(neighbor);
            }
        }
    }
    return count;
}

int main() {
    unsigned long long plansCount;
    cin >> plansCount;

    while (plansCount--) {
        unsigned long long citiesCount, possiblePathsCount, priceForDisco, priceForPath;
        cin >> citiesCount >> possiblePathsCount >> priceForDisco >> priceForPath;
        vector<bool> visited(citiesCount + 1, false);
        unordered_map<unsigned long long, set<unsigned long long>> graph;

        for (int i = 0; i < possiblePathsCount; ++i) {
            unsigned long long firstCity, secondCity;
            cin >> firstCity >> secondCity;
            graph[firstCity].insert(secondCity);
            graph[secondCity].insert(firstCity);
        }

        unsigned long long result = 0;
        if (priceForDisco <= priceForPath) {
            result = priceForDisco * citiesCount;
        }
        else {
            for (unsigned long long city = 1; city <= citiesCount; ++city) {
                if (!visited[city]) {
                    unsigned long long componentSize = bfs(visited, graph, city);
                    result += priceForDisco + (componentSize - 1) * priceForPath;
                }
            }
        }
        cout << result << endl;
    }

    return 0;
}
