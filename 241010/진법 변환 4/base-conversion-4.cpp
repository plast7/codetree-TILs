#include <iostream>
#include <string>

using namespace std;

int main() {
    // 이진수를 문자열로 입력받습니다.
    string binaryString;
    cin >> binaryString;

    // 10진수로 변환된 값을 저장할 변수를 초기화합니다.
    int decimalValue = 0;
    // 이진수의 각 자릿수에 해당하는 값을 계산하기 위한 base를 초기화합니다. (2^0)
    int base = 1;

    // 이진수 문자열의 끝에서부터 시작하여 각 자릿수를 확인합니다.
    for (int i = binaryString.length() - 1; i >= 0; i--) {
        // 현재 자릿수가 '1'이라면, 해당 자릿수의 값을 10진수 값에 더합니다.
        if (binaryString[i] == '1') {
            decimalValue += base;
        }
        // 다음 자릿수로 이동하기 위해 base를 2배로 증가시킵니다.
        base *= 2;
    }

    // 변환된 10진수 값을 출력합니다.
    cout << decimalValue << endl;

    return 0;
}