#include <iostream>
#include <string>
#include <set>

using namespace std;

// 좌표를 나타내는 구조체를 정의합니다.
struct Point {
    int x, y;
    // 좌표를 비교하기 위한 연산자를 정의합니다.
    bool operator<(const Point& other) const {
        return tie(x, y) < tie(other.x, other.y);
    }
};

int main() {
    // 명령어 문자열을 입력받습니다.
    string commands;
    cin >> commands;

    // 명령어의 길이를 구합니다.
    int n = commands.size();
    
    // 방향을 나타내는 배열을 정의합니다. (북, 동, 남, 서)
    int dx[4] = {0, 1, 0, -1}; // N, E, S, W
    int dy[4] = {1, 0, -1, 0}; // N, E, S, W

    // 서로 다른 도착 지점을 저장하기 위한 집합을 정의합니다.
    set<Point> unique_positions;

    // 각 명령어를 하나씩 바꿔가며 가능한 모든 경우를 확인합니다.
    for (int i = 0; i < n; ++i) {
        // 명령어를 복사합니다.
        string temp_commands = commands;
        // 'L', 'R', 'F'로 바꿔가며 시뮬레이션을 진행합니다.
        for (char c : {'L', 'R', 'F'}) {
            temp_commands[i] = c;
            int x = 0, y = 0, dir = 0; // 초기 위치와 방향을 설정합니다.
            // 바뀐 명령어로 시뮬레이션을 진행합니다.
            for (char command : temp_commands) {
                if (command == 'L') {
                    // 왼쪽으로 90도 회전합니다.
                    dir = (dir + 3) % 4;
                } else if (command == 'R') {
                    // 오른쪽으로 90도 회전합니다.
                    dir = (dir + 1) % 4;
                } else if (command == 'F') {
                    // 현재 방향으로 한 칸 이동합니다.
                    x += dx[dir];
                    y += dy[dir];
                }
            }
            // 도착한 지점을 집합에 추가합니다.
            unique_positions.insert({x, y});
        }
    }

    // 서로 다른 도착 지점의 수를 출력합니다.
    cout << unique_positions.size() << endl;

    return 0;
}