#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int N, curr;
    cin >> N;
    unordered_map<int, int> nums;
    int minCount = 10e5 + 2;
    for(int i = 0; i < N; i++) {
        cin >> curr;
        if(nums.find(curr) == nums.end()) {
            nums[curr] = i;
        }
        else {
            int diff = i - nums[curr];
            minCount = min(diff, minCount);
            nums[curr] = i;
        }
    }
    
    cout << minCount;
    return 0;
}
