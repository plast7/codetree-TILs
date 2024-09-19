#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 500
#define INF 1e9

using namespace std;

// 변수 선언
int n;
int grid[MAX][MAX];
int dp[MAX][MAX];

// 입력을 받는 함수입니다.
void Input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
}

// 최소 연산 횟수를 계산하는 함수입니다.
void CalculateMinimumOperations() {
    // dp 배열을 초기화합니다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }
    
    // 시작점 (0, 0)의 연산 횟수는 0으로 설정합니다.
    dp[0][0] = 0;

    // 모든 칸을 순회하며 dp 값을 갱신합니다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 현재 칸에서 오른쪽으로 이동할 경우를 계산합니다.
            if (j + 1 < n) {
                int costFromLeft = (grid[i][j + 1] < grid[i][j]) ? 0 : grid[i][j + 1] - grid[i][j] + 1;
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + costFromLeft);
            }
            // 현재 칸에서 아래쪽으로 이동할 경우를 계산합니다.
            if (i + 1 < n) {
                int costFromTop = (grid[i + 1][j] < grid[i][j]) ? 0 : grid[i + 1][j] - grid[i][j] + 1;
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + costFromTop);
            }
        }
    }
}

// 정답을 출력하는 함수입니다.
void FindAnswer() {
    cout << dp[n - 1][n - 1] << "\n";
}

int main() {
    FASTIO
    Input();
    CalculateMinimumOperations();
    FindAnswer();

    return 0;
}