#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 99999999;

// 각 칸의 비용을 저장하는 배열
int cost[510][510];
// dp 배열: dp[x][y][dir]는 (x, y) 위치에 dir 방향으로 도착했을 때의 최소 비용을 저장합니다.
// dir: 0은 남서쪽, 1은 남쪽, 2는 남동쪽을 의미합니다.
int dp[510][510][3]; 
int rows, cols;

// (x, y) 위치에서 dir 방향으로 이동했을 때의 최소 비용을 찾는 함수
int findMinCost(int x, int y, int dir) {
    // 만약 가장 아래 행에 도달했다면 더 이상 이동할 필요가 없으므로 0을 반환합니다.
    if (x == rows) {
        return 0;
    }

    // 이미 계산된 값이 있다면 그 값을 반환합니다.
    if (dp[x][y][dir] != INF) {
        return dp[x][y][dir];
    }

    // 남서쪽으로 이동하는 경우
    if (dir != 0 && y - 1 >= 0) {
        dp[x][y][dir] = findMinCost(x + 1, y - 1, 0) + cost[x][y];
    }

    // 남쪽으로 이동하는 경우
    if (dir != 1) {
        dp[x][y][dir] = min(dp[x][y][dir], findMinCost(x + 1, y, 1) + cost[x][y]);
    }

    // 남동쪽으로 이동하는 경우
    if (dir != 2 && y + 1 < cols) {
        dp[x][y][dir] = min(dp[x][y][dir], findMinCost(x + 1, y + 1, 2) + cost[x][y]);
    }

    return dp[x][y][dir];
}

int main() {
    // 행과 열의 개수를 입력받습니다.
    cin >> rows >> cols;

    // 각 칸의 비용을 입력받고 dp 배열을 초기화합니다.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> cost[i][j];
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = INF;
            }
        }
    }

    int minCost = INF;
    // 가장 위의 행의 모든 위치에서 출발하여 최소 비용을 찾습니다.
    for (int i = 0; i < cols; i++) {
        minCost = min(minCost, findMinCost(0, i, 3));
    }

    // 최소 비용을 출력합니다.
    cout << minCost;

    return 0;
}