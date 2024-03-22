#include <iostream>
#include <utility>
#define MAX_N 20
#define DIR_NUM 8
using namespace std;

int n, m;
int grid[MAX_N][MAX_N];
pair<int, int> pos[MAX_N+1];
int count[MAX_N*MAX_N+1];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

void Move(int target) {
    int dx[DIR_NUM] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dy[DIR_NUM] = {1, 1, 0, -1, -1, -1, 0, 1};

    int max_num = 0;
    int x = pos[target].first, y = pos[target].second;
    int ch_x, ch_y;
    for(int i=0; i<DIR_NUM; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if(InRange(nx, ny) && grid[nx][ny] > max_num) {
            max_num = grid[nx][ny];
            ch_x = nx; ch_y = ny;
        }
    }
    
    if(max_num != target) {
        grid[ch_x][ch_y] = grid[x][y];
        grid[x][y] = max_num;

        pos[target] = make_pair(ch_x, ch_y);
        pos[max_num] = make_pair(x, y);
    }

    // cout << target << '\n';
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

}

void Simulate() {
    for(int i=1; i<=n*n; i++) {
        Move(i);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
            pos[grid[i][j]] = make_pair(i, j);
        }
    }

    while(m--) {
        Simulate();
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}