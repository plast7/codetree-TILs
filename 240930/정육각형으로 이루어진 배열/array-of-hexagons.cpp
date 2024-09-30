#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

const int MAX_SIZE = 101;
const int INF = 1e9 + 7;
typedef pair<int, int> pii;

int width, height;
int hexagonMap[MAX_SIZE][MAX_SIZE];

// 홀수 행과 짝수 행에 대한 이동 방향을 정의합니다.
int odd_dx[6] = {1, 1, 1, 0, -1, 0};
int odd_dy[6] = {-1, 0, 1, 1, 0, -1};
int even_dx[6] = {0, 1, 0, -1, -1, -1};
int even_dy[6] = {-1, 0, 1, 1, 0, -1};

// 입력을 받는 함수입니다.
void input() {
    cin >> height >> width;
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            cin >> hexagonMap[j][i];
        }
    }
}

// 외부 공간을 표시하는 함수입니다.
void markExternalSpaces(pii start) {
    queue<pii> que;
    que.push(start);
    
    bool visited[MAX_SIZE][MAX_SIZE];
    memset(visited, 0, sizeof(visited));
    visited[start.first][start.second] = true;
    
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        hexagonMap[x][y] = 2;
        
        for (int i = 0; i < 6; i++) {
            int nx = x + (y % 2 ? odd_dx[i] : even_dx[i]);
            int ny = y + (y % 2 ? odd_dy[i] : even_dy[i]);
            
            if (nx < 1 || nx > width || ny < 1 || ny > height || visited[nx][ny] || hexagonMap[nx][ny] == 1) continue;
            
            visited[nx][ny] = true;
            que.push({nx, ny});
        }
    }
}

// 방문 여부를 기록하는 배열입니다.
bool visited[MAX_SIZE][MAX_SIZE];

// 둘레를 계산하는 함수입니다.
int calculatePerimeter(pii start) {
    int perimeter = 0;
    
    queue<pii> que;
    que.push(start);
    
    visited[start.first][start.second] = true;
    
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for (int i = 0; i < 6; i++) {
            int nx = x + (y % 2 ? odd_dx[i] : even_dx[i]);
            int ny = y + (y % 2 ? odd_dy[i] : even_dy[i]);
        
            if (visited[nx][ny]) continue;
            if (nx < 1 || nx > width || ny < 1 || ny > height || hexagonMap[nx][ny] == 2) {
                perimeter++;
                continue;
            }
            if (hexagonMap[nx][ny] == 0) continue;
            
            visited[nx][ny] = true;
            que.push({nx, ny});
        }
    }
    
    return perimeter;
}

// 문제를 해결하는 함수입니다.
void solve() {
    // 외부 공간을 표시합니다.
    for (int i = 1; i <= width; i++) {
        for (int j = 1; j <= height; j++) {
            if (hexagonMap[i][j] == 1) continue;
            if (i == 1 || j == 1 || i == width || j == height) {
                markExternalSpaces({i, j});
            }
        }
    }
    
    // 1로 이루어진 집합의 둘레를 계산합니다.
    int totalPerimeter = 0;
    
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= width; i++) {
        for (int j = 1; j <= height; j++) {
            if (hexagonMap[i][j] == 0 || hexagonMap[i][j] == 2 || visited[i][j]) continue;
            totalPerimeter += calculatePerimeter({i, j});
        }
    }
    cout << totalPerimeter;
}

int main() {
    fastio
    input();
    solve();
    
    return 0;
}