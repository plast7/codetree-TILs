#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// 정수 부분을 주어진 진법으로 변환하여 출력하는 함수입니다.
void printIntegerPart(int integerPart, int base) {
    // 정수 부분이 0인 경우 바로 0을 출력합니다.
    if (integerPart == 0) {
        cout << "0";
        return;
    }

    // 변환된 결과를 저장할 문자열입니다.
    string result;
    // 정수 부분을 주어진 진법으로 변환합니다.
    while (integerPart > 0) {
        // 현재 자리의 값을 계산하여 문자열 앞에 추가합니다.
        result = char('0' + (integerPart % base)) + result;
        // 다음 자리로 이동하기 위해 정수 부분을 base로 나눕니다.
        integerPart /= base;
    }

    // 변환된 결과를 출력합니다.
    cout << result;
}

int main() {
    // 입력을 받을 문자열입니다.
    string input;
    cin >> input;

    // 소수점 위치를 찾습니다.
    size_t dotPosition = input.find('.');
    // 정수 부분을 추출하여 정수로 변환합니다.
    int integerPart = stoi(input.substr(0, dotPosition));
    // 소수 부분을 문자열로 추출합니다.
    string fractionalPartStr = input.substr(dotPosition + 1);

    // 정수 부분을 이진법으로 변환하여 출력합니다.
    printIntegerPart(integerPart, 2);
    cout << ".";

    // 소수 부분을 실수로 변환합니다.
    double fractionalPart = stod("0." + fractionalPartStr);
    // 소수 부분을 이진법으로 변환하여 4자리까지 출력합니다.
    for (int i = 0; i < 4; ++i) {
        // 소수 부분에 2를 곱합니다.
        fractionalPart *= 2;
        // 정수 부분을 추출하여 비트로 사용합니다.
        int bit = static_cast<int>(fractionalPart);
        cout << bit;
        // 정수 부분을 제거하여 다음 자리 계산을 준비합니다.
        fractionalPart -= bit;
    }

    return 0;
}