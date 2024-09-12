#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10007;

int num_people, max_coins, target_sum;
vector<int> coins[51];
int dp[51][1001] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // 입력을 받습니다.
    cin >> num_people >> max_coins >> target_sum;

    // 각 사람이 가진 동전의 정보를 입력받습니다.
    for (int i = 1; i <= num_people; i++) {
        int num_coins;
        cin >> num_coins;
        for (int j = 0; j < num_coins; j++) {
            int coin_value;
            cin >> coin_value;
            coins[i].push_back(coin_value);
        }
    }
    
    // dp[i][0] = 1로 초기화합니다. 이는 i번째 사람까지 고려했을 때, 합이 0이 되는 경우는 1가지(아무도 동전을 내지 않는 경우)라는 의미입니다.
    for (int i = 0; i <= num_people; i++)
        dp[i][0] = 1;

    // 각 사람을 순차적으로 고려합니다.
    for (int i = 1; i <= num_people; i++) {
        // 각 가능한 합을 순차적으로 고려합니다.
        for (int j = 1; j <= target_sum; j++) {
            // 현재 사람의 동전들을 순차적으로 고려합니다.
            for (int k = 0; k < coins[i].size(); k++) {
                // 현재 동전을 사용했을 때의 경우를 고려합니다.
                if (j >= coins[i][k]) {
                    dp[i][j] += dp[i - 1][j - coins[i][k]];
                    dp[i][j] %= MOD;
                }
            }
            // 현재 사람의 동전을 사용하지 않았을 때의 경우를 고려합니다.
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= MOD;
        }
    }

    // 최종적으로 dp[num_people][target_sum] 값을 출력합니다.
    cout << dp[num_people][target_sum] << endl;

    return 0;
}