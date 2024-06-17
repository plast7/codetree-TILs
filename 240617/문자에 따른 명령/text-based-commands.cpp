#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Point {
    int x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

namespace std {
    template <>
    struct hash<Point> {
        size_t operator()(const Point& p) const {
            return hash<int>()(p.x) ^ hash<int>()(p.y);
        }
    };
}

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int rightTurn(int dir) {
    return (dir + 1) % 4;
}

int leftTurn(int dir) {
    return (dir + 3) % 4;
}

int rotateX(int dir, const Point& p) {
    if (dir == 0) return p.x;
    if (dir == 1) return p.y;
    if (dir == 2) return -p.x;
    if (dir == 3) return -p.y;
    return 0;
}

int rotateY(int dir, const Point& p) {
    if (dir == 0) return p.y;
    if (dir == 1) return -p.x;
    if (dir == 2) return -p.y;
    if (dir == 3) return p.x;
    return 0;
}

int main() {
    string commands;
    cin >> commands;

    int n = commands.length();
    vector<Point> offset(n + 1);
    unordered_set<Point> unique_points;

    int x = 0, y = 0, dir = 0;
    offset[n] = {0, 0};

    for (int i = n - 1; i >= 0; --i) {
        if (commands[i] == 'F') {
            offset[i].x = offset[i + 1].x;
            offset[i].y = 1 + offset[i + 1].y;
        } else if (commands[i] == 'L') {
            offset[i].x = -offset[i + 1].y;
            offset[i].y = offset[i + 1].x;
        } else if (commands[i] == 'R') {
            offset[i].x = offset[i + 1].y;
            offset[i].y = -offset[i + 1].x;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (commands[i] != 'F') {
            unique_points.insert({x + dx[dir] + rotateX(dir, offset[i + 1]), y + dy[dir] + rotateY(dir, offset[i + 1])});
        }
        if (commands[i] != 'L') {
            unique_points.insert({x + rotateX(leftTurn(dir), offset[i + 1]), y + rotateY(leftTurn(dir), offset[i + 1])});
        }
        if (commands[i] != 'R') {
            unique_points.insert({x + rotateX(rightTurn(dir), offset[i + 1]), y + rotateY(rightTurn(dir), offset[i + 1])});
        }
        if (commands[i] == 'F') {
            x += dx[dir];
            y += dy[dir];
        } else if (commands[i] == 'L') {
            dir = leftTurn(dir);
        } else if (commands[i] == 'R') {
            dir = rightTurn(dir);
        }
    }

    cout << unique_points.size() << endl;

    return 0;
}