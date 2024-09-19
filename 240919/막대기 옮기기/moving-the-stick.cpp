#include <iostream>
#include <queue>
using namespace std;

// grid 배열은 1~16 인덱스를 사용합니다.
int grid[17][17];
int gridSize, waysToReachEnd;

// 이동 방향을 나타내는 배열입니다.
// dx와 dy는 각각 가로, 대각선, 세로 방향으로 이동할 때의 x, y 변화량을 나타냅니다.
int dx[3] = {0, 1, 1}; // 가로, 대각선, 세로
int dy[3] = {1, 1, 0};

// Pipe 구조체는 현재 파이프의 위치와 방향을 나타냅니다.
struct Pipe {
    int x, y, direction;
    // 방향은 0, 1, 2 순서대로 가로, 대각선, 세로를 의미합니다.
};

// 파이프의 이동을 관리하는 큐입니다.
queue<Pipe> pipeQueue;

// 파이프를 이동시키는 함수입니다.
void movePipe(int x, int y, int direction, int moveType) {
    // 새로운 위치를 계산합니다.
    int newX = x + dx[moveType];
    int newY = y + dy[moveType];
    int newDirection = moveType;

    // 새로운 위치가 격자 안에 있고, 빈 칸인 경우에만 이동합니다.
    if (grid[newX][newY] == 0 && newX > 0 && newX <= gridSize && newY > 0 && newY <= gridSize) {
        // 대각선으로 이동하는 경우, 추가적인 체크가 필요합니다.
        if (moveType == 1) {
            if (grid[newX - 1][newY] == 1 || grid[newX][newY - 1] == 1)
                return;
        }
        // 새로운 위치와 방향을 큐에 추가합니다.
        pipeQueue.push({newX, newY, newDirection});
    }
}

int main() {
    // 입력을 받습니다.
    cin >> gridSize;
    for (int i = 1; i <= gridSize; i++) {
        for (int j = 1; j <= gridSize; j++) {
            cin >> grid[i][j];
        }
    }

    // 초기 파이프의 위치와 방향을 큐에 추가합니다.
    pipeQueue.push({1, 2, 0});

    // 큐가 빌 때까지 반복합니다.
    while (!pipeQueue.empty()) {
        // 큐에서 현재 파이프의 위치와 방향을 꺼냅니다.
        int x = pipeQueue.front().x;
        int y = pipeQueue.front().y;
        int direction = pipeQueue.front().direction;
        pipeQueue.pop();

        // 현재 위치가 (n, n)인 경우, 방법의 수를 증가시킵니다.
        if (x == gridSize && y == gridSize)
            waysToReachEnd++;

        // 현재 파이프의 방향에 따라 이동 가능한 방향을 결정합니다.
        if (direction == 0) { // 가로
            for (int i = 0; i < 2; i++) { // 0, 1로 이동
                movePipe(x, y, direction, i);
            }
        } else if (direction == 1) { // 대각선
            for (int i = 0; i < 3; i++) { // 0, 1, 2로 이동
                movePipe(x, y, direction, i);
            }
        } else { // 세로
            for (int i = 1; i < 3; i++) { // 1, 2로 이동
                movePipe(x, y, direction, i);
            }
        }
    }

    // 결과를 출력합니다.
    cout << waysToReachEnd;
    return 0;
}