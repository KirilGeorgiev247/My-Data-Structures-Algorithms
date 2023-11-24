#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Point {
    int x, y;
    long long dist;

    Point(int x, int y, int xT, int yT) : x(x), y(y) {
        dist = (long long)(xT - x) * (xT - x) + (long long)(yT - y) * (yT - y);
    }

    bool operator>(const Point& other) const {
        if (dist == other.dist) {
            if (x == other.x) return y > other.y;
            return x > other.x;
        }
        return dist > other.dist;
    }
};

int main() {
    int X, Y, N, K;
    cin >> X >> Y >> N >> K;

    priority_queue<Point, vector<Point>, greater<Point>> points;

    for (int i = 0; i < N; i++) {
        int sX, sY;
        cin >> sX >> sY;
        points.emplace(sX, sY, X, Y);
    }

    for (int i = 0; i < K; i++) {
        cout << points.top().x << " " << points.top().y << '\n';
        points.pop();
    }

    return 0;
}
