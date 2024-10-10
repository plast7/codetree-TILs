#include <iostream>

using namespace std;

int main() {
    // 높이와 너비를 입력받습니다.
    int height, width;
    cin >> height >> width;

    // 숫자를 저장할 2차원 배열을 선언합니다.
    int numbers[101][101];
    // 현재 숫자를 기록할 변수를 초기화합니다.
    int currentNumber = 0;

    // 열을 기준으로 숫자를 채워나갑니다.
    for (int col = 1; col <= width; col++) {
        // 각 열마다 숫자를 아래로 채워나갑니다.
        for (int row = 1; row <= height; row++) {
            // 현재 숫자를 증가시키고 배열에 저장합니다.
            numbers[row][col] = ++currentNumber;
        }
    }

    // 결과를 출력합니다.
    for (int row = 1; row <= height; row++) {
        for (int col = 1; col <= width; col++) {
            // 각 숫자를 출력하고, 숫자 사이에 공백을 둡니다.
            cout << numbers[row][col] << " ";
        }
        // 각 행의 끝에서는 줄바꿈을 합니다.
        cout << endl;
    }

    return 0;
}