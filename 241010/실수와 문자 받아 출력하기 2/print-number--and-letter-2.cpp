#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // 변수 선언
    char character; // 문자를 저장할 변수
    double firstNumber, secondNumber; // 실수를 저장할 변수

    // 입력:
    // 첫 번째 줄에서 문자를 입력받습니다.
    cin >> character;
    // 두 번째 줄에서 첫 번째 실수를 입력받습니다.
    cin >> firstNumber;
    // 세 번째 줄에서 두 번째 실수를 입력받습니다.
    cin >> secondNumber;

    // 실수를 소수점 둘째 자리까지 반올림하여 출력하기 위해
    // fixed와 precision을 사용합니다.
    cout << fixed;
    cout.precision(2);

    // 두 번째 실수를 먼저 출력합니다.
    cout << secondNumber << endl;
    // 첫 번째 실수를 출력합니다.
    cout << firstNumber << endl;
    // 마지막으로 문자를 출력합니다.
    cout << character;

    return 0;
}