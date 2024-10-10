#include <iostream>
#include <cmath>

using namespace std;

// 두 실수의 제곱근 사이에 있는 정수의 개수를 계산하는 함수입니다.
void countIntegersBetweenSquareRoots(double num1, double num2) {
    // 첫 번째 수의 제곱근을 구하고, 그보다 큰 가장 작은 정수를 찾습니다.
    int lowerBound = ceil(sqrt(num1));
    // 두 번째 수의 제곱근을 구하고, 그보다 작은 가장 큰 정수를 찾습니다.
    int upperBound = floor(sqrt(num2));
    // 두 정수 사이의 개수를 출력합니다.
    cout << upperBound - lowerBound + 1;
}

int main() {
    double firstNumber, secondNumber;
    // 두 실수를 입력받습니다.
    cin >> firstNumber >> secondNumber;

    // 첫 번째 수가 두 번째 수보다 큰 경우, 두 수를 교환합니다.
    if (firstNumber > secondNumber) {
        swap(firstNumber, secondNumber);
    }

    // 두 수의 제곱근 사이에 있는 정수의 개수를 계산합니다.
    countIntegersBetweenSquareRoots(firstNumber, secondNumber);
}