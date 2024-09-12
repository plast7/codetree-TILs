#include <iostream>

using namespace std;
#define MOD 10007

// dp[length][digit] : 길이가 length이고 마지막 숫자가 digit인 오름차순 수열의 개수를 저장합니다.
int dp[1001][10] = {0};

int main() {
    int sequence_length;
    cin >> sequence_length;

    // 길이가 1인 수열의 경우, 각 숫자(0~9)로 끝나는 수열은 각각 1개씩 존재합니다.
    for (int digit = 0; digit < 10; digit++) {
        dp[1][digit] = 1;
    }

    // 길이가 2 이상인 수열에 대해 dp 테이블을 채웁니다.
    for (int length = 2; length <= sequence_length; length++) {
        for (int digit = 0; digit < 10; digit++) {
            if (digit == 0) {
                // 마지막 숫자가 0인 경우, 오름차순 수열은 항상 1개입니다.
                dp[length][0] = 1;
            } else {
                // 마지막 숫자가 digit인 경우, 이전 길이의 수열에서 digit 이하의 숫자로 끝나는 모든 수열의 합을 구합니다.
                dp[length][digit] = (dp[length - 1][digit] + dp[length][digit - 1]) % MOD;
            }
        }
    }

    // 주어진 길이의 수열 중 모든 오름차순 수열의 개수를 계산합니다.
    int total_sequences = 0;
    for (int digit = 0; digit < 10; digit++) {
        total_sequences = (total_sequences + dp[sequence_length][digit]) % MOD;
    }

    // 결과를 출력합니다.
    cout << total_sequences;

    return 0;
}