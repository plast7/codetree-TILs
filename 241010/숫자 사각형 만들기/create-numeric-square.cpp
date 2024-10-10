#include <iostream>
using namespace std;

int main() {
    int grid_size;
    cin >> grid_size; // 격자의 크기를 입력받습니다.

    int start_value = 9; // 좌측 상단의 시작 숫자는 항상 9입니다.

    // 각 행을 순회합니다.
    for (int row = 0; row < grid_size; row++) {
        // 각 열을 순회합니다.
        for (int col = 0; col < grid_size; col++) {
            // 현재 위치에 들어갈 숫자를 계산합니다.
            // 시작 숫자에서 열의 인덱스를 뺀 값이 1보다 작으면 1을 출력합니다.
            cout << max(1, start_value - col) << " ";
        }
        // 한 행이 끝나면 줄바꿈을 합니다.
        cout << endl;
        // 다음 행의 시작 숫자는 이전 행의 시작 숫자보다 1 작습니다.
        start_value--;
    }
}