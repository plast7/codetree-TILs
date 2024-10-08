#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 502

int n, m;
// flip_count 배열은 각 위치에서 중력 방향을 뒤집은 횟수를 저장합니다.
int flip_count[MAX][MAX];
string grid[MAX];

// 위치를 나타내는 구조체입니다.
struct Position {
    int row, col;
};

// 우선순위 큐에서 사용할 비교 기준입니다.
// 중력 방향을 뒤집은 횟수가 적은 것을 우선으로 합니다.
bool operator<(Position a, Position b) {
    return flip_count[a.row][a.col] > flip_count[b.row][b.col];
}

priority_queue<Position> pq;

// 주어진 방향으로 떨어지는 동작을 시뮬레이션합니다. dir={-1:위로,1:아래로}
Position fall(Position pos, int dir) {
    while (true) {
        // D에 도착하면 멈춥니다.
        if (grid[pos.row][pos.col] == 'D') break;
        // 범위를 벗어나면 실패로 간주합니다.
        if (pos.row + dir < 0 || pos.row + dir >= n) return {-1, -1};
        // 장애물이 있으면 멈춥니다.
        if (grid[pos.row + dir][pos.col] == '#') break;
        // 중력 방향으로 한 칸 이동합니다.
        pos.row += dir;
    }
    return pos;
}

// 주어진 방향으로 move={-1:왼쪽,0:중력 뒤집기,1:오른쪽} 동작을 수행합니다. dir={-1:위로,1:아래로}
Position performAction(Position pos, int move, int dir) {
    // 좌우로 이동하는 경우
    if (move) {
        pos.col += move;
        // 범위를 벗어나거나 장애물이 있으면 실패로 간주합니다.
        if (pos.col < 0 || pos.col >= m || grid[pos.row][pos.col] == '#') return {-1, -1};
    } else {
        // 중력 방향을 뒤집습니다.
        dir = -dir;
    }
    // 중력에 따라 떨어지는 동작을 수행합니다.
    return fall(pos, dir);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    
    Position start, destination;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            // C의 시작 위치를 찾고, 중력에 따라 떨어뜨립니다.
            if (grid[i][j] == 'C') start = fall({i, j}, 1);
            // D의 위치를 저장합니다.
            else if (grid[i][j] == 'D') destination = {i, j};
        }

    // 시작 위치가 유효한 경우 탐색을 시작합니다.
    if (start.row >= 0) {
        pq.push(start);
        flip_count[start.row][start.col] = 1;
        while (!pq.empty()) {
            Position current = pq.top();
            pq.pop();
            // D에 도착하면 탐색을 종료합니다.
            if (current.row == destination.row && current.col == destination.col) break;

            // 가능한 이동을 우선순위 큐에 추가합니다.
            for (int move = -1, dir = flip_count[current.row][current.col] % 2 ? 1 : -1; move <= 1; move++) {
                Position next = performAction(current, move, dir);
                // 유효한 위치이고 아직 방문하지 않은 경우
                if (next.row != -1 && !flip_count[next.row][next.col]) {
                    flip_count[next.row][next.col] = flip_count[current.row][current.col];
                    // 중력 방향을 뒤집은 경우 횟수를 증가시킵니다.
                    if (!move) flip_count[next.row][next.col]++;
                    pq.push(next);
                }
            }
        }
    }

    // D에 도착할 수 있는 경우 중력 방향을 뒤집은 횟수를 출력합니다.
    // 도착할 수 없는 경우 -1을 출력합니다.
    cout << flip_count[destination.row][destination.col] - 1 << endl;
}