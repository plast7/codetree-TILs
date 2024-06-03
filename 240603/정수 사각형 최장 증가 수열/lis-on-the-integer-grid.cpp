#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

#define MAX_N 500
#define DIR_NUM 4

using namespace std;

// 변수 선언
int n;
int grid[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

// (x, y)에서 출발하여 조건을 만족하며
// 도달할 수 있는 칸의 수 중
// 최대 칸의 수를 구합니다.
int FindMax(int x, int y) {
    // 이미 계산해본적이 있다면
    // 그 값을 바로 반환합니다.
    if(dp[x][y] != -1)
        return dp[x][y];

    // 기본값은 자기자신이 됩니다.
    int best = 1;

    // 정수값이 작은 칸부터 순서대로 보며
    // 4방향에 대해 최적의 칸 수를 계산합니다.
    int dx[DIR_NUM] = {-1, 1,  0, 0};
    int dy[DIR_NUM] = { 0, 0, -1, 1};

    for(int j = 0; j < DIR_NUM; j++) {
        int nx = x + dx[j], ny = y + dy[j];
        if(InRange(nx, ny) && grid[nx][ny] > grid[x][y])
            best = max(best, FindMax(nx, ny) + 1);
    }

    return dp[x][y] = best;
}

int main() {
    // 입력
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    // 메모이제이션을 위해 
    // 전부 초기값을 -1로 셋팅해줍니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = -1;

    // 각 칸에 시작했을 떄
    // 최대로 이동할 수 있는 칸의 수 중 
    // 최댓값을 갱신합니다.
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans = max(ans, FindMax(i, j));
    
    cout << ans;
    return 0;
}