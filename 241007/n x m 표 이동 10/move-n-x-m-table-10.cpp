#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 전역 변수 선언
int numRows, numCols;
char grid[500][500]; // 표의 상태를 저장하는 배열
bool visited[500][500]; // 방문 여부를 기록하는 배열
int fireSpreadTime[500][500]; // 불이 퍼지는 시간을 기록하는 배열
vector<pair<int, int>> fireSources; // 초기 불의 위치를 저장하는 벡터
int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // 상하좌우 방향을 나타내는 배열

// 불이 퍼지는 시간을 계산하는 함수
void calculateFireSpread() {
    queue<pair<int, int>> fireQueue; // 불의 확산을 처리하기 위한 큐

    // 초기 불의 위치를 큐에 넣고, 불이 퍼지는 시간을 0으로 설정합니다.
    for (const auto& fire : fireSources) {
        fireQueue.push(fire);
        fireSpreadTime[fire.first][fire.second] = 0;
    }

    // BFS를 사용하여 불이 퍼지는 시간을 계산합니다.
    while (!fireQueue.empty()) {
        int currentRow = fireQueue.front().first;
        int currentCol = fireQueue.front().second;
        fireQueue.pop();

        // 상하좌우로 불이 퍼질 수 있는지 확인합니다.
        for (int i = 0; i < 4; i++) {
            int nextRow = currentRow + directions[i][0];
            int nextCol = currentCol + directions[i][1];

            // 다음 위치가 유효하고 벽이 아닌 경우
            if (nextRow >= 0 && nextRow < numRows && nextCol >= 0 && nextCol < numCols && grid[nextRow][nextCol] != '#') {
                // 현재 위치에서 1초 후에 불이 퍼질 수 있다면
                if (fireSpreadTime[currentRow][currentCol] + 1 < fireSpreadTime[nextRow][nextCol]) {
                    fireQueue.push({nextRow, nextCol});
                    fireSpreadTime[nextRow][nextCol] = fireSpreadTime[currentRow][currentCol] + 1;
                }
            }
        }
    }
}

// 플레이어가 탈출할 수 있는지 확인하는 함수
void escape(int startRow, int startCol) {
    queue<pair<pair<int, int>, int>> playerQueue; // 플레이어의 이동을 처리하기 위한 큐
    playerQueue.push({{startRow, startCol}, 0}); // 초기 위치와 시간을 큐에 넣습니다.

    // BFS를 사용하여 플레이어가 탈출할 수 있는지 확인합니다.
    while (!playerQueue.empty()) {
        int currentRow = playerQueue.front().first.first;
        int currentCol = playerQueue.front().first.second;
        int currentTime = playerQueue.front().second;
        playerQueue.pop();

        // 현재 위치가 가장자리라면 탈출 성공
        if (currentRow == 0 || currentRow == numRows - 1 || currentCol == 0 || currentCol == numCols - 1) {
            cout << currentTime + 1; // 탈출에 걸린 시간을 출력합니다.
            return;
        }

        // 상하좌우로 이동할 수 있는지 확인합니다.
        for (int i = 0; i < 4; i++) {
            int nextRow = currentRow + directions[i][0];
            int nextCol = currentCol + directions[i][1];

            // 다음 위치가 유효하고 불이 퍼지기 전에 도착할 수 있으며, 이동할 수 있는 공간인 경우
            if (nextRow >= 0 && nextRow < numRows && nextCol >= 0 && nextCol < numCols) {
                if (fireSpreadTime[nextRow][nextCol] > currentTime + 1 && grid[nextRow][nextCol] == '.') {
                    if (!visited[nextRow][nextCol]) {
                        playerQueue.push({{nextRow, nextCol}, currentTime + 1});
                        visited[nextRow][nextCol] = true; // 방문 표시
                    }
                }
            }
        }
    }

    // 탈출이 불가능한 경우
    cout << "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> numRows >> numCols;
    pair<int, int> startPosition; // 초기 위치 저장

    // 표의 상태를 입력받습니다.
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            char cell;
            cin >> cell;
            if (cell == 'F') {
                fireSources.push_back({i, j}); // 불의 위치 저장
                grid[i][j] = 'F';
                fireSpreadTime[i][j] = 0; // 불의 초기 위치는 시간 0
            } else if (cell == 'J') {
                startPosition = {i, j}; // 플레이어의 초기 위치 저장
                grid[i][j] = '.';
                fireSpreadTime[i][j] = INT_MAX; // 초기 위치는 불이 퍼지지 않음
            } else {
                grid[i][j] = cell;
                fireSpreadTime[i][j] = INT_MAX; // 초기에는 불이 퍼지지 않음
            }
        }
    }

    calculateFireSpread(); // 불이 퍼지는 시간 계산
    escape(startPosition.first, startPosition.second); // 탈출 시도

    return 0;
}