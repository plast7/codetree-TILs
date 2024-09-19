#include <iostream>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 500
#define INF 1e9

using namespace std;

// n: 표의 크기
int n;
// grid: 표의 각 칸에 적혀있는 정수
int grid[MAX][MAX];
// dp: 각 칸에 도달하기 위해 필요한 최소 연산 횟수를 저장하는 배열
int dp[MAX][MAX];

// 입력을 받는 함수
void Input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
}

// 최소 연산 횟수를 계산하는 함수
void CalculateMinimumOperations() {
    // 표의 각 칸을 순회하면서 dp 값을 갱신합니다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 왼쪽에서 오는 비용과 위쪽에서 오는 비용을 초기화합니다.
            int costFromLeft = INF;
            int costFromTop = INF;

            // 왼쪽에서 오는 경우를 계산합니다.
            if (j > 0) {
                // 현재 칸의 값이 왼쪽 칸의 값보다 작거나 같다면, 
                // 현재 칸의 값을 왼쪽 칸의 값보다 1 크게 만들기 위해 필요한 연산 횟수를 계산합니다.
                costFromLeft = (grid[i][j] <= grid[i][j - 1]) ? grid[i][j - 1] - grid[i][j] + 1 : 0;
            }
            // 위쪽에서 오는 경우를 계산합니다.
            if (i > 0) {
                // 현재 칸의 값이 위쪽 칸의 값보다 작거나 같다면, 
                // 현재 칸의 값을 위쪽 칸의 값보다 1 크게 만들기 위해 필요한 연산 횟수를 계산합니다.
                costFromTop = (grid[i][j] <= grid[i - 1][j]) ? grid[i - 1][j] - grid[i][j] + 1 : 0;
            }

            // 시작점인 경우
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
            } 
            // 첫 번째 행인 경우
            else if (i == 0) {
                dp[i][j] = dp[i][j - 1] + costFromLeft;
            } 
            // 첫 번째 열인 경우
            else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + costFromTop;
            } 
            // 나머지 경우
            else {
                dp[i][j] = min(dp[i][j - 1] + costFromLeft, dp[i - 1][j] + costFromTop);
            }
        }
    }
}

// 정답을 출력하는 함수
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