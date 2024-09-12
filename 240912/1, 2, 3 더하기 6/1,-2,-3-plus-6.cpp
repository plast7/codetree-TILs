#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    // dp[i][j] : i를 1, 2, 3의 합으로 나타낼 때, 사용한 수의 개수가 j개인 경우의 수를 저장합니다.
    vector<vector<int>> dp(1001, vector<int>(1001, 0));

    // 초기 조건: 1, 2, 3을 1개의 수로 나타내는 경우는 각각 1가지입니다.
    dp[1][1] = dp[2][1] = dp[3][1] = 1;

    // dp 배열을 채워나갑니다.
    for (int i = 2; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            // 1, 2, 3을 사용하여 현재 값을 만들 수 있는지 확인합니다.
            for (int k = 1; k <= 3; k++) {
                if (j - k > 0) {
                    // dp[j][i]는 dp[j - k][i - 1]의 값을 더한 것입니다.
                    dp[j][i] = (dp[j][i] + dp[j - k][i - 1]) % MOD;
                }
            }
        }
    }

    // 결과를 출력합니다.
    cout << dp[n][m] << endl;
    return 0;
}