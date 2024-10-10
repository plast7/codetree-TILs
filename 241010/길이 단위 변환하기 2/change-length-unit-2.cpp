#include <iostream>

using namespace std;

int main() {
    // 1야드를 cm로 변환하는 상수입니다.
    const double YARD_TO_CM = 91.44;
    // 1마일을 cm로 변환하는 상수입니다.
    const double MILE_TO_CM = 160934;

    // 변환할 야드와 마일 값을 정의합니다.
    double yards = 6.8;
    double miles = 0.4;

    // 소수 첫째 자리까지 반올림하여 출력하기 위해 설정합니다.
    cout << fixed;
    cout.precision(1);

    // 야드를 cm로 변환하여 출력합니다.
    cout << yards << "yd = " << yards * YARD_TO_CM << "cm" << endl;
    // 마일을 cm로 변환하여 출력합니다.
    cout << miles << "mi = " << miles * MILE_TO_CM << "cm";

    return 0;
}