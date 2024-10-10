#include <iostream>

using namespace std;

int main() {
    // 두 정수를 입력받기 위한 변수 선언
    int firstNumber, secondNumber;
    // 사용자로부터 두 정수를 입력받습니다.
    cin >> firstNumber >> secondNumber;

    // 첫 번째 줄 출력: 두 수가 같으면 1, 다르면 0을 출력합니다.
    if(firstNumber == secondNumber)
        cout << 1 << endl; // 두 수가 같으므로 1을 출력합니다.
    else
        cout << 0 << endl; // 두 수가 다르므로 0을 출력합니다.

    // 두 번째 줄 출력: 두 수가 다르면 1, 같으면 0을 출력합니다.
    if(firstNumber != secondNumber)
        cout << 1; // 두 수가 다르므로 1을 출력합니다.
    else
        cout << 0; // 두 수가 같으므로 0을 출력합니다.

    // 프로그램 종료
    return 0;
}