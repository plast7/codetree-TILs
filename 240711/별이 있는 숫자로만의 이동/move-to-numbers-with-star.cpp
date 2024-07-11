#include <iostream>

#define MAX_N 400

using namespace std;

// 변수 선언
int n, k;
int board[MAX_N + 1][MAX_N + 1];
int board2[MAX_N * 2 + 1][MAX_N * 2 + 1];
int s[MAX_N * 2 + 1][MAX_N * 2 + 1];
int ans = 0;

// 해당 정사각형의 정 가운데 부분이 실제 배열에서 존재하는 지점인지 검사합니다.
bool is_valid(int i, int j) {
    if(!(n + 1 <= i + j <= 3 * n - 1))
        return false;
    if(!(1 - n <= i - j <= n - 1))
        return false;
    if((i + j) % 2 == (n + 1) % 2)
        return true;
    return false;
}

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
            // 정사각형의 중심이 (i, j)일 때 가능한 정사각형인지 확인합니다.
            if(is_valid(i, j)) {
                // 중심으로부터 정사각형의 양 끝 좌표를 구하고, 구간합을 이용해 계산합니다.)
                int ri = min(2 * n, i + k2 / 2);
                int li = max(0, i - k2 / 2 - 1);
                int rj = min(2 * n, j + k2 / 2);
                int lj = max(0, j - k2 / 2 - 1);
                ans = max(ans, s[ri][rj] - s[ri][lj] - s[li][rj] + s[li][lj]);
            }
        }
    
    // 정답을 출력합니다.
    cout << ans;
}