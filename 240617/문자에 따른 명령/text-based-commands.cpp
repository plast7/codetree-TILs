#include <iostream>
#include <string>
#include <set>

using namespace std;

// 좌표를 나타내는 구조체입니다.
struct Point {
    int x, y;

    // 좌표 비교를 위한 연산자 오버로딩을 정의합니다.
    bool operator<(const Point& p) const {
        if (x == p.x)
            return y < p.y;
        return x < p.x;
    }
};

int main() {
    string commands;
    cin >> commands;
    
    int n = commands.size();

    // 방향을 나타내는 배열입니다. 북, 동, 남, 서 순서입니다.
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    // 모든 도착 지점을 저장하기 위한 집합입니다.
    set<Point> uniquePoints;

    // 명령을 하나씩 잘못된 것으로 가정하고 모든 가능한 도착 지점을 계산합니다.
    for (int i = 0; i < n; ++i) {
        int x = 0, y = 0, dir = 0;
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                // 잘못된 명령을 무시하고 넘어갑니다.
                continue;
            }
            if (commands[j] == 'F') {
                x += dx[dir];
                y += dy[dir];
            } else if (commands[j] == 'L') {
                dir = (dir + 3) % 4; // 왼쪽으로 회전합니다.
            } else if (commands[j] == 'R') {
                dir = (dir + 1) % 4; // 오른쪽으로 회전합니다.
            }
        }
        // 도착 지점을 집합에 추가합니다.
        uniquePoints.insert({x, y});
    }

    // 서로 다른 도착 지점의 수를 출력합니다.
    cout << uniquePoints.size() << endl;

    return 0;
}