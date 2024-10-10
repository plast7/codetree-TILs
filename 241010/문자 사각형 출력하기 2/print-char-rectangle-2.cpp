#include <iostream>

using namespace std;

int main() {
    // 정사각형의 크기를 입력받습니다.
    int size;
    cin >> size;

    // 문자 사각형을 저장할 2차원 배열을 선언합니다.
    char square[101][101];
    // 문자를 순차적으로 증가시키기 위한 카운터를 초기화합니다.
    int charCounter = 0;

    // 각 열에 대해 문자를 채워넣습니다.
    for (int col = 1; col <= size; col++) {
        // 홀수 번째 열의 경우 위에서 아래로 문자를 채웁니다.
        if (col % 2 == 1) {
            for (int row = 1; row <= size; row++) {
                // 현재 문자를 계산하여 배열에 저장합니다.
                square[row][col] = (charCounter++ % 26) + 'A';
            }
        } 
        // 짝수 번째 열의 경우 아래에서 위로 문자를 채웁니다.
        else {
            for (int row = size; row >= 1; row--) {
                // 현재 문자를 계산하여 배열에 저장합니다.
                square[row][col] = (charCounter++ % 26) + 'A';
            }
        }
    }

    // 완성된 문자 사각형을 출력합니다.
    for (int row = 1; row <= size; row++) {
        for (int col = 1; col <= size; col++) {
            // 각 문자를 출력하고, 문자 사이에 공백을 추가합니다.
            cout << square[row][col] << ' ';
        }
        // 각 행의 끝에서 줄바꿈을 합니다.
        cout << endl;
    }

    return 0;
}