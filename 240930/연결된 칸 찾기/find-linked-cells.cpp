#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 26

int n, cnt;

int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N] = {0,};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<int> result;

// 주어진 좌표를 시작으로 DFS를 수행하여 연결된 구역의 크기를 계산합니다.
void dfs(int x,int y) {
    visited[x][y]=true;
    cnt++;

    // 상하좌우로 이동하며 연결된 구역을 찾습니다.
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && 0 <= ny && nx < n && ny < n && !visited[nx][ny] && arr[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n;

    // 배열을 입력받습니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    // 모든 구역에 대해 DFS를 수행합니다.
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == 1 && !visited[i][j]) {
                cnt = 0;
                dfs(i, j);
                result.push_back(cnt);
            }
        }
    }

    // 결과를 정렬하고 출력합니다.
    sort(result.begin(), result.end());
    
    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }
}