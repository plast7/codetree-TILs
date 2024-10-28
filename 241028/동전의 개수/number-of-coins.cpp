#include <iostream>

#define MAX_N 10

using namespace std;

// 변수 선언
int n, k;
int coins[MAX_N];

int ans;

int main() {
    // 입력:
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> coins[i];

    // 큰 동전부터 이용합니다.
    for(int i = n - 1; i >= 0; i--) {
        ans += k / coins[i];
        k %= coins[i];
    }

    cout << ans;
    return 0;
}