#include <iostream>
#include <algorithm>

#define MAX_N 15
#define MAX_M 15
#define MAX_P 105

using namespace std;

// 전역 변수 선언
int n, m, k;
int grid[MAX_N][MAX_M];

// dp[i][j][l] : i번째 행까지 확인했을 때, 
//               i번째 행에서 선택한 비트마스크가 j이고,
//               총 선택한 칸의 수가 l일 때, 선택된 칸들의 합의 최대값
int dp[MAX_N][1 << 15][MAX_P];

int main() {
    // 입력을 받습니다.
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // dp 배열을 초기화합니다.
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < (1 << m); j++) {
            for(int l = 0; l <= k; l++) {
                dp[i][j][l] = -(int)1e9;
            }
        }
    }

    // 초기 상태 설정
    dp[0][0][0] = 0;

    // 동적 계획법을 통해 최대 값을 구합니다.
    for(int i = 0; i < n; i++) {
        for(int prevMask = 0; prevMask < (1 << m); prevMask++) {
            for(int currMask = 0; currMask < (1 << m); currMask++) {
                // 이전 상태와 현재 상태가 겹치는 경우를 제외합니다.
                if((prevMask & currMask) != 0)
                    continue;

                // 현재 상태에서 인접한 두 칸이 동시에 선택된 경우를 제외합니다.
                bool isValid = true;
                for(int l = 0; l < m - 1; l++) {
                    if(((currMask >> l) & 1) && ((currMask >> (l + 1)) & 1)) {
                        isValid = false;
                        break;
                    }
                }

                // 유효하지 않은 경우를 제외합니다.
                if(!isValid)
                    continue;

                // 점수 및 선택한 칸의 수를 계산합니다.
                int score = 0, count = 0;
                for(int l = 0; l < m; l++) {
                    if((currMask >> l) & 1) {
                        score += grid[i][l];
                        count++;
                    }
                }

                // dp 배열을 갱신합니다.
                for(int l = 0; l <= k - count; l++) {
                    dp[i + 1][currMask][l + count] = max(dp[i + 1][currMask][l + count], 
                                                         dp[i][prevMask][l] + score);
                }
            }
        }
    }

    // 최종 결과를 계산합니다.
    int maxSum = 0;
    for(int mask = 0; mask < (1 << m); mask++) {
        for(int l = 0; l <= k; l++) {
            maxSum = max(maxSum, dp[n][mask][l]);
        }
    }

    // 결과를 출력합니다.
    cout << maxSum;
    return 0;
}