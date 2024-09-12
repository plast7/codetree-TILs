#include <iostream>

using namespace std;

#define MAX_N 300

int n, m;
int dp[MAX_N][MAX_N];
bool arr[MAX_N][MAX_N];

int main() {
    // 행과 열의 수를 입력받습니다.
    cin >> n >> m;

    // 배열을 입력받아 저장합니다.
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];

    // dp 배열의 초기값 설정입니다.
    dp[0][0] = arr[0][0];

    // dp 연산을 수행합니다.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i != 0) // 첫 행이 아닌 경우 위쪽 값을 확인합니다.
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j]);
            if (j != 0) // 첫 열이 아닌 경우 왼쪽 값을 확인합니다.
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + arr[i][j]);
        }
    }

    // 마지막 위치에서의 최댓값을 출력합니다.
    cout << dp[n - 1][m - 1] << '\n';

    return 0;
}