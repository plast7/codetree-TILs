#include <iostream>
#include <set>
#include <string>

using namespace std;

#define MAX_N 100000

// Point 구조체를 정의합니다. 
// x, y 좌표를 가지고 있으며, set에 넣기 위해 비교 연산자를 오버로딩합니다.
struct Point {
    int x, y;
    bool operator<(const Point& other) const {
        return tie(x, y) < tie(other.x, other.y);
    }
};

// 방향에 따라 이동할 때의 x, y 변화량을 정의합니다.
// 북, 동, 남, 서 순서대로 Dx, Dy 배열을 정의합니다.
const int Dx[4] = {0, 1, 0, -1};
const int Dy[4] = {1, 0, -1, 0};

// 현재 방향에서 오른쪽으로 90도 회전하는 함수입니다.
int right_turn(int dir) { return (dir + 1) % 4; }

// 현재 방향에서 왼쪽으로 90도 회전하는 함수입니다.
int left_turn(int dir) { return (dir + 3) % 4; }

// 주어진 방향에서 x 좌표를 회전시키는 함수입니다.
int rotate_x(int dir, Point p) {
    if (dir == 0) return p.x;       // 북쪽
    if (dir == 1) return p.y;       // 동쪽
    if (dir == 2) return -p.x;      // 남쪽
    if (dir == 3) return -p.y;      // 서쪽
    return 0; // 여기에 도달하지 않아야 합니다.
}

// 주어진 방향에서 y 좌표를 회전시키는 함수입니다.
int rotate_y(int dir, Point p) {
    if (dir == 0) return p.y;       // 북쪽
    if (dir == 1) return -p.x;      // 동쪽
    if (dir == 2) return -p.y;      // 남쪽
    if (dir == 3) return p.x;       // 서쪽
    return 0; // 여기에 도달하지 않아야 합니다.
}

int main() {
    string S;
    cin >> S;
    int L = S.length();

    // 각 명령 이후의 오프셋을 저장하는 배열입니다.
    Point offset[MAX_N + 1] = {};
    for (int i = L - 1; i >= 0; i--) {
        if (S[i] == 'F') {
            offset[i].x = offset[i + 1].x + Dx[0];
            offset[i].y = offset[i + 1].y + Dy[0];
        } else if (S[i] == 'L') {
            offset[i].x = -offset[i + 1].y;
            offset[i].y = offset[i + 1].x;
        } else if (S[i] == 'R') {
            offset[i].x = offset[i + 1].y;
            offset[i].y = -offset[i + 1].x;
        }
    }

    // 도착 지점들을 저장하는 set입니다.
    set<Point> unique_points;
    int x = 0, y = 0, dir = 0;
    for (int i = 0; i < L; i++) {
        if (S[i] != 'F') {
            unique_points.insert({x + Dx[dir] + rotate_x(dir, offset[i + 1]), y + Dy[dir] + rotate_y(dir, offset[i + 1])});
        }
        if (S[i] != 'L') {
            int new_dir = left_turn(dir);
            unique_points.insert({x + rotate_x(new_dir, offset[i + 1]), y + rotate_y(new_dir, offset[i + 1])});
        }
        if (S[i] != 'R') {
            int new_dir = right_turn(dir);
            unique_points.insert({x + rotate_x(new_dir, offset[i + 1]), y + rotate_y(new_dir, offset[i + 1])});
        }
        if (S[i] == 'F') {
            x += Dx[dir];
            y += Dy[dir];
        } else if (S[i] == 'L') {
            dir = left_turn(dir);
        } else if (S[i] == 'R') {
            dir = right_turn(dir);
        }
    }

    // 서로 다른 도착 지점의 수를 출력합니다.
    cout << unique_points.size() << endl;

    return 0;
}