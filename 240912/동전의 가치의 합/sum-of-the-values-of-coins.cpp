#include <bits/stdc++.h>
using namespace std;

// 최소 동전 개수를 저장할 배열을 선언합니다.
int minCoins[100001];

int main() {
    // 입출력 속도를 높이기 위한 설정입니다.
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    // 지불해야 할 금액을 입력받습니다.
    int amount;
    cin >> amount;
    
    // 기본적인 경우를 초기화합니다.
    minCoins[0] = 0; // 0원을 지불하는 데 필요한 동전의 개수는 0개입니다.
    if (amount >= 1) minCoins[1] = 1; // 1원을 지불하는 데 필요한 동전의 개수는 1개입니다.
    if (amount >= 2) minCoins[2] = 1; // 2원을 지불하는 데 필요한 동전의 개수는 1개입니다.
    if (amount >= 3) minCoins[3] = 2; // 3원을 지불하는 데 필요한 동전의 개수는 2개입니다. (1원 + 2원)
    if (amount >= 4) minCoins[4] = 2; // 4원을 지불하는 데 필요한 동전의 개수는 2개입니다. (2원 + 2원)
    if (amount >= 5) minCoins[5] = 1; // 5원을 지불하는 데 필요한 동전의 개수는 1개입니다.
    if (amount >= 6) minCoins[6] = 2; // 6원을 지불하는 데 필요한 동전의 개수는 2개입니다. (1원 + 5원)
    if (amount >= 7) minCoins[7] = 1; // 7원을 지불하는 데 필요한 동전의 개수는 1개입니다.
    
    // 주어진 금액까지의 최소 동전 개수를 계산합니다.
    for (int i = 8; i <= amount; i++) {
        // i원을 지불하기 위해 필요한 최소 동전 개수를 계산합니다.
        // 1원, 2원, 5원, 7원 동전을 사용했을 때의 최소 동전 개수를 비교합니다.
        minCoins[i] = min({ minCoins[i - 1], minCoins[i - 2], minCoins[i - 5], minCoins[i - 7] }) + 1;
    }
    
    // 주어진 금액을 지불하기 위해 필요한 최소 동전 개수를 출력합니다.
    cout << minCoins[amount];
}