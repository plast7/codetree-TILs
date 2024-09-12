#include <iostream>
using namespace std;

int main() {
    int rows, cols, waypoint, waypointRow, waypointCol;
    cin >> rows >> cols >> waypoint;

    // dp 배열을 선언하고 초기화합니다.
    long long dp[16][16] = {0};
    dp[1][1] = 1;

    // (1,1)에서 (rows,cols)까지의 경로 수를 계산합니다.
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (i == 1 && j == 1) continue; // 시작점은 이미 초기화되어 있으므로 건너뜁니다.
            dp[i][j] = dp[i-1][j] + dp[i][j-1]; // 위쪽과 왼쪽에서 오는 경로의 합을 저장합니다.
        }
    }

    if (waypoint != 0) {
        // 경유지의 좌표를 계산합니다.
        if (waypoint % cols != 0) {
            waypointCol = waypoint % cols;
            waypointRow = (waypoint - waypointCol) / cols + 1;
        } else {
            waypointRow = waypoint / cols;
            waypointCol = cols;
        }
    }

    if (waypoint == 0) {
        // 경유지가 없는 경우, (1,1)에서 (rows,cols)까지의 경로 수를 출력합니다.
        cout << dp[rows][cols];
    } else {
        // 경유지가 있는 경우, (1,1)에서 경유지까지의 경로 수와 경유지에서 (rows,cols)까지의 경로 수를 곱하여 출력합니다.
        // 경유지에서 (rows,cols)까지의 경로 수를 계산하기 위해 dp 배열을 다시 초기화합니다.
        long long dp2[16][16] = {0};
        dp2[waypointRow][waypointCol] = 1;

        for (int i = waypointRow; i <= rows; i++) {
            for (int j = waypointCol; j <= cols; j++) {
                if (i == waypointRow && j == waypointCol) continue; // 경유지는 이미 초기화되어 있으므로 건너뜁니다.
                dp2[i][j] = dp2[i-1][j] + dp2[i][j-1]; // 위쪽과 왼쪽에서 오는 경로의 합을 저장합니다.
            }
        }

        // (1,1)에서 경유지까지의 경로 수와 경유지에서 (rows,cols)까지의 경로 수를 곱하여 출력합니다.
        cout << dp[waypointRow][waypointCol] * dp2[rows][cols];
    }

    return 0;
}