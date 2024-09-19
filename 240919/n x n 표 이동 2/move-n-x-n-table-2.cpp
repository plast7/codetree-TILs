#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 501;
int n, grid[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int max_path_length;
int dy[] = { 0, 0, -1, 1 }, dx[] = { -1, 1, 0, 0 };

// 현재 위치 (y, x)에서 시작하여 이동할 수 있는 최대 경로 길이를 반환하는 함수입니다.
int dfs(int y, int x) {
    // 이미 계산된 경로 길이가 있다면 그 값을 반환합니다.
    if (dp[y][x]) return dp[y][x];
    
    // 현재 위치에서 시작하는 경로 길이는 최소 1입니다.
    dp[y][x] = 1;
    
    // 상하좌우 네 방향으로 이동을 시도합니다.
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        // 이동하려는 위치가 격자 범위 내에 있고, 현재 위치보다 높은 값이 있다면 이동합니다.
        if (ny >= 0 && ny < n && nx >= 0 && nx < n && grid[ny][nx] > grid[y][x]) {
            // 이동한 위치에서의 최대 경로 길이를 계산하여 현재 위치의 경로 길이를 갱신합니다.
            dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
        }
    }
    
    // 현재 위치에서 시작하는 최대 경로 길이를 반환합니다.
    return dp[y][x];
}

int main() {
    // 격자의 크기를 입력받습니다.
    cin >> n;
    
    // 격자의 각 칸에 주어진 정수를 입력받습니다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    // 모든 칸에서 시작하여 이동할 수 있는 최대 경로 길이를 계산합니다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            max_path_length = max(max_path_length, dfs(i, j));
        }
    }
    
    // 이동할 수 있는 최대 경로 길이를 출력합니다.
    cout << max_path_length;
    
    return 0;
}