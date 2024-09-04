#include <iostream>
#include <vector>

using namespace std;

// 보드의 최대 크기를 정의합니다.
int board[100][100];
// dp 배열을 정의합니다. dp[i][j]는 (i, j) 위치에 도달하는 경로의 수를 의미합니다.
long long dp[100][100];
int n;

int main() {
    // 보드의 크기를 입력받습니다.
    cin >> n;

    // 보드의 각 칸에 적혀있는 숫자를 입력받습니다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // 시작점 (0, 0)에서 출발하는 경로의 수는 1입니다.
    dp[0][0] = 1;

    // 보드의 각 칸을 순회합니다.
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // 현재 칸의 숫자가 0이면 이동할 수 없으므로 continue 합니다.
            if (board[row][col] == 0) continue;

            // 현재 칸에 도달할 수 있는 경로가 있는 경우에만 다음 칸으로 이동합니다.
            if (dp[row][col] != 0) {
                // 오른쪽으로 이동할 위치를 계산합니다.
                int next_row = row + board[row][col];
                // 아래쪽으로 이동할 위치를 계산합니다.
                int next_col = col + board[row][col];

                // 오른쪽으로 이동할 위치가 보드의 범위 내에 있는 경우 경로의 수를 갱신합니다.
                if (next_row < n) dp[next_row][col] += dp[row][col];
                // 아래쪽으로 이동할 위치가 보드의 범위 내에 있는 경우 경로의 수를 갱신합니다.
                if (next_col < n) dp[row][next_col] += dp[row][col];
            }
        }
    }

    // 오른쪽 최하단 (n-1, n-1) 위치에 도달하는 경로의 수를 출력합니다.
    cout << dp[n - 1][n - 1];

    return 0;
}