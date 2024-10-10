#include <iostream>
using namespace std;

// 주어진 정수에 대해 특정 연산을 수행하는 함수입니다.
void processNumber(int number) {
    // 정수가 짝수인 경우
    if (number % 2 == 0)
        // 2로 나누어 출력합니다.
        cout << number / 2 << " ";
    else
        // 정수가 홀수인 경우
        // 3배를 곱한 후 20을 감소시켜 출력합니다.
        cout << number * 3 - 20 << " ";
}

int main() {
    // 세 개의 정수를 입력받습니다.
    int firstNumber, secondNumber, thirdNumber;

    cin >> firstNumber >> secondNumber >> thirdNumber;

    // 각 정수에 대해 processNumber 함수를 호출하여 연산을 수행합니다.
    processNumber(firstNumber);
    processNumber(secondNumber);
    processNumber(thirdNumber);

    return 0;
}