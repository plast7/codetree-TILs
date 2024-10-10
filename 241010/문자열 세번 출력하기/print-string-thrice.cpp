#include <iostream>
using namespace std;

int main() {
    // 문자열을 입력받을 변수를 선언합니다.
    string inputString;
    
    // 사용자로부터 문자열을 입력받습니다.
    cin >> inputString;

    // 입력받은 문자열을 3번 출력하기 위해 반복문을 사용합니다.
    for (int i = 0; i < 3; i++) {
        // 입력받은 문자열을 출력합니다.
        cout << inputString << endl;
    }

    // 프로그램이 정상적으로 종료되었음을 알립니다.
    return 0;
}