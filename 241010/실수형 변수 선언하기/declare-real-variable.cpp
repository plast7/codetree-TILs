#include <iostream>

using namespace std;

int main() {
    // 두 개의 실수형 변수를 선언하고 각각 12.3과 70.0을 대입합니다.
    double firstNumber = 12.3;
    double secondNumber = 70.0;
    
    // 두 수의 합을 계산하여 sum 변수에 저장합니다.
    double sum = firstNumber + secondNumber;

    // 소수 둘째 자리까지 고정된 소수점 형식으로 출력하기 위해 설정합니다.
    cout << fixed;
    cout.precision(2);
    
    // 각 숫자를 소수 둘째 자리까지 출력하고, 숫자 사이에 5개의 공백을 둡니다.
    cout << firstNumber << "     " << secondNumber << "     " << sum;

    return 0; // 프로그램이 정상적으로 종료되었음을 알립니다.
}