#include <iostream>
using namespace std;

#define MAX_N 55

int grid[MAX_N][MAX_N];
int T, N, M;

bool exist[MAX_N];
pair <int,int> position[MAX_N * MAX_N + 5];
char direction[MAX_N];

bool inRange(int r, int c) {
    return r > 0 && r <= N && c > 0 && c <= N;
}

void changeDir(int bead_num) {
    switch(direction[bead_num]) {
        case 'U':
            direction[bead_num] = 'D';
            break;
        case 'D':
            direction[bead_num] = 'U';
            break;
        case 'L':
            direction[bead_num] = 'R';
            break;
        case 'R':
            direction[bead_num] = 'L';
            break;
    }
}

void simulate(int bead_num) {
    int r = position[bead_num].first;
    int c = position[bead_num].second;
    int nr = r;
    int nc = c;

    switch(direction[bead_num]) {
        case 'U':
            nr -=  1;
            break;
        case 'D':
            nr += 1;
            break;
        case 'L':
            nc -= 1;
            break;
        case 'R':
            nc += 1;
            break;
    }
    if (!inRange(nr, nc)) {
        changeDir(bead_num);
        grid[r][c] += 1;
    }
    else {
        grid[nr][nc] += 1;
        position[bead_num] = {nr, nc};
    }
}


void removeBead() {
    for (int i = 1; i <= M; i++) {
        if (!exist[i])
            continue;
        
        int r = position[i].first;
        int c = position[i].second;
        if (grid[r][c] > 1)
            exist[i] = false;
    }

    for (int i = 1; i <= M; i++) {
        int r = position[i].first;
        int c = position[i].second;
        grid[r][c] = 0;
    }
}


int main() {
    cin >> T;

    while(T--) {
        cin >> N >> M;
        for (int i = 1; i <= M; i++) {
            int r, c;
            char dir;
            cin >> r >> c >> dir;
            position[i] = {r, c};
            direction[i] = dir;
            exist[i] = true;
        }

        for (int i = 1; i <= 2*N; i++) {
            for (int j = 1; j <= M; j++) {
                if (!exist[j])
                    continue;
                simulate(j);
            }
            removeBead();
        }

        int ans = 0;
        for (int i = 1; i <= M; i++) {
            if (exist[i])
                ans++;
        }

        cout << ans << "\n";
    }
    return 0;
}