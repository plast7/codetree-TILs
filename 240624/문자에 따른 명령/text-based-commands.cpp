#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

// 좌표를 나타내는 구조체
struct Point {
    int x, y;
    // 좌표를 비교하는 연산자 오버로딩
    bool operator<(const Point& other) const {
        return x == other.x ? y < other.y : x < other.x;
    }
};

// 방향에 따른 이동을 나타내는 배열
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

// 오른쪽으로 90도 회전
int right_turn(int dir) { return (dir + 1) % 4; }
// 왼쪽으로 90도 회전
int left_turn(int dir) { return (dir + 3) % 4; }

// 현재 방향에 따른 x 좌표 회전
int rotate_x(int dir, Point p) {
    if (dir == 0) return p.x;
    if (dir == 1) return p.y;
    if (dir == 2) return -p.x;
    if (dir == 3) return -p.y;
    return 0;
}

// 현재 방향에 따른 y 좌표 회전
int rotate_y(int dir, Point p) {
    if (dir == 0) return p.y;
    if (dir == 1) return -p.x;
    if (dir == 2) return -p.y;
    if (dir == 3) return p.x;
    return 0;
}

int main() {
    string commands;
    cin >> commands;
    int length = commands.size();

    // 각 명령에 따른 오프셋을 저장하는 벡터
    vector<Point> offset(length + 1);
    // 유일한 도착 지점을 저장하는 집합
    set<Point> unique_points;

    // 명령을 역순으로 처리하여 오프셋을 계산
    for (int i = length - 1; i >= 0; --i) {
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

    int x = 0, y = 0, dir = 0;

    // 명령을 순차적으로 처리하여 도착 지점을 계산
    for (int i = 0; i < length; ++i) {
        if (commands[i] != 'F') {
            unique_points.insert({x + dx[dir] + rotate_x(dir, offset[i + 1]), y + dy[dir] + rotate_y(dir, offset[i + 1])});
        }
        if (commands[i] != 'L') {
            unique_points.insert({x + rotate_x(left_turn(dir), offset[i + 1]), y + rotate_y(left_turn(dir), offset[i + 1])});
        }
        if (commands[i] != 'R') {
            unique_points.insert({x + rotate_x(right_turn(dir), offset[i + 1]), y + rotate_y(right_turn(dir), offset[i + 1])});
        }
        if (commands[i] == 'F') {
            x += dx[dir];
            y += dy[dir];
        } else if (commands[i] == 'L') {
            dir = left_turn(dir);
        } else if (commands[i] == 'R') {
            dir = right_turn(dir);
        }
    }

    // 유일한 도착 지점의 수를 출력
    cout << unique_points.size() << endl;

    return 0;
}