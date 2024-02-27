#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int INF = -1e9;
int n, k;
int a[MAXN];
int dp[MAXN][15];

int main() {
    // n과 k 값을 입력받습니다.
    cin >> n >> k;
    // 보물 지도의 정보를 입력받습니다.
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    // 동적 프로그래밍을 이용해 최대 합을 구합니다.
    // dp[i][j] :: i번째 숫자를 마지막으로, 음수가 j번 나타났을 때 나타나는 연속합 중 최댓값
    int ans = INF;
    for(int i = 1; i <= n; i++) {
        // a[i]가 0 이상인 경우
        if(a[i] >= 0) {
            for(int j = 0; j <= k; j++) {
                dp[i][j] = max(dp[i - 1][j] + a[i], dp[i][j]);
                ans = max(ans, dp[i][j]);
            }
        }
        // a[i]가 음수인 경우
        else {
            // 최대 k개 까지만 음수가 나타날 수 있게 관리합니다.
            for(int j = 1; j <= k; j++) {
                dp[i][j] = max(dp[i - 1][j - 1] + a[i], dp[i][j]);
                ans = max(ans, dp[i][j]);
            }
        }
    }

    // 최종 결과를 출력합니다.
    cout << ans;
}