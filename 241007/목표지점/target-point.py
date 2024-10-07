#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 1000

int map[MAX_N][MAX_N];
bool visit[MAX_N][MAX_N];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue<pair<int, int> > q;

int n, m;

// 너비 우선 탐색을 수행하는 함수입니다.
void bfs() {
    // 큐가 빌 때까지 반복합니다.
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 상하좌우를 확인하여 이동합니다.
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 지도 범위 내에 있고 방문하지 않은 곳이라면
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(!visit[nx][ny]) {
                    map[nx][ny] = map[x][y] + 1;
                    visit[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    // 지도의 크기를 입력받습니다.
    cin >> n >> m;

    // 지도 정보를 입력받습니다.
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            cin >> map[x][y];
            if(map[x][y] == 2) {
                // 시작점이면 큐에 삽입하고 방문 처리합니다.
                map[x][y] = 0;
                q.push({x, y});
                visit[x][y] = true;
            } else if(map[x][y] == 0) {
                // 방문할 수 없는 곳이면 방문 처리합니다.
                visit[x][y] = true;
            }
        }
    }

    // 너비 우선 탐색을 시작합니다.
    bfs();

    // 지도를 출력합니다.
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            if(!visit[x][y]) {
                // 도달할 수 없는 곳은 -1로 출력합니다.
                cout << "-1 ";
            } else {
                cout << map[x][y] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}