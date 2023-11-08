#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<int> result;
int resTop;
long long maxArea = 0;
long long currArea = 0;
int i = 0;

int main()
{
    int N;
    cin >> N;

    vector<int> arr(N);

    for (int j = 0; j < N; j++)
        cin >> arr[j];

    while (i < N) {
        if (result.empty() || arr[result.top()] <= arr[i])
            result.push(i++);
        else {
            resTop = arr[result.top()];
            result.pop();
            currArea = resTop * i;

            if (!result.empty())
                currArea = resTop * (i - result.top() - 1);
            maxArea = max(currArea, maxArea);
        }
    }

    while (!result.empty()) {
        resTop = arr[result.top()];
        result.pop();
        currArea = resTop * i;
        if (!result.empty())
            currArea = resTop * (i - result.top() - 1);

        maxArea = max(currArea, maxArea);
    }

    cout << maxArea;

    return 0;
}