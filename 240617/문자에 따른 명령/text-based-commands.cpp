#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

// 방향을 나타내는 상수. 북쪽, 동쪽, 남쪽, 서쪽 순서.
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

// 방향을 오른쪽으로 회전시키는 함수.
int right_turn(int dir) {
    return (dir + 1) % 4;
}

// 방향을 왼쪽으로 회전시키는 함수.
int left_turn(int dir) {
    return (dir + 3) % 4;
}

int main() {
    // 입력 문자열을 받습니다.
    string commands;
    cin >> commands;

    int length = commands.length();

    // 명령 중 하나를 변경했을 때의 가능한 도착 지점을 저장할 집합.
    set<pair<int, int>> destinations;

    // 명령의 각 위치에서 이동 후의 위치와 방향을 기록합니다.
    vector<int> x(length + 1, 0), y(length + 1, 0), direction(length + 1, 0);

    // 처음 위치에서 시작하여 각 명령을 수행합니다.
    for (int i = 0; i < length; ++i) {
        if (commands[i] == 'F') {
            x[i + 1] = x[i] + dx[direction[i]];
            y[i + 1] = y[i] + dy[direction[i]];
            direction[i + 1] = direction[i];
        } else if (commands[i] == 'L') {
            x[i + 1] = x[i];
            y[i + 1] = y[i];
            direction[i + 1] = left_turn(direction[i]);
        } else if (commands[i] == 'R') {
            x[i + 1] = x[i];
            y[i + 1] = y[i];
            direction[i + 1] = right_turn(direction[i]);
        }
    }

    // 각 명령을 하나씩 변경해가며 가능한 도착 지점을 계산합니다.
    for (int i = 0; i < length; ++i) {
        // 명령을 'L'로 변경했을 때.
        int new_dir = left_turn(direction[i]);
        int new_x = x[i] + dx[new_dir];
        int new_y = y[i] + dy[new_dir];
        for (int j = i + 1; j <= length; ++j) {
            if (commands[j - 1] == 'F') {
                new_x += dx[new_dir];
                new_y += dy[new_dir];
            } else if (commands[j - 1] == 'L') {
                new_dir = left_turn(new_dir);
            } else if (commands[j - 1] == 'R') {
                new_dir = right_turn(new_dir);
            }
        }
        destinations.insert({new_x, new_y});

        // 명령을 'R'로 변경했을 때.
        new_dir = right_turn(direction[i]);
        new_x = x[i] + dx[new_dir];
        new_y = y[i] + dy[new_dir];
        for (int j = i + 1; j <= length; ++j) {
            if (commands[j - 1] == 'F') {
                new_x += dx[new_dir];
                new_y += dy[new_dir];
            } else if (commands[j - 1] == 'L') {
                new_dir = left_turn(new_dir);
            } else if (commands[j - 1] == 'R') {
                new_dir = right_turn(new_dir);
            }
        }
        destinations.insert({new_x, new_y});

        // 명령을 'F'로 변경했을 때.
        new_x = x[i] + dx[direction[i]];
        new_y = y[i] + dy[direction[i]];
        new_dir = direction[i];
        for (int j = i + 1; j <= length; ++j) {
            if (commands[j - 1] == 'F') {
                new_x += dx[new_dir];
                new_y += dy[new_dir];
            } else if (commands[j - 1] == 'L') {
                new_dir = left_turn(new_dir);
            } else if (commands[j - 1] == 'R') {
                new_dir = right_turn(new_dir);
            }
        }
        destinations.insert({new_x, new_y});
    }

    // 서로 다른 도착 지점의 수를 출력합니다.
    cout << destinations.size() << endl;

    return 0;
}