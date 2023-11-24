#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int Q;
int N;
int C;
int K;
int X;
int Y;

struct Trip {
    int numPassengers;
    int start;
    int end;

    Trip(int num, int start, int end) :
        numPassengers(num), start(start), end(end) {}
};

bool comp(const Trip& lhs, const Trip& rhs) {
    return lhs.start == rhs.start ? lhs.end < rhs.end : lhs.start < rhs.start;
}

int main() {
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        cin >> N >> C;

        vector<Trip> trips;
        for (int j = 0; j < N; j++)
        {
            cin >> K >> X >> Y;
            trips.emplace_back(K, X, Y);
        }

        sort(trips.begin(), trips.end(), comp);

        int currPassCount = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> progressingTrips;
        bool isPos = true;

        for (const auto& trip : trips)
        {
            while (!progressingTrips.empty() && progressingTrips.top().first <= trip.start)
            {
                currPassCount -= progressingTrips.top().second;
                progressingTrips.pop();
            }

            progressingTrips.push({ trip.end, trip.numPassengers });
            currPassCount += trip.numPassengers;

            if (currPassCount > C)
            {
                isPos = false;
                break;
            }
        }

        cout << (isPos ? 1 : 0) << '\n';
    }

    return 0;
}
