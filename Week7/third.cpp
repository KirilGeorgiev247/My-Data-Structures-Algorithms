#include <iostream>
#include <set>
#include <limits>

using namespace std;

set<int> s;
int Q;
int minXOR = numeric_limits<int>::max();
int curr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;

    s.insert(0);

    while (Q--) {
        cin >> curr;
        
        auto result = s.insert(curr);

        if (result.second) {
            auto iter = result.first;

            if (iter != s.begin()) {
                minXOR = min(minXOR, curr ^ *prev(iter));
            }
            if (next(iter) != s.end()) {
                minXOR = min(minXOR, curr ^ *next(iter));
            }
        }

        cout << minXOR << '\n';
    }

    return 0;
}
