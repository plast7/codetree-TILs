#include <iostream>

#define MAX_N 200
#define MAX_K 10

using namespace std;

// 변수 선언
int n;
int arr[MAX_N];

// dp[i][j][k] : [i, j] 구간에 있는 수들을 전부 하나로 합쳤을 때,
//               k를 남기면서 얻을 수 있는 최대 점수를 기록합니다.
int dp[MAX_N][MAX_N][MAX_K + 1];

// pos[i][j][k] : [i, j] 구간에 있는 수들을 전부 하나로 합쳤을 때,
//                k를 남길 수 있는지 여부를 기록합니다.
bool pos[MAX_N][MAX_N][MAX_K + 1];

int main() {
    // 입력:
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // 구간의 크기가 1인 경우 dp 값이 0이며, pos는 true입니다.
    // 구간의 크기가 2인 경우 dp 값이 두 수의 합이며, pos는 true입니다.
    // dp[i][i + 1][abs(arr[i] - arr[i + 1])] = arr[i] + arr[i + 1]
    // 이 초기 조건이 됩니다.
    for (int i = 0; i < n; i++) {
        pos[i][i][arr[i]] = true;
        if (i + 1 != n) {
            dp[i][i + 1][abs(arr[i] - arr[i + 1])] = arr[i] + arr[i + 1];
            pos[i][i + 1][abs(arr[i] - arr[i + 1])] = true;
        }
    }
    
    // dp는 미리 구해져 있는 작은 문제를 가지고 큰 문제를 풀어야 하므로
    // 이러한 유형의 경우 구간을 점점 넓혀가면서 dp 값을 채워야만 합니다. 
    // 따라서 구간의 크기를 3부터 n까지 증가하게 미리 정해줍니다.
    for (int gap = 3; gap <= n; gap++) {
        // 구간의 시작 위치 i를 정해줍니다.
        for (int i = 0; i <= n - gap; i++) {
            // 구간의 크기와 시작 위치가 정해져 있기에
            // 끝 위치는 자동으로 정해집니다.
            int j = i + gap - 1;

            // [i, j]가 되기 위해
            // 최종적으로 합쳐지는 두 수가
            // 각각 [i, k], [k + 1, j]로부터 온 결과들을 바탕으로
            // 가능한 답의 최댓값을 갱신해줍니다.
            for (int k = i; k < j; k++) {
                for (int x = 0; x <= MAX_K; x++) {
                    if (!pos[i][k][x]) continue;
                    for (int y = 0; y <= MAX_K; y++) {
                        if (!pos[k + 1][j][y]) continue;

                        int score = dp[i][k][x] + dp[k + 1][j][y] + x + y;
                        pos[i][j][abs(x - y)] = true;
                        dp[i][j][abs(x - y)] = max(dp[i][j][abs(x - y)], score);
                    }
                }
            }
        }
    }

    // 모든 수를 합치면서 얻는 최대 점수를 출력합니다.
    int ans = 0;
    for (int x = 0; x <= MAX_K; x++)
        ans = max(ans, dp[0][n - 1][x]);
    cout << ans;
    return 0;
}