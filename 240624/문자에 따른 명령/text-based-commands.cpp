#include <iostream>
#include <string>
#include <set>
#include <tuple>

using namespace std;

// Point 구조체를 정의합니다. 좌표를 나타내며, set에서 사용하기 위해 비교 연산자를 오버로딩합니다.
struct Point {
    int x, y;
    bool operator<(const Point &p) const {
        return tie(x, y) < tie(p.x, p.y);
    }
};

int main() {
    string commands;
    cin >> commands;

    int n = commands.size();
    set<Point> unique_positions;

    // 방향을 나타내는 배열을 정의합니다.
    // 0 = 북쪽, 1 = 동쪽, 2 = 남쪽, 3 = 서쪽을 의미합니다.
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    // 각 명령어를 하나씩 변경해가며 모든 경우를 확인합니다.
    for (int i = 0; i < n; ++i) {
        string modified_commands = commands;
        Point pos = {0, 0};
        int direction = 0;

        // i번째 명령어를 변경합니다.
        if (commands[i] == 'L') modified_commands[i] = 'F';
        else if (commands[i] == 'R') modified_commands[i] = 'F';
        else modified_commands[i] = 'L';

        // 변경된 명령어를 실행합니다.
        for (char command : modified_commands) {
            if (command == 'L') direction = (direction + 3) % 4; // 왼쪽으로 회전합니다.
            else if (command == 'R') direction = (direction + 1) % 4; // 오른쪽으로 회전합니다.
            else { // 'F'인 경우 현재 방향으로 한 칸 이동합니다.
                pos.x += dx[direction];
                pos.y += dy[direction];
            }
        }

        // 도착한 위치를 set에 추가합니다.
        unique_positions.insert(pos);
    }

    // 서로 다른 도착 지점의 수를 출력합니다.
    cout << unique_positions.size() << endl;
    return 0;
}