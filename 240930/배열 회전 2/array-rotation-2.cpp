#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 45도 회전을 수행하는 함수
void rotate45Degrees(int n, int d, vector<vector<int>>& matrix) {
    // 회전 횟수를 계산합니다.
    int rotations = abs(d) / 45;
    // 시계 방향인지 반시계 방향인지 확인합니다.
    bool counterClockwise = d < 0;

    // 회전 횟수만큼 반복합니다.
    for (int r = 0; r < rotations; ++r) {
        // 임시 배열을 생성합니다.
        vector<int> temp(n);
        
        if (!counterClockwise) {  // 시계 방향 회전
            // 주 대각선의 값을 임시 배열에 저장합니다.
            for (int i = 0; i < n; ++i) {
                temp[i] = matrix[i][i];
            }
            // 주 대각선의 값을 중앙 열로 이동합니다.
            for (int i = 0; i < n; ++i) {
                swap(temp[i], matrix[i][n / 2]);
            }
            // 중앙 열의 값을 반대 대각선으로 이동합니다.
            for (int i = 0; i < n; ++i) {
                swap(temp[i], matrix[i][n - i - 1]);
            }
            // 반대 대각선의 값을 중앙 행으로 이동합니다.
            for (int i = 0; i < n; ++i) {
                swap(temp[i], matrix[n / 2][n - i - 1]);
            }
            // 중앙 행의 값을 주 대각선으로 이동합니다.
            for (int i = 0; i < n; ++i) {
                matrix[n - i - 1][n - i - 1] = temp[i];
            }
        } else {  // 반시계 방향 회전
            // 주 대각선의 값을 임시 배열에 저장합니다.
            for (int i = 0; i < n; ++i) {
                temp[i] = matrix[i][i];
            }
            // 주 대각선의 값을 중앙 행으로 이동합니다.
            for (int i = 0; i < n; ++i) {
                swap(temp[i], matrix[n / 2][i]);
            }
            // 중앙 행의 값을 반대 대각선으로 이동합니다.
            for (int i = 0; i < n; ++i) {
                swap(temp[i], matrix[n - i - 1][i]);
            }
            // 반대 대각선의 값을 중앙 열로 이동합니다.
            for (int i = 0; i < n; ++i) {
                swap(temp[i], matrix[n - i - 1][n / 2]);
            }
            // 중앙 열의 값을 주 대각선으로 이동합니다.
            for (int i = 0; i < n; ++i) {
                matrix[n - i - 1][n - i - 1] = temp[i];
            }
        }
    }
}

int main() {
    int n, d;
    // 배열의 크기와 회전 각도를 입력받습니다.
    cin >> n >> d;

    // 배열을 입력받습니다.
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // 45도 회전을 수행합니다.
    rotate45Degrees(n, d, matrix);

    // 회전된 배열을 출력합니다.
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}