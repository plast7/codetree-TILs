#include <iostream>
#include <cmath>

using namespace std;

// 두 정수 중 절대값이 더 큰 값을 양수로 변환하여 출력하는 함수입니다.
void printLargerAbsoluteValue(int num1, int num2) {
    // num1의 절대값이 num2의 절대값보다 큰 경우
    if (abs(num1) > abs(num2))
        // num1의 절대값을 출력합니다.
        cout << abs(num1) << endl;
    else
        // 그렇지 않으면 num2의 절대값을 출력합니다.
        cout << abs(num2) << endl;
}

int main() {
    int numberOfPairs;
    // 숫자쌍의 개수를 입력받습니다.
    cin >> numberOfPairs;

    // 각 숫자쌍에 대해 절대값이 더 큰 값을 출력합니다.
    for (int i = 0; i < numberOfPairs; i++) {
        int firstNumber, secondNumber;
        // 두 정수를 입력받습니다.
        cin >> firstNumber >> secondNumber;
        // 입력받은 두 정수를 함수에 전달하여 절대값이 더 큰 값을 출력합니다.
        printLargerAbsoluteValue(firstNumber, secondNumber);
    }

    return 0;
}