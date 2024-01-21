#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_NUMBERS = 100000 + 10;
const int MAX_VALUE = 200000 + 10;

int sequence[MAX_NUMBERS], sequenceLength, numQueries;
vector<int> multiples[MAX_VALUE], indices[MAX_VALUE];
bool isPresentInSequence[MAX_VALUE];

int findIndicesInRange(int divisor, int upperBound) {
    int left = -1, right = indices[divisor].size(), mid;
    while (left < right - 1) {
        mid = (left + right) / 2;
        if (indices[divisor][mid] <= upperBound)
            left = mid;
        else
            right = mid;
    }
    return right;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> sequenceLength >> numQueries;
    for (int i = 1; i <= sequenceLength; ++i) {
        cin >> sequence[i];
        isPresentInSequence[sequence[i]] = true;
    }

    for (int i = 1; i < MAX_VALUE; ++i) {
        for (int multiple = 2 * i; multiple < MAX_VALUE; multiple += i) {
            if (isPresentInSequence[multiple]) multiples[multiple].push_back(i);
        }
    }

    for (int i = 1; i <= sequenceLength; ++i) {
        for (int multiple = sequence[i]; multiple < MAX_VALUE; multiple += sequence[i])
            indices[multiple].push_back(i);

        for (int divisor : multiples[sequence[i]])
            indices[divisor].push_back(i);
    }

    int start, end, divisor;
    for (int i = 1; i <= numQueries; ++i) {
        cin >> start >> end >> divisor;
        cout << findIndicesInRange(divisor, end) - findIndicesInRange(divisor, start - 1) << ' ';
    }

    return 0;
}
