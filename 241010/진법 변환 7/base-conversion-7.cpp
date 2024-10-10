#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// 정수 부분을 이진법으로 변환하여 출력하는 함수입니다.
void printIntegerPart(int integerPart, int base) {
    // 정수 부분이 0인 경우, 바로 0을 출력합니다.
    if (integerPart == 0) {
        cout << "0";
        return;
    }

    // 변환 결과를 저장할 문자열입니다.
    string result;
    // 정수 부분을 base(2)로 나누어가며 변환합니다.
    while (integerPart > 0) {
        // 나머지를 구하여 이진법 자릿수를 결정합니다.
        result = char('0' + (integerPart % base)) + result;
        // 정수 부분을 base로 나누어 다음 자릿수를 구합니다.
        integerPart /= base;
    }

    // 변환된 이진법 정수 부분을 출력합니다.
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

    // 소수점 출력
    cout << ".";

    // 소수 부분을 10진수로 변환합니다.
    int fractionalPart = 0;
    for (char digit : fractionalPartStr) {
        fractionalPart = fractionalPart * 10 + (digit - '0');
    }

    // 소수 부분을 이진법으로 변환하여 4자리까지 출력합니다.
    for (int i = 0; i < 4; i++) {
        // 소수 부분에 2를 곱합니다.
        fractionalPart *= 2;
        // 정수 부분을 출력합니다.
        cout << fractionalPart / 100000;
        // 소수 부분만 남깁니다.
        fractionalPart %= 100000;
    }

    return 0;
}