#include <iostream>
#include <string>

using namespace std;

int main() {
    // 두 개의 문자열을 입력받습니다.
    string firstString, secondString;
    cin >> firstString >> secondString;

    // 각 문자열에서 추출한 숫자를 저장할 변수를 초기화합니다.
    int firstNumber = 0, secondNumber = 0;

    // 첫 번째 문자열에서 숫자를 추출합니다.
    for(char ch : firstString) {
        // 문자가 숫자인지 확인합니다.
        if(isdigit(ch)) {
            // 숫자라면, 현재 숫자를 10배하고 새로운 숫자를 더해줍니다.
            firstNumber = firstNumber * 10 + (ch - '0');
        }
    }

    // 두 번째 문자열에서 숫자를 추출합니다.
    for(char ch : secondString) {
        // 문자가 숫자인지 확인합니다.
        if(isdigit(ch)) {
            // 숫자라면, 현재 숫자를 10배하고 새로운 숫자를 더해줍니다.
            secondNumber = secondNumber * 10 + (ch - '0');
        }
    }

    // 두 숫자의 합을 출력합니다.
    cout << firstNumber + secondNumber;
}