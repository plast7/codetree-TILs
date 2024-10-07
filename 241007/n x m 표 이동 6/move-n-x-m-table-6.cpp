#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 변수 선언
int rows, cols, max_time;
char grid[100][100];

// 방문 여부를 기록하는 배열입니다.
// visited[i][j][0]은 검을 얻기 전 방문 여부를,
// visited[i][j][1]은 검을 얻은 후 방문 여부를 기록합니다.
bool visited[100][100][2];

// 상하좌우 이동을 위한 방향 배열입니다.
int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

// BFS를 통해 최단 시간을 구하는 함수입니다.
void bfs() {
    // 큐에는 현재 위치와 검을 얻었는지 여부, 현재 시간을 저장합니다.
    queue<pair<pair<int, int>, pair<bool, int>>> q;
    // 시작 위치는 (0, 0)이며, 검을 얻지 않은 상태로 시작합니다.
    q.push({ {0, 0}, {false, 0} });

    // 큐가 빌 때까지 반복합니다.
    while (!q.empty()) {
        // 큐의 front에서 현재 위치와 상태를 가져옵니다.
        int current_row = q.front().first.first;
        int current_col = q.front().first.second;
        bool has_sword = q.front().second.first;
        int current_time = q.front().second.second;
        q.pop();

        // 현재 시간이 최대 시간을 초과하면 실패를 출력합니다.
        if (current_time > max_time) {
            cout << "Fail";
            return;
        }
        // 목적지에 도달하면 현재 시간을 출력합니다.
        if (current_row == rows - 1 && current_col == cols - 1) {
            cout << current_time;
            return;
        }

        // 4방향으로 이동을 시도합니다.
        for (int i = 0; i < 4; i++) {
            int next_row = current_row + directions[i][0];
            int next_col = current_col + directions[i][1];
            int next_time = current_time + 1;

            // 이동할 위치가 유효한 범위 내에 있는지 확인합니다.
            if (next_row >= 0 && next_row < rows && next_col >= 0 && next_col < cols) {
                // 검을 가지고 있는 경우
                if (has_sword) {
                    // 검을 가지고 있는 상태에서 방문하지 않은 경우
                    if (!visited[next_row][next_col][1]) {
                        q.push({ {next_row, next_col}, {true, next_time} });
                        visited[next_row][next_col][1] = true;
                    }
                } 
                // 검을 가지고 있지 않은 경우
                else {
                    // 0인 칸으로 이동할 수 있는 경우
                    if (grid[next_row][next_col] == '0' && !visited[next_row][next_col][0]) {
                        q.push({ {next_row, next_col}, {false, next_time} });
                        visited[next_row][next_col][0] = true;
                    } 
                    // 2인 칸으로 이동하여 검을 얻는 경우
                    else if (grid[next_row][next_col] == '2' && !visited[next_row][next_col][0]) {
                        q.push({ {next_row, next_col}, {true, next_time} });
                        visited[next_row][next_col][1] = true;
                    }
                }
            }
        }
    }
    // 큐가 비었는데도 목적지에 도달하지 못한 경우 실패를 출력합니다.
    cout << "Fail";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 입력:
    cin >> rows >> cols >> max_time;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    // BFS를 통해 최소 시간을 구합니다.
    bfs();
    return 0;
}