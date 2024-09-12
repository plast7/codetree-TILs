#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 비용을 저장하는 2차원 벡터
vector<vector<int>> cost;
// dp 배열을 저장하는 3차원 벡터
vector<vector<vector<int>>> dp;
int rows, cols;

// 최소 경로 합을 찾는 함수
int findMinPathSum(int x, int y, int dir) {
    // 만약 마지막 행에 도달했다면 0을 반환합니다.
    if (x == rows) {
        return 0;
    }

    // 이미 계산된 값이 있다면 그 값을 반환합니다.
    if (dp[x][y][dir] != INT_MAX) {
        return dp[x][y][dir];
    }

    // 왼쪽으로 이동
    if (dir != 0 && y - 1 >= 0) {
        dp[x][y][dir] = findMinPathSum(x + 1, y - 1, 0) + cost[x][y];
    }

    // 아래로 이동
    if (dir != 1) {
        dp[x][y][dir] = min(dp[x][y][dir], findMinPathSum(x + 1, y, 1) + cost[x][y]);
    }

    // 오른쪽으로 이동
    if (dir != 2 && y + 1 < cols) {
        dp[x][y][dir] = min(dp[x][y][dir], findMinPathSum(x + 1, y + 1, 2) + cost[x][y]);
    }

    return dp[x][y][dir];
}

int main() {
    // 행과 열의 크기를 입력받습니다.
    cin >> rows >> cols;

    // 비용 배열의 크기를 조정합니다.
    cost.resize(rows, vector<int>(cols));
    // dp 배열의 크기를 조정합니다.
    dp.resize(rows, vector<vector<int>>(cols, vector<int>(4, INT_MAX)));

    // 비용 배열을 입력받습니다.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> cost[i][j];
        }
    }

    // 최소 경로 합을 저장할 변수를 초기화합니다.
    int minPathSum = INT_MAX;
    // 첫 번째 행의 모든 열에 대해 최소 경로 합을 계산합니다.
    for (int i = 0; i < cols; i++) {
        minPathSum = min(minPathSum, findMinPathSum(0, i, 3));
    }

    // 최소 경로 합을 출력합니다.
    cout << minPathSum;

    return 0;
}