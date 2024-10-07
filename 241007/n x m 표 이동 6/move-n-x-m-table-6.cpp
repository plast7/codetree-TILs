#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 변수 선언
int numRows, numCols, maxTime;
char grid[100][100];
// 방문 여부를 기록하는 배열입니다.
// visited[i][j][0]은 2를 지나기 전의 방문 여부를,
// visited[i][j][1]은 2를 지난 후의 방문 여부를 기록합니다.
bool visited[100][100][2];
// 상하좌우 네 방향을 나타내는 배열입니다.
int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

// BFS를 통해 최단 시간을 구하는 함수입니다.
void bfs() {
    // 큐를 선언하고 초기 위치를 넣어줍니다.
    // 큐의 원소는 (현재 행, 현재 열), (2를 지났는지 여부, 현재 시간)입니다.
    queue<pair<pair<int, int>, pair<bool, int>>> q;
    q.push({ {0, 0}, {false, 0} });

    // 큐가 빌 때까지 반복합니다.
    while (!q.empty()) {
        // 큐의 맨 앞 원소를 꺼내옵니다.
        int currentRow = q.front().first.first;
        int currentCol = q.front().first.second;
        bool passedThroughTwo = q.front().second.first;
        int currentTime = q.front().second.second;
        q.pop();

        // 현재 시간이 최대 시간을 초과하면 Fail을 출력하고 종료합니다.
        if (currentTime > maxTime) {
            cout << "Fail";
            return;
        }
        // 목적지에 도달하면 현재 시간을 출력하고 종료합니다.
        if (currentRow == numRows - 1 && currentCol == numCols - 1) {
            cout << currentTime;
            return;
        }

        // 네 방향으로 이동을 시도합니다.
        for (int i = 0; i < 4; i++) {
            int newRow = currentRow + directions[i][0];
            int newCol = currentCol + directions[i][1];
            int newTime = currentTime + 1;

            // 새로운 위치가 유효한 범위 내에 있는지 확인합니다.
            if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols) {
                // 2를 지난 후라면 1도 지나갈 수 있습니다.
                if (passedThroughTwo) {
                    // 아직 방문하지 않은 경우에만 큐에 추가합니다.
                    if (!visited[newRow][newCol][1]) {
                        q.push({ {newRow, newCol}, {true, newTime} });
                        visited[newRow][newCol][1] = true;
                    }
                } else {
                    // 0인 경우에만 지나갈 수 있습니다.
                    if (grid[newRow][newCol] == '0' && !visited[newRow][newCol][0]) {
                        q.push({ {newRow, newCol}, {false, newTime} });
                        visited[newRow][newCol][0] = true;
                    // 2를 지나면 이후로는 1도 지나갈 수 있습니다.
                    } else if (grid[newRow][newCol] == '2' && !visited[newRow][newCol][0]) {
                        q.push({ {newRow, newCol}, {true, newTime} });
                        visited[newRow][newCol][1] = true;
                    }
                }
            }
        }
    }
    // 큐가 비었는데도 목적지에 도달하지 못했다면 Fail을 출력합니다.
    cout << "Fail";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 입력을 받습니다.
    cin >> numRows >> numCols >> maxTime;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cin >> grid[i][j];
        }
    }
    // BFS를 실행합니다.
    bfs();
    return 0;
}