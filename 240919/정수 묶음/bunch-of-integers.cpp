#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

// 변수 선언
int numIntegers, boxSize;
int prefixSum[50001]; // prefixSum[i]는 1번부터 i번까지의 합을 저장합니다.
int dp[50001][3]; // dp[i][j]는 i번째 정수부터 시작하여 j개의 상자를 채울 때 얻을 수 있는 최대 합을 저장합니다.

// getMaxSum 함수는 index 위치에서 boxCount 개의 상자를 채울 때 얻을 수 있는 최대 합을 반환합니다.
int getMaxSum(int index, int boxCount) {
    // 더 이상 상자를 채울 수 없거나, 모든 상자를 다 채운 경우 0을 반환합니다.
    if (index >= numIntegers || boxCount == 3) return 0;
    // 이미 계산된 값이 있다면 그 값을 반환합니다.
    if (dp[index][boxCount] != -1) return dp[index][boxCount];

    // dp 값을 초기화합니다.
    dp[index][boxCount] = 0;
    // 현재 위치에서 상자를 채울 수 있는 경우와 채우지 않는 경우 중 최대 값을 선택합니다.
    if (index + boxSize - 1 <= numIntegers)
        dp[index][boxCount] = max(getMaxSum(index + 1, boxCount), 
                                  getMaxSum(index + boxSize, boxCount + 1) + prefixSum[index + boxSize - 1] - prefixSum[index - 1]);

    return dp[index][boxCount];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 입력:
    cin >> numIntegers;
    for (int temp, i = 1; i <= numIntegers; i++) {
        cin >> temp;
        prefixSum[i] = prefixSum[i - 1] + temp; // prefixSum 배열을 채웁니다.
    }
    
    cin >> boxSize;

    // dp 배열을 -1로 초기화합니다.
    memset(dp, -1, sizeof(dp));
    // getMaxSum 함수를 호출하여 결과를 출력합니다.
    cout << getMaxSum(1, 0);
}