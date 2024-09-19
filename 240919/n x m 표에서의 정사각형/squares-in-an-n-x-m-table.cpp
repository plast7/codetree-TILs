#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// 변수 선언
int rows, cols, totalSquares;
int grid[501][501];
int dp[501][501];

void countSquares() {
    // 각 칸을 순회하면서 정사각형의 개수를 세어줍니다.
    for(int r = 1; r <= rows; r++) {
        for(int c = 1; c <= cols; c++) {
            // 현재 칸이 1인 경우에만 정사각형을 만들 수 있습니다.
            if(grid[r][c] == 1) {
                // 현재 칸이 (r, c)일 때, (r-1, c-1), (r, c-1), (r-1, c) 중
                // 최소값에 1을 더한 값이 현재 칸을 오른쪽 아래로 하는 정사각형의 최대 크기입니다.
                if(r >= 2 && c >= 2) {
                    dp[r][c] = min({dp[r-1][c-1], dp[r][c-1], dp[r-1][c]}) + 1;
                }
                // 현재 칸이 첫 번째 행이나 첫 번째 열에 있는 경우, 정사각형의 크기는 1입니다.
                else {
                    dp[r][c] = 1;
                }
            }
            // 현재 칸을 오른쪽 아래로 하는 정사각형의 개수를 더해줍니다.
            totalSquares += dp[r][c];
        }
    }
    // 결과 출력
    cout << totalSquares << "\n";
}

int main() {
    // dp 배열을 0으로 초기화합니다.
    memset(dp, 0, sizeof(dp));
    
    totalSquares = 0;
    // 행과 열의 크기를 입력받습니다.
    cin >> rows >> cols;
    
    // 표의 각 칸의 값을 입력받습니다.
    for(int r = 1; r <= rows; r++) {
        for(int c = 1; c <= cols; c++) {
            cin >> grid[r][c];
            // dp 배열의 초기값을 grid 배열의 값으로 설정합니다.
            dp[r][c] = grid[r][c];
        }
    }
    // 정사각형의 개수를 세는 함수를 호출합니다.
    countSquares();
    
    return 0;
}