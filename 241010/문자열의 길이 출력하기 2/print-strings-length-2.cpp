#include <iostream>
using namespace std;

int main() {
    // 세 개의 문자열을 입력받기 위한 변수를 선언합니다.
    string firstString, secondString, thirdString;
    
    // 첫 번째 문자열을 입력받습니다.
    cin >> firstString;
    // 두 번째 문자열을 입력받습니다.
    cin >> secondString;
    // 세 번째 문자열을 입력받습니다.
    cin >> thirdString;

    // 각 문자열의 길이를 구한 후, 세 문자열의 길이를 합산합니다.
    int totalLength = firstString.length() + secondString.length() + thirdString.length();
    
    // 세 문자열의 길이의 합을 출력합니다.
    cout << totalLength;
}