#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

// 좌표를 나타내는 구조체를 정의합니다.
struct Point {
    int x, y;
    // 좌표를 비교하는 연산자를 정의합니다.
    bool operator<(const Point& other) const {
        return tie(x, y) < tie(other.x, other.y);
    }
};

int main() {
    string commands;
    cin >> commands;
    int n = commands.size();

    // 가능한 도착 지점을 저장할 벡터를 정의합니다.
    vector<Point> possible_endpoints;
    // 방향을 나타내는 배열을 정의합니다.
    // 북(0), 동(1), 남(2), 서(3) 순서로 방향을 나타냅니다.
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    // 각 명령을 하나씩 변경해봅니다.
    for (int i = 0; i < n; ++i) {
        string modified_commands = commands;
        // 중복된 도착 지점을 제거하기 위해 set을 사용합니다.
        set<Point> unique_endpoints;

        // 'L', 'R', 'F' 각각의 명령으로 변경해봅니다.
        for (char c : {'L', 'R', 'F'}) {
            // 현재 명령과 같은 경우는 건너뜁니다.
            if (commands[i] == c) continue;
            // 명령을 변경합니다.
            modified_commands[i] = c;

            // 초기 위치와 방향을 설정합니다.
            int x = 0, y = 0, dir = 0;
            // 변경된 명령을 수행합니다.
            for (char cmd : modified_commands) {
                if (cmd == 'L') {
                    // 왼쪽으로 90도 회전합니다.
                    dir = (dir + 3) % 4;
                } else if (cmd == 'R') {
                    // 오른쪽으로 90도 회전합니다.
                    dir = (dir + 1) % 4;
                } else if (cmd == 'F') {
                    // 현재 방향으로 한 칸 이동합니다.
                    x += dx[dir];
                    y += dy[dir];
                }
            }
            // 도착 지점을 set에 추가합니다.
            unique_endpoints.insert({x, y});
        }

        // 가능한 도착 지점을 벡터에 추가합니다.
        possible_endpoints.insert(possible_endpoints.end(), unique_endpoints.begin(), unique_endpoints.end());
    }

    // 중복된 도착 지점을 제거하기 위해 set을 사용합니다.
    set<Point> unique_possible_endpoints(possible_endpoints.begin(), possible_endpoints.end());
    // 서로 다른 도착 지점의 수를 출력합니다.
    cout << unique_possible_endpoints.size() << endl;

    return 0;
}