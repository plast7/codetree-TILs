#include <iostream>
using namespace std;

// 변수 선언
int n;
int matrix[11][11];

int main() {
    // 입력:
    // n을 입력받고, n*n 크기의 배열을 입력받습니다.
    cin >> n;
    for(int row = 0; row < n; row++)
        for(int col = 0; col < n; col++)
            cin >> matrix[row][col];

    // 모든 홀수 행에 대해 1을 적어줍니다.
    for(int row = 0; row < n; row++) {
        // 행 번호가 짝수인 경우 (0부터 시작하므로 0, 2, 4, ...) 
        // 해당 행의 모든 열에 대해 1을 적어줍니다.
        if(row % 2 == 0) {
            for(int col = 0; col < n; col++)
                matrix[row][col] = 1;
        }
    }

    // 모든 짝수 열에 대해 2를 적어줍니다.
    for(int col = 0; col < n; col++) {
        // 열 번호가 홀수인 경우 (0부터 시작하므로 1, 3, 5, ...)
        // 해당 열의 모든 행에 대해 2를 적어줍니다.
        if(col % 2 == 1) {
            for(int row = 0; row < n; row++)
                matrix[row][col] = 2;
        }
    }

    // 최종 결과를 출력합니다.
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++)
            cout << matrix[row][col] << " ";
        cout << endl;
    }

    return 0;
}