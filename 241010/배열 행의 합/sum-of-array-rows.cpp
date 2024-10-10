#include <iostream>
using namespace std;

int main() {
    // 5행 4열의 배열을 선언합니다.
    int array[5][4];

    // 배열의 요소를 입력받습니다.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            // 각 요소를 입력받아 배열에 저장합니다.
            cin >> array[i][j];
        }
    }

    // 각 행의 합을 계산하고 출력합니다.
    for (int i = 0; i < 5; i++) {
        // 현재 행의 합을 저장할 변수를 초기화합니다.
        int rowSum = 0;
        for (int j = 0; j < 4; j++) {
            // 현재 행의 모든 요소를 더하여 rowSum에 저장합니다.
            rowSum += array[i][j];
        }
        // 현재 행의 합을 출력합니다.
        cout << rowSum << endl;
    }

    return 0;
}