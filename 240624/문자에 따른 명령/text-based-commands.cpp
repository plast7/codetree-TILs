#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

// Point 구조체: 좌표를 저장하며, set에서 중복을 피하기 위해 < 연산자를 오버로딩합니다.
struct Point {
    int x, y;
    // 좌표를 비교하기 위한 < 연산자 오버로딩
    bool operator<(const Point& other) const {
        return tie(x, y) < tie(other.x, other.y);
    }
};

int main() {
    // 명령어 문자열을 입력받습니다.
    string commands;
    cin >> commands;
    
    int n = commands.size();
    // 각 명령어 수행 후의 위치와 방향을 저장할 벡터를 선언합니다.
    vector<Point> positions(n + 1);
    vector<int> directions(n + 1);
    
    // 방향에 따른 이동 좌표를 정의합니다. (북, 동, 남, 서)
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    // 초기 위치와 방향을 설정합니다. (0, 0)에서 북쪽을 향함
    int x = 0, y = 0, dir = 0;
    positions[0] = {x, y};
    directions[0] = dir;
    
    // 주어진 명령어에 따라 이동을 수행합니다.
    for (int i = 0; i < n; ++i) {
        if (commands[i] == 'L') {
            // 왼쪽으로 90도 회전
            dir = (dir + 3) % 4;
        } else if (commands[i] == 'R') {
            // 오른쪽으로 90도 회전
            dir = (dir + 1) % 4;
        } else if (commands[i] == 'F') {
            // 현재 방향으로 한 칸 이동
            x += dx[dir];
            y += dy[dir];
        }
        // 현재 위치와 방향을 저장합니다.
        positions[i + 1] = {x, y};
        directions[i + 1] = dir;
    }
    
    // 서로 다른 도착 지점을 저장할 set을 선언합니다.
    set<Point> unique_positions;
    
    // 각 명령이 잘못되었을 경우를 가정하여 가능한 모든 도착 지점을 계산합니다.
    for (int i = 0; i < n; ++i) {
        // 현재 위치와 방향을 가져옵니다.
        x = positions[i].x;
        y = positions[i].y;
        dir = directions[i];
        
        // 현재 명령이 'L'이 아닌 경우 'L'로 잘못되었다고 가정하고 이동합니다.
        if (commands[i] != 'L') {
            int new_dir = (dir + 3) % 4;
            unique_positions.insert({x + dx[new_dir], y + dy[new_dir]});
        }
        // 현재 명령이 'R'이 아닌 경우 'R'로 잘못되었다고 가정하고 이동합니다.
        if (commands[i] != 'R') {
            int new_dir = (dir + 1) % 4;
            unique_positions.insert({x + dx[new_dir], y + dy[new_dir]});
        }
        // 현재 명령이 'F'가 아닌 경우 'F'로 잘못되었다고 가정하고 이동합니다.
        if (commands[i] != 'F') {
            unique_positions.insert({x + dx[dir], y + dy[dir]});
        }
    }
    
    // 서로 다른 도착 지점의 수를 출력합니다.
    cout << unique_positions.size() << endl;
    return 0;
}