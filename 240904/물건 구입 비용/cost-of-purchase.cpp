#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dp[i]는 i개의 물건을 구매하는데 드는 최소 비용을 저장합니다.
int dp[1001];
const int INF = 987654321;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 필요한 물건의 개수와 상점의 개수를 입력받습니다.
    int required_items, num_shops;
    cin >> required_items >> num_shops;

    // 각 상점의 묶음 크기와 가격 정보를 저장할 벡터를 선언합니다.
    vector<pair<int, int>> shop_info(num_shops);
    for (int i = 0; i < num_shops; i++) {
        int bundle_size, price;
        cin >> bundle_size >> price;
        shop_info[i] = { bundle_size, price };
    }

    // dp 배열을 초기화합니다. 초기에는 모든 값을 무한대로 설정합니다.
    fill(dp, dp + 1001, INF);
    dp[0] = 0; // 0개의 물건을 구매하는데 드는 비용은 0입니다.

    // dp 배열을 갱신합니다.
    // i는 현재까지 구매한 물건의 개수를 나타냅니다.
    for (int i = 0; i <= required_items; i++) {
        // j는 각 상점을 나타냅니다.
        for (int j = 0; j < num_shops; j++) {
            int bundle_size = shop_info[j].first;
            int price = shop_info[j].second;
            // 현재 구매한 물건의 개수에 상점의 묶음 크기를 더한 값이 1000 이하일 때
            if (i + bundle_size <= 1000) {
                // dp[i + bundle_size]를 갱신합니다.
                dp[i + bundle_size] = min(dp[i + bundle_size], dp[i] + price);
            }
        }
    }

    // 최소 비용을 찾습니다.
    int min_cost = INF;
    for (int i = required_items; i <= 1000; i++) {
        min_cost = min(min_cost, dp[i]);
    }

    // 최소 비용을 출력합니다.
    cout << min_cost << "\n";
    return 0;
}