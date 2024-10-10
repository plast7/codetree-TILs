#include <iostream>
using namespace std;

int main() {
    // 두 개의 문자열을 입력받기 위한 변수 선언
    string firstString, secondString;

    // 두 문자열을 공백을 기준으로 입력받습니다.
    cin >> firstString >> secondString;

    // 두 번째 문자열의 앞부분 3개의 문자를 잘라내어 첫 번째 문자열 앞에 이어붙입니다.
    // substr(0, 3)은 두 번째 문자열의 첫 번째 문자부터 시작하여 3개의 문자를 잘라냅니다.
    cout << secondString.substr(0, 3) << firstString;

    // 프로그램이 정상적으로 종료되었음을 알립니다.
    return 0;
}