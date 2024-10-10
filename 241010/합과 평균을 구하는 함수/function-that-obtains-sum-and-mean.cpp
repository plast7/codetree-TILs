#include <iostream>
#include <cmath>

using namespace std;

// 이 함수는 세 정수를 입력받아 합과 평균을 출력합니다.
void printSumAndAverage(int num1, int num2, int num3) {
    // 세 정수의 합을 계산합니다.
    int sum = num1 + num2 + num3;
    // 합을 출력합니다.
    cout << sum << endl;
    // 평균을 계산하고 반올림하여 출력합니다.
    cout << round(static_cast<double>(sum) / 3) << endl;
}

int main() {
    // 세 개의 실수를 입력받습니다.
    double input1, input2, input3;
    cin >> input1 >> input2 >> input3;

    // 각 실수를 반올림하여 정수로 변환합니다.
    int rounded1 = round(input1);
    int rounded2 = round(input2);
    int rounded3 = round(input3);

    // 반올림된 정수들을 이용하여 합과 평균을 출력합니다.
    printSumAndAverage(rounded1, rounded2, rounded3);

    return 0;
}