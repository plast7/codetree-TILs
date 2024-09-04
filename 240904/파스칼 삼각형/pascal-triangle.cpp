#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // r, c, w 값을 입력받습니다.
    int row, col, width;
    cin >> row >> col >> width;

    // 파스칼 삼각형을 저장할 2차원 벡터를 선언합니다.
    vector<vector<int>> pascalTriangle(31, vector<int>(31, 0));
    pascalTriangle[1][1] = 1;

    // 파스칼 삼각형을 구성합니다.
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= i; j++) {
            // 삼각형의 양 끝은 항상 1입니다.
            if (j == 1 || j == i) {
                pascalTriangle[i][j] = 1;
            } else {
                // 내부의 수는 바로 왼쪽 위와 오른쪽 위의 수의 합입니다.
                pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
            }
        }
    }

    int sum = 0;
    // 지정된 삼각형 내부의 수들의 합을 계산합니다.
    for (int i = 0; i < width; i++) {
        for (int j = 0; j <= i; j++) {
            sum += pascalTriangle[row + i][col + j];
        }
    }

    // 결과를 출력합니다.
    cout << sum;
    return 0;
}