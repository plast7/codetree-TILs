#include <iostream>
using namespace std;
#define MAX_N 100

int n, m, k;
int grid[MAX_N][MAX_N], next_grid[MAX_N][MAX_N];

void Bumb() {
    
    for(int col=0; col<n; col++) {
        int st = 0;
        int cnt = 1;
        for(int row=1; row<n; row++) {
            if(grid[st][col] != grid[row][col]) {
                if(cnt >= m) {
                    for(int i=st; i<st+cnt; i++) {
                        grid[i][col] = 0;
                    }
                }
                cnt = 1;
                st = row;
            } else
                cnt++;
        }

        if(cnt >= m) {
            for(int i=st; i<st+cnt; i++) {
                grid[i][col] = 0;
            }
        }
    }
}

void Gravity() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            next_grid[i][j] = 0;
        }
    }

    for(int j=0; j<n; j++) {
        int cnt = n-1;
        for(int i=n-1; i>=0; i--) {
            if(grid[i][j] != 0) {
                next_grid[cnt--][j] = grid[i][j];
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            grid[i][j] = next_grid[i][j];
        }
    }
}

void Rotate() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            next_grid[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            next_grid[i][j] = grid[n-j-1][i];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            grid[i][j] = next_grid[i][j];
        }
    }
}

void Simulate() {
    Bumb();

    cout << "\n***B.   " << '\n';
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    Gravity();

    // cout << "\n***G.   " << '\n';
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    Rotate();

    // cout << "\n***R.   " << '\n';
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    Gravity();

    cout << "\n***G.   " << '\n';
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >>n>>m>>k;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<k; i++) {
        // cout << i+1;
        Simulate();
    }

    Bumb();

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] != 0) ans++;
        }
    }

    cout << ans;
    return 0;
}