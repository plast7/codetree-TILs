#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; // 정수 n을 입력받습니다.

    // n x n 크기의 순서쌍을 생성하기 위한 이중 반복문을 시작합니다.
    for (int row = 1; row <= n; row++) {
        // 각 행에 대해 열을 순회합니다.
        for (int col = 1; col <= n; col++) {
            // 각 순서쌍은 (row * row, col * col)의 형태로 출력됩니다.
            cout << "(" << row * row << "," << col * col << ") ";
        }
        // 한 행의 출력이 끝나면 줄바꿈을 합니다.
        cout << endl;
    }
}