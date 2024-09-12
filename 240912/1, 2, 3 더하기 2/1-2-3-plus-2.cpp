#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long ll;

// MOD 값을 정의합니다. 이는 결과를 1,000,000,007로 나누기 위함입니다.
const int MOD = 1e9 + 7;
// 최대 n의 값을 정의합니다.
const int MAX_N = 100000;
// DP 배열을 정의합니다. DP[n][k]는 n을 1, 2, 3의 합으로 나타내는 방법 중 마지막에 k를 사용한 경우의 수를 의미합니다.
ll DP[MAX_N + 1][4];

// DP 배열을 미리 계산해주는 함수입니다.
void calculateDP() {
    // 초기값을 설정합니다.
    DP[1][1] = DP[2][2] = DP[3][1] = DP[3][2] = DP[3][3] = 1;
    
    // 4부터 MAX_N까지 DP 배열을 채워줍니다.
    for (int n = 4; n <= MAX_N; n++) {
        // n-1에서 끝나는 경우, 마지막에 1을 더한 경우를 계산합니다.
        if (n - 1 >= 0) {
            DP[n][1] = (DP[n - 1][2] + DP[n - 1][3]) % MOD;
        }
        // n-2에서 끝나는 경우, 마지막에 2를 더한 경우를 계산합니다.
        if (n - 2 >= 0) {
            DP[n][2] = (DP[n - 2][1] + DP[n - 2][3]) % MOD;
        }
        // n-3에서 끝나는 경우, 마지막에 3을 더한 경우를 계산합니다.
        if (n - 3 >= 0) {
            DP[n][3] = (DP[n - 3][1] + DP[n - 3][2]) % MOD;
        }
    }
}

int main() {
    // DP 배열을 미리 계산합니다.
    calculateDP();
    
    int n;
    // 사용자로부터 n을 입력받습니다.
    scanf("%d", &n);
    
    // n을 1, 2, 3의 합으로 나타내는 방법의 수를 계산합니다.
    // 이는 DP[n][1], DP[n][2], DP[n][3]의 합입니다.
    printf("%d\n", (DP[n][1] + DP[n][2] + DP[n][3]) % MOD);
    
    return 0;
}