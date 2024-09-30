#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 51

// 변수 선언
int n, l, r;
int grid[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// BFS를 통해 연합을 찾고, 연합에 속한 칸들의 좌표와 총합을 구합니다.
void bfs(int start_x, int start_y, vector<pair<int, int>>& union_cells, int& union_sum) {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    union_cells.push_back({start_x, start_y});
    union_sum += grid[start_x][start_y];

    // BFS를 통해 인접한 칸들을 탐색합니다.
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 인접한 칸이 범위 내에 있고, 아직 방문하지 않았으며, 수 차이가 L 이상 R 이하인 경우
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                int diff = abs(grid[nx][ny] - grid[x][y]);
                if (diff >= l && diff <= r) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    union_cells.push_back({nx, ny});
                    union_sum += grid[nx][ny];
                }
            }
        }
    }
}

// 방문 배열을 초기화합니다.
void reset_visited() {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            visited[i][j] = false;
}

int main() {
    // 입력:
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int days = 0;
    bool has_union = true;

    // 더 이상 연합이 생기지 않을 때까지 반복합니다.
    while (has_union) {
        has_union = false;

        // 모든 칸에 대해 BFS를 수행하여 연합을 찾습니다.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    vector<pair<int, int>> union_cells;
                    int union_sum = 0;
                    bfs(i, j, union_cells, union_sum);

                    // 연합이 형성된 경우
                    if (union_cells.size() > 1) {
                        has_union = true;
                        int new_value = union_sum / union_cells.size();
                        // 연합에 속한 모든 칸에 새로운 값을 할당합니다.
                        for (auto cell : union_cells) {
                            grid[cell.first][cell.second] = new_value;
                        }
                    }
                }
            }
        }

        // 연합이 형성된 경우, 분배 횟수를 증가시킵니다.
        if (has_union) days++;
        // 방문 배열을 초기화합니다.
        reset_visited();
    }

    // 결과 출력
    cout << days;
    return 0;
}