#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// calculates the sum of elements in a subarray from given start to given end
int calculateSubarraySum(int startIndex, int endIndex, const vector<int>& prefixSums) {
    int endSum = prefixSums[endIndex];
    int startMinusOneSum = (startIndex == 0) ? 0 : prefixSums[startIndex - 1];
    return endSum - startMinusOneSum;
}

int countValidSolutions(vector<int>& prefixSumArray, int& keyIndex, int adjustmentValue) {
    int numElements = prefixSumArray.size();
    int solutionCount = 0;

    /*These maps will track indices of subarrays for which the sum of elements is a specific value,
    to the left(leftIndexMap) and to the right(rightIndexMap) of keyIndex*/
    unordered_map<int, vector<int>> leftIndexMap;
    unordered_map<int, vector<int>> rightIndexMap;

    // For each iteration on the left side, we calculate the sum of the subarray from leftIdx to keyIndex
    for (int leftIdx = 0; leftIdx <= keyIndex; leftIdx++)
        leftIndexMap[calculateSubarraySum(leftIdx, keyIndex, prefixSumArray) + adjustmentValue].push_back(leftIdx);

    // For each iteration on the right side, we calculate the sum of the subarray from keyIndex to rightIdx
    for (int rightIdx = keyIndex; rightIdx < numElements; rightIdx++)
        rightIndexMap[calculateSubarraySum(keyIndex, rightIdx, prefixSumArray)].push_back(rightIdx);

    for (auto& kvpair : leftIndexMap) { // auto& [sumValue, leftIndices]
        auto& sumValue = kvpair.first;
        auto& leftIndices = kvpair.second;

        /*We multiply the number of occurrences of this sum
        by the number of occurrences of the inverse sum on the right (multiplied by -1).
        This is because we want to find pairs of subarrays
        where the sum on the left cancels out the sum on the right,
        making keyIndex effectively the median*/
        solutionCount += leftIndices.size() * rightIndexMap[sumValue * -1].size();
    }
    return solutionCount;
}

int countSubarraysWithMedian(const vector<int>& inputArray, int keyValue) {
    int arraySize = inputArray.size();
    int keyValueIndex = 0;
    vector<int> transformedArray = vector<int>(arraySize, 0);

    /*Each element is replaced with - 1 if it is less than keyValue,
    with 1 if it is greater than keyValue, and 0 if it equals keyValue*/
    for (int i = 0; i < arraySize; i++) {
        if ((inputArray[i] - keyValue) != 0)
            transformedArray[i] = abs(inputArray[i] - keyValue) / (inputArray[i] - keyValue);
    }

    // calculate prefix sums
    for (int i = 1; i < arraySize; i++)
        transformedArray[i] = transformedArray[i - 1] + transformedArray[i];

    // find the index of key value
    for (int i = 0; i < arraySize; i++)
        if (inputArray[i] == keyValue)
            keyValueIndex = i;

    return countValidSolutions(transformedArray, keyValueIndex, 0);
}

vector<int> inputArr;
int N;
int K;
int curr;

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> curr;
        inputArr.push_back(curr);
    }

    cout << countSubarraysWithMedian(inputArr, K);
    return 0;
}
