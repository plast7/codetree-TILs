#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

// 좌표를 나타내는 구조체를 정의합니다.
struct Point {
    int x, y;
    // 좌표 비교를 위한 연산자를 정의합니다.
    bool operator<(const Point& other) const {
        return tie(x, y) < tie(other.x, other.y);
    }
};

// 방향에 따른 x, y 좌표 변화량을 정의합니다.
// 북쪽, 동쪽, 남쪽, 서쪽 순서입니다.
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

// 오른쪽으로 90도 회전하는 함수입니다.
int rightTurn(int direction) {
    return (direction + 1) % 4;
}

// 왼쪽으로 90도 회전하는 함수입니다.
int leftTurn(int direction) {
    return (direction + 3) % 4;
}

// 주어진 방향에서의 x 좌표 변화를 계산하는 함수입니다.
int rotateX(int direction, Point p) {
    if (direction == 0) return p.x;
    if (direction == 1) return p.y;
    if (direction == 2) return -p.x;
    if (direction == 3) return -p.y;
    return 0;
}

// 주어진 방향에서의 y 좌표 변화를 계산하는 함수입니다.
int rotateY(int direction, Point p) {
    if (direction == 0) return p.y;
    if (direction == 1) return -p.x;
    if (direction == 2) return -p.y;
    if (direction == 3) return p.x;
    return 0;
}

int main() {
    string commands;
    cin >> commands;
    int length = commands.length();

    // 각 명령어에 따른 좌표 변화를 저장할 벡터를 정의합니다.
    vector<Point> offset(length + 1);
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

    // 도착 지점의 좌표를 저장할 집합을 정의합니다.
    set<Point> uniquePoints;
    int x = 0, y = 0, direction = 0;

    // 각 명령어에 대해 가능한 모든 경우를 고려합니다.
    for (int i = 0; i < length; ++i) {
        if (commands[i] != 'F') {
            uniquePoints.insert({x + dx[direction] + rotateX(direction, offset[i + 1]), y + dy[direction] + rotateY(direction, offset[i + 1])});
        }
        if (commands[i] != 'L') {
            uniquePoints.insert({x + rotateX(leftTurn(direction), offset[i + 1]), y + rotateY(leftTurn(direction), offset[i + 1])});
        }
        if (commands[i] != 'R') {
            uniquePoints.insert({x + rotateX(rightTurn(direction), offset[i + 1]), y + rotateY(rightTurn(direction), offset[i + 1])});
        }
        if (commands[i] == 'F') {
            x += dx[direction];
            y += dy[direction];
        } else if (commands[i] == 'L') {
            direction = leftTurn(direction);
        } else if (commands[i] == 'R') {
            direction = rightTurn(direction);
        }
    }

    // 서로 다른 도착 지점의 수를 출력합니다.
    cout << uniquePoints.size() << endl;

    return 0;
}