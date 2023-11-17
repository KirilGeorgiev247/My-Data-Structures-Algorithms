#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to find the correct position to insert a number
// into the permutation to keep it lexicographically smallest.
int findPosition(const vector<int>& perm, int num) {
    for (int i = 0; i < perm.size(); ++i) {
        if (num < perm[i]) {
            return i;
        }
    }
    return perm.size();
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> permutation(M);
    unordered_set<int> usedNumbers;

    for (int i = 0; i < M; ++i) {
        cin >> permutation[i];
        usedNumbers.insert(permutation[i]);
    }

    for (int num = 1; num <= N; ++num) {
        if (usedNumbers.find(num) == usedNumbers.end()) {
            // Find the position where the missing number should be inserted
            int position = findPosition(permutation, num);
            permutation.insert(permutation.begin() + position, num);
        }
    }

    for (int num : permutation) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
