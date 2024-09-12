#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 입력
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows + 1, vector<int>(cols + 1, 0));
    vector<vector<int>> maxSum(rows + 1, vector<int>(cols + 1, 0));
    
    // 각 칸에 적혀있는 숫자를 입력받습니다.
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            cin >> grid[i][j];
            // 초기값을 매우 작은 값으로 설정합니다.
            maxSum[i][j] = -200000;
        }
    }

    // 시작점의 초기값을 설정합니다.
    maxSum[1][1] = grid[1][1];

    // 문제 해결
    // 각 칸을 순회하며 최대 합을 계산합니다.
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            // 위쪽 칸에서 오는 경우
            if (i != 1)
                maxSum[i][j] = max(maxSum[i][j], grid[i][j] + maxSum[i - 1][j]);
            // 왼쪽 칸에서 오는 경우
            if (j != 1)
                maxSum[i][j] = max(maxSum[i][j], grid[i][j] + maxSum[i][j - 1]);
            // 왼쪽 위 대각선 칸에서 오는 경우
            if (i != 1 && j != 1)
                maxSum[i][j] = max(maxSum[i][j], grid[i][j] + maxSum[i - 1][j - 1]);
        }
    }

    // 최종적으로 오른쪽 최하단 칸의 최대 합을 출력합니다.
    cout << maxSum[rows][cols] << '\n';
}