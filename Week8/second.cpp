#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Guest {
    long long arr;
    long long dep;
    int ind;
    int chair;

    Guest(long long arr, long long dep, int ind) :
        arr(arr), dep(dep), ind(ind) {
        chair = -1;
    }

    bool operator<(const Guest& other) const {
        return arr == other.arr ? dep > other.dep : arr > other.arr;
    }
};

struct CompByDep {
    bool operator()(const Guest& first, const Guest& second) {
        return first.dep > second.dep;
    }
};

int N;
long long arr;
long long dep;
int ind;
int T;

priority_queue<Guest> guests;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr >> dep;
        guests.emplace(arr, dep, i);
    }

    cin >> T;

    priority_queue<long long, vector<long long>, greater<long long>> freeChairs;
    for (int i = 0; i < N; i++) {
        freeChairs.push(i);
    }

    long long freeIndex = 0;
    priority_queue<Guest, vector<Guest>, CompByDep> leavingGuests;

    while (!guests.empty())
    {
        Guest curr = guests.top();

        guests.pop();

        while (!leavingGuests.empty() && leavingGuests.top().dep <= curr.arr) {
            freeChairs.push(leavingGuests.top().chair);
            leavingGuests.pop();
        }

        curr.chair = freeChairs.top();
        if (curr.ind == T) {
            freeIndex = curr.chair;
            break;
        }

        freeChairs.pop();
        leavingGuests.push(curr);
    }

    cout << freeIndex;

    return 0;
}
