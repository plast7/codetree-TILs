#include <iostream>
#include <string>
#include <set>
#include <utility>
#include <cstring>

using namespace std;

#define MAX_N 100000

// Point 구조체를 정의하여 좌표를 나타냅니다.
struct Point {
    int x, y;
    // 좌표 비교 연산자를 정의하여 set에서 중복을 제거합니다.
    bool operator<(const Point &other) const {
        return x == other.x ? y < other.y : x < other.x;
    }
};

// 명령어를 저장할 배열과 이동 오프셋을 저장할 배열을 정의합니다.
char commands[MAX_N + 1];
Point movementOffsets[MAX_N + 1];

// 방향에 따른 이동 오프셋을 정의합니다. (북, 동, 남, 서)
int Dx[4] = { 0, 1, 0, -1 };
int Dy[4] = { 1, 0, -1, 0 };

// 오른쪽으로 90도 회전하는 함수
int rightTurn(int direction) { return (direction + 1) % 4; }
// 왼쪽으로 90도 회전하는 함수
int leftTurn(int direction) { return (direction + 3) % 4; }

// 주어진 방향으로 회전한 후의 x 좌표를 계산하는 함수
int rotateX(int direction, Point p) {
    if (direction == 0) return p.x;
    if (direction == 1) return p.y;
    if (direction == 2) return -p.x;
    if (direction == 3) return -p.y;
    return 0; // 이 위치에 도달하지 않음
}

// 주어진 방향으로 회전한 후의 y 좌표를 계산하는 함수
int rotateY(int direction, Point p) {
    if (direction == 0) return p.y;
    if (direction == 1) return -p.x;
    if (direction == 2) return -p.y;
    if (direction == 3) return p.x;
    return 0; // 이 위치에 도달하지 않음
}

int main() {
    // 명령어를 입력받습니다.
    cin >> commands;
    int length = strlen(commands);

    // 각 명령어의 접미사에 대한 이동 오프셋을 계산합니다.
    for (int i = length - 1; i >= 0; i--) {
        if (commands[i] == 'F') {
            movementOffsets[i].x = movementOffsets[i + 1].x;
            movementOffsets[i].y = 1 + movementOffsets[i + 1].y;
        }
        if (commands[i] == 'L') {
            movementOffsets[i].x = -movementOffsets[i + 1].y;
            movementOffsets[i].y = movementOffsets[i + 1].x;
        }
        if (commands[i] == 'R') {
            movementOffsets[i].x = movementOffsets[i + 1].y;
            movementOffsets[i].y = -movementOffsets[i + 1].x;
        }
    }
    
    // 도착 지점을 저장할 set을 정의합니다.
    set<Point> uniquePoints;
    int x = 0, y = 0, direction = 0;

    // 가능한 모든 도착 지점을 계산합니다.
    for (int i = 0; i < length; i++) {
        if (commands[i] != 'F') {
            Point dest = { x + Dx[direction] + rotateX(direction, movementOffsets[i + 1]), 
                           y + Dy[direction] + rotateY(direction, movementOffsets[i + 1]) };
            uniquePoints.insert(dest);
        }
        if (commands[i] != 'L') {
            Point dest = { x + rotateX(leftTurn(direction), movementOffsets[i + 1]), 
                           y + rotateY(leftTurn(direction), movementOffsets[i + 1]) };
            uniquePoints.insert(dest);
        }
        if (commands[i] != 'R') {
            Point dest = { x + rotateX(rightTurn(direction), movementOffsets[i + 1]), 
                           y + rotateY(rightTurn(direction), movementOffsets[i + 1]) };
            uniquePoints.insert(dest);
        }
        if (commands[i] == 'F') {
            x += Dx[direction];
            y += Dy[direction];
        }
        if (commands[i] == 'L') {
            direction = leftTurn(direction);
        }
        if (commands[i] == 'R') {
            direction = rightTurn(direction);
        }
    }

    // 서로 다른 도착 지점의 수를 출력합니다.
    cout << uniquePoints.size() << endl;
    
    return 0;
}