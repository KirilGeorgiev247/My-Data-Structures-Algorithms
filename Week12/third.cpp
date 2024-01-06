#include <bits/stdc++.h>

using namespace std;

struct Road {
    size_t cityA, cityB, speedLimit;

    bool operator<(const Road& other) const {
        return speedLimit < other.speedLimit;
    }
};

class CityNetwork {
private:
    vector<size_t> leader;
    vector<size_t> groupSize;

public:
    CityNetwork(size_t numberOfCities) : leader(numberOfCities), groupSize(numberOfCities, 1) {
        for (size_t i = 0; i < numberOfCities; ++i) {
            leader[i] = i;
        }
    }

    size_t findLeader(size_t city) {
        if (leader[city] != city) {
            leader[city] = findLeader(leader[city]);
        }
        return leader[city];
    }

    bool linkCities(size_t cityA, size_t cityB) {
        size_t leaderA = findLeader(cityA);
        size_t leaderB = findLeader(cityB);

        if (leaderA != leaderB) {
            if (groupSize[leaderA] < groupSize[leaderB]) {
                swap(leaderA, leaderB);
            }
            leader[leaderB] = leaderA;
            groupSize[leaderA] += groupSize[leaderB];
        }

        return groupSize[leaderA] == leader.size();
    }
};

struct SpeedRange {
    size_t minSpeed, maxSpeed;
};

SpeedRange findSpeedLimits(const vector<Road>& roads, size_t numberOfCities, size_t startIndex) {
    size_t lowerBoundSpeed = roads[startIndex].speedLimit;
    size_t upperBoundSpeed = LLONG_MAX;
    
    CityNetwork network(numberOfCities);
    while (startIndex < roads.size() && roads[startIndex].speedLimit <= upperBoundSpeed) {
        const auto& currentRoad = roads[startIndex];
        if (network.findLeader(currentRoad.cityA) != network.findLeader(currentRoad.cityB)) {
            if (network.linkCities(currentRoad.cityA, currentRoad.cityB)) {
                upperBoundSpeed = currentRoad.speedLimit;
            }
        }
        ++startIndex;
    }

    return { lowerBoundSpeed, upperBoundSpeed };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t numberOfCities, numberOfRoads;
    cin >> numberOfCities >> numberOfRoads;

    vector<Road> roads(numberOfRoads);
    for (auto& road : roads) {
        cin >> road.cityA >> road.cityB >> road.speedLimit;
        --road.cityA;
        --road.cityB;
    }

    sort(roads.begin(), roads.end());

    SpeedRange optimalSpeedRange{ LLONG_MAX, 0 };
    size_t currentRoadIndex = 0;

    while (currentRoadIndex < roads.size()) {
        SpeedRange speedRange = findSpeedLimits(roads, numberOfCities, currentRoadIndex);
        size_t speedDifference = speedRange.maxSpeed - speedRange.minSpeed;
        size_t optimalSpeedDifference = optimalSpeedRange.maxSpeed - optimalSpeedRange.minSpeed;
        
        if (speedDifference < optimalSpeedDifference) {
            optimalSpeedRange = speedRange;
        }

        while (currentRoadIndex < roads.size() - 1 && roads[currentRoadIndex].speedLimit == roads[currentRoadIndex + 1].speedLimit) {
            ++currentRoadIndex;
        }
        ++currentRoadIndex;
    }

    cout << optimalSpeedRange.minSpeed << " " << optimalSpeedRange.maxSpeed << '\n';

    return 0;
}