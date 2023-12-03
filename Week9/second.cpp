#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int STATIC_ARR_SIZE = 100000;
long long powerArrayOne[STATIC_ARR_SIZE];
long long powerArrayTwo[STATIC_ARR_SIZE];

const int MODULO_ONE = 1e9 + 9;
const int MODULO_TWO = 1e9 + 7;
const int BASE_ONE = 809;
const int BASE_TWO = 17;

void precomputePowers() {
    long long basePower = 1;
    for (int i = 0; i < STATIC_ARR_SIZE; ++i) {
        powerArrayOne[i] = basePower;
        basePower = (basePower * BASE_ONE) % MODULO_ONE;
    }

    basePower = 1;
    for (int i = 0; i < STATIC_ARR_SIZE; ++i) {
        powerArrayTwo[i] = basePower;
        basePower = (basePower * BASE_TWO) % MODULO_TWO;
    }
}

long long computeRollingHash(long long previousHash, long long len, char removedChar, char addedChar, long long powerSeries[], int modulo, int base) {
    previousHash = (previousHash - (removedChar - 'a' + 1) * powerSeries[len - 1]) % modulo;
    previousHash = (previousHash + modulo) % modulo;

    return (previousHash * base + (addedChar - 'a' + 1)) % modulo;
}

long long createHash(const string& text, long long textLength, long long powerSeries[], int modulo) {
    long long hashValue = 0;

    for (long long i = 0; i < textLength; ++i) {
        hashValue = (hashValue + (text[i] - 'a' + 1) * powerSeries[textLength - 1 - i]) % modulo;
    }

    return hashValue;
}

bool checkSubsequence(const string& first, const string& second, size_t seqLength) {
    unordered_set<long long> hashSetOne, hashSetTwo;

    long long hashOne = createHash(first, seqLength, powerArrayOne, MODULO_ONE);
    long long hashTwo = createHash(first, seqLength, powerArrayTwo, MODULO_TWO);
    hashSetOne.insert(hashOne);
    hashSetTwo.insert(hashTwo);

    for (long long i = 0; i < first.length() - seqLength; ++i) {
        hashOne = computeRollingHash(hashOne, seqLength, first[i], first[i + seqLength], powerArrayOne, MODULO_ONE, BASE_ONE);
        hashSetOne.insert(hashOne);

        hashTwo = computeRollingHash(hashTwo, seqLength, first[i], first[i + seqLength], powerArrayTwo, MODULO_TWO, BASE_TWO);
        hashSetTwo.insert(hashTwo);
    }

    long long hashForSecondOne = createHash(second, seqLength, powerArrayOne, MODULO_ONE);
    long long hashForSecondTwo = createHash(second, seqLength, powerArrayTwo, MODULO_TWO);

    if (hashSetOne.find(hashForSecondOne) != hashSetOne.end() && hashSetTwo.find(hashForSecondTwo) != hashSetTwo.end()) {
        return true;
    }

    for (long long i = 0; i < second.length() - seqLength; ++i) {
        hashForSecondOne = computeRollingHash(hashForSecondOne, seqLength, second[i], second[i + seqLength], powerArrayOne, MODULO_ONE, BASE_ONE);
        hashForSecondTwo = computeRollingHash(hashForSecondTwo, seqLength, second[i], second[i + seqLength], powerArrayTwo, MODULO_TWO, BASE_TWO);

        if (hashSetOne.find(hashForSecondOne) != hashSetOne.end() && hashSetTwo.find(hashForSecondTwo) != hashSetTwo.end()) {
            return true;
        }
    }

    return false;
}

int main() {
    precomputePowers();
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.length() < s2.length()) {
        swap(s1, s2);
    }

    long long low = 0, high = s2.length(), maxLength = 0;
    while (low <= high) {
        long long midPoint = low + (high - low) / 2;

        if (checkSubsequence(s1, s2, midPoint)) {
            maxLength = midPoint;
            low = midPoint + 1;
        }
        else {
            high = midPoint - 1;
        }
    }

    cout << maxLength;

    return 0;
}