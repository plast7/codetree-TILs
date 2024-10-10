#include <iostream>
using namespace std;

int main() {
    // 문자열을 입력받기 위한 변수 선언
    string inputString;
    // 문자열 입력 받기
    cin >> inputString;
    
    // 문자열의 길이를 저장
    int length = inputString.length();

    // 문자열의 앞에서부터 3자를 출력합니다.
    // substr(0, 3)은 문자열의 시작 위치에서 3개의 문자를 추출합니다.
    cout << inputString.substr(0, 3) << endl;

    // 문자열의 뒤에서부터 4자를 출력합니다.
    // substr(length - 4, 4)는 문자열의 끝에서 4개의 문자를 추출합니다.
    cout << inputString.substr(length - 4, 4) << endl;

    return 0;
}