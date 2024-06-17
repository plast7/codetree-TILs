#include <iostream>
#include <cstring>
#include <set>

using namespace std;

#define MAX_N 100000

struct Point {
    int x, y;
    bool operator<(const Point& other) const {
        if (x == other.x)
            return y < other.y;
        return x < other.x;
    }
};

char commands[MAX_N + 1];
Point possible_destinations[MAX_N * 2];
Point offset[MAX_N + 1];

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

int turn_right(int dir) { return (dir + 1) % 4; }
int turn_left(int dir) { return (dir + 3) % 4; }

int rotate_x(int dir, Point p) {
    if (dir == 0) return p.x;
    if (dir == 1) return p.y;
    if (dir == 2) return -p.x;
    if (dir == 3) return -p.y;
    return 0; // Should never reach here
}

int rotate_y(int dir, Point p) {
    if (dir == 0) return p.y;
    if (dir == 1) return -p.x;
    if (dir == 2) return -p.y;
    if (dir == 3) return p.x;
    return 0; // Should never reach here
}

int main() {
    cin >> commands;
    int L = strlen(commands);

    // Compute action of every "suffix" of commands
    for (int i = L - 1; i >= 0; i--) {
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

    // Build a list of all possible destination points
    int x = 0, y = 0, dir = 0, n = 0;
    set<Point> unique_points;
    for (int i = 0; i < L; i++) {
        if (commands[i] != 'F') { 
            Point p = { x + dx[dir] + rotate_x(dir, offset[i + 1]), y + dy[dir] + rotate_y(dir, offset[i + 1]) };
            unique_points.insert(p);
        }
        if (commands[i] != 'L') { 
            Point p = { x + rotate_x(turn_left(dir), offset[i + 1]), y + rotate_y(turn_left(dir), offset[i + 1]) };
            unique_points.insert(p);
        }
        if (commands[i] != 'R') { 
            Point p = { x + rotate_x(turn_right(dir), offset[i + 1]), y + rotate_y(turn_right(dir), offset[i + 1]) };
            unique_points.insert(p);
        }   
        if (commands[i] == 'F') {
            x += dx[dir];
            y += dy[dir];
        } else if (commands[i] == 'L') {
            dir = turn_left(dir);
        } else if (commands[i] == 'R') {
            dir = turn_right(dir);
        }
    }

    // Output the number of unique points
    cout << unique_points.size() << endl;
    
    return 0;
}