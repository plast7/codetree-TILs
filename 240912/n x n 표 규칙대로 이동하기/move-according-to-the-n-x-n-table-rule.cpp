#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 500;

// 다음 색깔을 결정하는 함수입니다.
// 현재 색깔이 0이면 다음 색깔은 1, 1이면 2, 2이면 0이 됩니다.
int getNextColor(int currentColor) {
    return (currentColor + 1) % 3;
}

int main() {
    int n;
    cin >> n;

    // n x n 크기의 표를 저장할 벡터입니다.
    vector<vector<int>> grid(n, vector<int>(n));
    // dp[i][j]는 (i, j)까지 이동하면서 색칠할 수 있는 최대 칸의 수를 저장합니다.
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // nextColor[i][j]는 (i, j)까지 이동했을 때 다음에 색칠해야 할 색깔을 저장합니다.
    vector<vector<int>> nextColor(n, vector<int>(n, 0));

    // 표의 값을 입력받습니다.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    // 시작점이 0인 경우 초기화합니다.
    if (grid[0][0] == 0) {
        dp[0][0] = 1;
        nextColor[0][0] = 1;
    }

    // 첫 번째 행을 초기화합니다.
    for (int i = 1; i < n; ++i) {
        if (grid[0][i] == nextColor[0][i - 1]) {
            dp[0][i] = dp[0][i - 1] + 1;
            nextColor[0][i] = getNextColor(nextColor[0][i - 1]);
        } else {
            dp[0][i] = dp[0][i - 1];
            nextColor[0][i] = nextColor[0][i - 1];
        }
    }

    // 첫 번째 열을 초기화합니다.
    for (int i = 1; i < n; ++i) {
        if (grid[i][0] == nextColor[i - 1][0]) {
            dp[i][0] = dp[i - 1][0] + 1;
            nextColor[i][0] = getNextColor(nextColor[i - 1][0]);
        } else {
            dp[i][0] = dp[i - 1][0];
            nextColor[i][0] = nextColor[i - 1][0];
        }
    }

    // 나머지 표를 채웁니다.
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            int topNextColor = nextColor[i - 1][j];
            int leftNextColor = nextColor[i][j - 1];

            int topCount = (grid[i][j] == topNextColor) ? dp[i - 1][j] + 1 : dp[i - 1][j];
            int leftCount = (grid[i][j] == leftNextColor) ? dp[i][j - 1] + 1 : dp[i][j - 1];

            if (topCount > leftCount) {
                dp[i][j] = topCount;
                nextColor[i][j] = (grid[i][j] == topNextColor) ? getNextColor(topNextColor) : topNextColor;
            } else {
                dp[i][j] = leftCount;
                nextColor[i][j] = (grid[i][j] == leftNextColor) ? getNextColor(leftNextColor) : leftNextColor;
            }
        }
    }

    // 최종적으로 오른쪽 최하단까지 이동하면서 색칠할 수 있는 최대 칸의 수를 출력합니다.
    cout << dp[n - 1][n - 1] << endl;

    return 0;
}