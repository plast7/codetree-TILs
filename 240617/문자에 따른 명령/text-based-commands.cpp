#include <iostream>
#include <cstring>
#include <unordered_set>
#include <utility>

using namespace std;

#define MAX_N 100000

typedef pair<int, int> Point;

char commands[MAX_N + 1];
Point offsets[MAX_N + 1];

/* Direction vectors for N, E, S, W */
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int turnRight(int dir) { return (dir + 1) % 4; }
int turnLeft(int dir) { return (dir + 3) % 4; }

int rotateX(int dir, Point p) {
    if (dir == 0) return p.first;
    if (dir == 1) return p.second;
    if (dir == 2) return -p.first;
    return -p.second;
}

int rotateY(int dir, Point p) {
    if (dir == 0) return p.second;
    if (dir == 1) return -p.first;
    if (dir == 2) return -p.second;
    return p.first;
}

int main() {
    cin >> commands;
    int len = strlen(commands);

    unordered_set<Point> uniquePoints;

    /* Compute action of every "suffix" of commands */
    offsets[len] = {0, 0};
    for (int i = len - 1; i >= 0; --i) {
        if (commands[i] == 'F') {
            offsets[i].first = offsets[i + 1].first;
            offsets[i].second = 1 + offsets[i + 1].second;
        } else if (commands[i] == 'L') {
            offsets[i].first = -offsets[i + 1].second;
            offsets[i].second = offsets[i + 1].first;
        } else if (commands[i] == 'R') {
            offsets[i].first = offsets[i + 1].second;
            offsets[i].second = -offsets[i + 1].first;
        }
    }

    /* Build a list of all possible destination points */
    int x = 0, y = 0, dir = 0;
    for (int i = 0; i < len; ++i) {
        if (commands[i] != 'F') {
            uniquePoints.insert({x + dx[dir] + rotateX(dir, offsets[i + 1]), y + dy[dir] + rotateY(dir, offsets[i + 1])});
        }
        if (commands[i] != 'L') {
            uniquePoints.insert({x + rotateX(turnLeft(dir), offsets[i + 1]), y + rotateY(turnLeft(dir), offsets[i + 1])});
        }
        if (commands[i] != 'R') {
            uniquePoints.insert({x + rotateX(turnRight(dir), offsets[i + 1]), y + rotateY(turnRight(dir), offsets[i + 1])});
        }
        if (commands[i] == 'F') {
            x += dx[dir];
            y += dy[dir];
        } else if (commands[i] == 'L') {
            dir = turnLeft(dir);
        } else if (commands[i] == 'R') {
            dir = turnRight(dir);
        }
    }

    cout << uniquePoints.size() << endl;

    return 0;
}