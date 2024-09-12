#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

// dp[i][j] :
// i를 1, 2, 3의 합으로 나타낼 때,
// 사용한 수의 개수가 j개 이하가 되게 하는 방법의 수를 기록합니다.
ll dp[1001][1001];

int main() {
    int targetSum, maxNumbers;
    cin >> targetSum >> maxNumbers;

    // 초기 조건 설정
    // 1을 1개의 수로 나타내는 방법은 1가지 (1)
    dp[1][1] = 1;
    // 2를 1개의 수로 나타내는 방법은 1가지 (2)
    dp[2][1] = 1;
    // 2를 2개의 수로 나타내는 방법은 1가지 (1+1)
    dp[2][2] = 1;
    // 3을 1개의 수로 나타내는 방법은 1가지 (3)
    dp[3][1] = 1;
    // 3을 2개의 수로 나타내는 방법은 2가지 (1+2, 2+1)
    dp[3][2] = 2;
    // 3을 3개의 수로 나타내는 방법은 1가지 (1+1+1)
    dp[3][3] = 1;

    // dp 배열을 채워나갑니다.
    for (int sum = 4; sum <= 1000; sum++) {
        for (int count = 2; count <= sum; count++) {
            // dp[sum][count]는 dp[sum-1][count-1], dp[sum-2][count-1], dp[sum-3][count-1]의 합입니다.
            dp[sum][count] = (dp[sum-1][count-1] % MOD + dp[sum-2][count-1] % MOD + dp[sum-3][count-1] % MOD) % MOD;
        }
    }

    // 결과를 계산합니다.
    ll result = 0;
    for (int i = 1; i <= maxNumbers; i++) {
        // dp[targetSum][i]를 모두 더해줍니다.
        result = (result % MOD + dp[targetSum][i] % MOD) % MOD;
    }

    // 결과를 출력합니다.
    cout << result << '\n';
}