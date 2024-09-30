#include <bits/stdc++.h>
using namespace std;

// Position 구조체를 정의합니다.
// x, y, z 좌표와 현재까지의 턴 수를 저장합니다.
struct Position {
    int x, y, z, turns;
};

// 전역 변수 선언
int width, height, depth;
int box[101][101][101];
bool visited[101][101][101];

// 6방향 이동을 위한 배열
int moveX[6] = {1, -1, 0, 0, 0, 0};
int moveY[6] = {0, 0, 1, -1, 0, 0};
int moveZ[6] = {0, 0, 0, 0, 1, -1};

// BFS를 위한 큐
queue<Position> bfsQueue;

int main() {
    int maxTurns = 0;

    // 입력을 받습니다.
    cin >> width >> height >> depth;
    for (int z = 0; z < depth; z++) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                cin >> box[y][x][z];
                // 1인 칸은 BFS의 시작점이 됩니다.
                if (box[y][x][z] == 1) {
                    bfsQueue.push({x, y, z, 0});
                    visited[y][x][z] = true;
                } 
                // -1인 칸은 방문할 수 없으므로 미리 방문 처리합니다.
                else if (box[y][x][z] == -1) {
                    visited[y][x][z] = true;
                }
            }
        }
    }

    // BFS 큐가 비어있다면, 1이 존재하지 않으므로 -1을 출력합니다.
    if (bfsQueue.empty()) {
        cout << "-1";
        return 0;
    }

    // BFS를 수행합니다.
    while (!bfsQueue.empty()) {
        auto current = bfsQueue.front();
        bfsQueue.pop();
        maxTurns = max(maxTurns, current.turns);

        // 6방향으로 이동합니다.
        for (int i = 0; i < 6; i++) {
            int newX = current.x + moveX[i];
            int newY = current.y + moveY[i];
            int newZ = current.z + moveZ[i];

            // 유효한 범위 내에 있고, 방문하지 않은 0인 칸이라면 큐에 추가합니다.
            if (newX >= 0 && newY >= 0 && newZ >= 0 && newX < width && newY < height && newZ < depth && !visited[newY][newX][newZ] && box[newY][newX][newZ] == 0) {
                bfsQueue.push({newX, newY, newZ, current.turns + 1});
                visited[newY][newX][newZ] = true;
            }
        }
    }

    // 모든 칸을 확인하여 방문하지 않은 0인 칸이 있는지 확인합니다.
    for (int z = 0; z < depth; z++) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (box[y][x][z] == 0 && !visited[y][x][z]) {
                    cout << "-1";
                    return 0;
                }
            }
        }
    }

    // 최소 턴 수를 출력합니다.
    cout << maxTurns;
    return 0;
}