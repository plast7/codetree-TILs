#include <iostream>

using namespace std;

int main() {
    // 변환할 마일과 피트 값을 정의합니다.
    double miles = 2.80;
    double feet = 128.40;

    // 마일과 피트를 센티미터로 변환하기 위한 상수를 정의합니다.
    double miles_to_cm = 160934.40; // 1마일은 160934.40cm입니다.
    double feet_to_cm = 30.48;      // 1피트는 30.48cm입니다.
    
    // 소수점 둘째 자리까지 출력하기 위해 설정합니다.
    cout << fixed << setprecision(2);

    // 마일을 센티미터로 변환하여 출력합니다.
    cout << miles << " mi = " << miles * miles_to_cm << endl;
    // 피트를 센티미터로 변환하여 출력합니다.
    cout << feet << " ft = " << feet * feet_to_cm;

    return 0;
}