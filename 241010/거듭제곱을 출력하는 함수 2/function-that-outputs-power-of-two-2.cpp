#include <iostream>
#include <cmath>

using namespace std;

// 재귀함수를 이용하여 base^exponent를 계산하는 함수입니다.
int power(int base, int exponent) {
    // 지수가 0이면 결과는 1입니다.
    if (exponent == 0) return 1;
    // base를 exponent번 곱한 결과를 반환합니다.
    return base * power(base, exponent - 1);
}

// 두 수의 거듭제곱을 계산하고 차이를 출력하는 함수입니다.
void printDifference(int base1, int base2) {
    // base1^base2를 계산합니다.
    int result1 = power(base1, base2);
    // base2^base1을 계산합니다.
    int result2 = power(base2, base1);
    // 두 결과의 차이를 절대값으로 출력합니다.
    cout << abs(result1 - result2);
}

int main() {
    int num1, num2;
    // 두 정수를 입력받습니다.
    cin >> num1 >> num2;
    // 입력받은 두 정수를 이용하여 차이를 출력합니다.
    printDifference(num1, num2);
}