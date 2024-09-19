#include <iostream>
using namespace std;

// 변수 선언
int rows = 0, cols = 0, obstacles_count = 0;
int start_x, start_y, end_x, end_y;
// 장애물 정보를 기록하는 배열입니다.
bool obstacles[201][201] = { 0, };
// 경로의 수를 기록하는 배열입니다.
unsigned long long paths[101][101] = { 0, };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 표의 크기를 입력받습니다.
    cin >> rows >> cols;
    // 장애물의 개수를 입력받습니다.
    cin >> obstacles_count;

    // 장애물의 위치를 입력받아 기록합니다.
    for (int i = 0; i < obstacles_count; i++) {
        cin >> start_x >> start_y >> end_x >> end_y;
        // 장애물의 위치를 기록합니다.
        obstacles[start_y + end_y][start_x + end_x] = 1;
    }

    // 시작점의 경로 수는 1로 초기화합니다.
    paths[0][0] = 1;

    // 첫 번째 열의 경로 수를 계산합니다.
    for (int i = 1; i <= cols; i++) {
        // 장애물이 있는 경우 더 이상 진행할 수 없습니다.
        if (obstacles[2 * i - 1][0] == 1)
            break;
        paths[i][0] = 1;
    }

    // 첫 번째 행의 경로 수를 계산합니다.
    for (int i = 1; i <= rows; i++) {
        // 장애물이 있는 경우 더 이상 진행할 수 없습니다.
        if (obstacles[0][2 * i - 1] == 1)
            break;
        paths[0][i] = 1;
    }

    // 나머지 경로 수를 계산합니다.
    for (int i = 1; i <= cols; i++) {
        for (int j = 1; j <= rows; j++) {
            // 위쪽에서 오는 경로가 막혀있지 않은 경우
            if (obstacles[2 * i - 1][2 * j] == 0)
                paths[i][j] += paths[i - 1][j];
            // 왼쪽에서 오는 경로가 막혀있지 않은 경우
            if (obstacles[2 * i][2 * j - 1] == 0)
                paths[i][j] += paths[i][j - 1];
        }
    }

    // (0, 0)에서 (n, m)까지 가는 경우의 수를 출력합니다.
    cout << paths[cols][rows] << endl;
    return 0;
}