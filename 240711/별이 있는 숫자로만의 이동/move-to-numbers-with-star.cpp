#include <iostream>

#define MAX_N 400

using namespace std;

// 변수 선언
int n, k;
int board[MAX_N + 1][MAX_N + 1];
int board2[MAX_N * 2 + 1][MAX_N * 2 + 1];
int s[MAX_N * 2 + 1][MAX_N * 2 + 1];
int ans = 0;

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> board[i][j];
    
    // 2차원 배열을 45도 회전시킵니다.
    // 배열을 회전시키면 정사각형 부분합을 구하는 문제로
    // 바뀌기 때문에 훨씬 접근하기 쉬워집니다.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			board2[i + j - 1][n - i + j] = board[i][j];
		}
	}

    // 2차원 배열의 누적합을 구합니다.
    for(int i = 1; i <= 2 * n; i++)
        for(int j = 1; j <= 2 * n; j++)
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + board2[i][j];

    // 한 변의 길이가 k2인 정사각형 중 부분합이 최대인 사각형을 찾습니다.
    int k2 = min(2 * k + 1, 2 * n);
    for(int i = k2; i <= 2 * n; i++)
        for(int j = k2; j <= 2 * n; j++) {
            if(board2[i - k2 + 1][j - k2 + 1])
                ans = max(ans, s[i][j] - s[i][j - k2] - s[i - k2][j] + s[i - k2][j - k2]);
    }
    
    // 정답을 출력합니다.
    cout << ans;
}