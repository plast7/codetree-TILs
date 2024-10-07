#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_SIZE 201
using namespace std;

// 변수 선언
int width, height, maxJumps;

// 이동 가능한 방향을 정의합니다. 
// moveDirections는 상하좌우로 이동하는 경우를 나타냅니다.
int moveDirections[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

// jumpDirections는 점프 이동을 나타냅니다.
int jumpDirections[8][2] = { {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1} };

// 방문 여부를 기록하는 3차원 배열입니다.
// visited[row][col][jumpsLeft]는 (row, col) 위치에 jumpsLeft번 점프를 남긴 상태로 방문했는지를 나타냅니다.
bool visited[MAX_SIZE][MAX_SIZE][31];

// 표의 각 칸의 상태를 저장합니다. '0'은 이동 가능, '1'은 이동 불가를 의미합니다.
char grid[MAX_SIZE][MAX_SIZE];

// BFS를 통해 최소 이동 횟수를 찾습니다.
void bfs() {
    // 큐에는 현재 위치와 이동 횟수, 남은 점프 횟수를 저장합니다.
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({ {0, 0}, {0, maxJumps} });
    visited[0][0][maxJumps] = true;

    // 큐가 빌 때까지 반복합니다.
    while (!q.empty()) {
        // 현재 위치와 상태를 큐에서 꺼냅니다.
        int currentRow = q.front().first.first;
        int currentCol = q.front().first.second;
        int moveCount = q.front().second.first;
        int jumpsLeft = q.front().second.second;
        
        q.pop();

        // 목적지에 도달한 경우, 이동 횟수를 출력하고 종료합니다.
        if (currentRow == height - 1 && currentCol == width - 1) {
            cout << moveCount;
            return;
        }

        // 점프를 사용할 수 있는 경우, 점프 이동을 시도합니다.
        if (jumpsLeft > 0) {
            for (int i = 0; i < 8; i++) {
                int newRow = currentRow + jumpDirections[i][0];
                int newCol = currentCol + jumpDirections[i][1];
                // 유효한 위치이고, 이동 가능한 칸인 경우
                if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width && grid[newRow][newCol] == '0') {
                    // 아직 방문하지 않은 경우
                    if (!visited[newRow][newCol][jumpsLeft - 1]) {
                        q.push({ {newRow, newCol}, {moveCount + 1, jumpsLeft - 1} });
                        visited[newRow][newCol][jumpsLeft - 1] = true;
                    }
                }
            }
        }

        // 상하좌우 이동을 시도합니다.
        for (int i = 0; i < 4; i++) {
            int newRow = currentRow + moveDirections[i][0];
            int newCol = currentCol + moveDirections[i][1];
            // 유효한 위치이고, 이동 가능한 칸인 경우
            if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width && grid[newRow][newCol] == '0') {
                // 아직 방문하지 않은 경우
                if (!visited[newRow][newCol][jumpsLeft]) {
                    q.push({ {newRow, newCol}, {moveCount + 1, jumpsLeft} });
                    visited[newRow][newCol][jumpsLeft] = true;
                }
            }
        }
    }

    // 목적지에 도달할 수 없는 경우 -1을 출력합니다.
    cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 입력:
    cin >> maxJumps >> height >> width;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> grid[i][j];
        }
    }

    // BFS를 통해 최소 이동 횟수를 계산합니다.
    bfs();

    return 0;
}