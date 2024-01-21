#include <iostream>
#include <vector>

using namespace std;

struct Position {
    int x, y;
};

vector<string> matrix;
vector<Position> markedPositions;

int matrixRows, matrixColumns;
int totalParallelograms = 0;

bool checkParallelogram(const Position& first, const Position& second, const Position& third) {
    int fourthX = third.x + (first.x - second.x);
    int fourthY = third.y + (first.y - second.y);

    if (fourthX >= 0 && fourthX < matrixColumns && fourthY >= 0 && fourthY < matrixRows) {
        return matrix[fourthY][fourthX] == 'x' && 
               ((first.x - second.x) * (third.y - second.y) - 
                (third.x - second.x) * (first.y - second.y)) != 0;
    }

    return false;
}

void calculateParallelograms() {
    int numMarkedPositions = markedPositions.size();

    for (int i = 0; i < numMarkedPositions - 2; i++) {
        for (int j = i + 1; j < numMarkedPositions - 1; j++) {
            for (int k = j + 1; k < numMarkedPositions; k++) {
                if (checkParallelogram(markedPositions[i], markedPositions[j], markedPositions[k])) {
                    totalParallelograms++;
                }
            }
        }
    }
}

int main() {
    cin >> matrixRows >> matrixColumns;
    matrix.resize(matrixRows);

    for (int i = 0; i < matrixRows; i++) {
        cin >> matrix[i];
    }
    
    for (int row = 0; row < matrixRows; row++) {
        for (int col = 0; col < matrixColumns; col++) {
            if (matrix[row][col] == 'x') {
                markedPositions.push_back({col, row});
            }
        }
    }
    
    calculateParallelograms();

    cout << totalParallelograms / 2 << endl;

    return 0;
}
