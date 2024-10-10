#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// 정수부와 소수부를 저장할 변수 선언
int integerPart, fractionalPart;
// 소수부를 문자열로 저장할 배열
char fractionalString[100];
// 각 자리의 값을 저장할 배열
int digitValue[200];
// 각 자리의 문자를 저장할 배열
char digitChar[200];

// 정수를 이진법으로 변환하여 출력하는 함수
void printIntegerInBinary(int number, int base) {
    // number가 0일 경우 바로 0을 출력하고 종료합니다.
    if (number == 0) {
        cout << "0";
        return;
    }

    // 나머지를 저장할 배열과 인덱스 변수 선언
    int index = 0;
    int remainder[101];

    // number가 0이 될 때까지 나누기를 반복합니다.
    while (number) {
        // 나머지를 저장합니다.
        remainder[index++] = digitChar[number % base];
        // number를 base로 나눕니다.
        number /= base;
    }

    // 나머지를 역순으로 출력하여 이진법으로 변환된 값을 출력합니다.
    for (int i = index - 1; i >= 0; i--) {
        cout << remainder[i];
    }
}

int main() {
    // 숫자와 문자를 매핑하는 배열을 초기화합니다.
    for (int i = '0'; i <= '9'; i++) {
        digitValue[i] = i - '0';
        digitChar[i - '0'] = i;
    }
    for (int i = 'a'; i <= 'z'; i++) {
        digitValue[i] = i - 'a' + 10;
        digitChar[i - 'a' + 10] = i;
    }

    // 10진법과 2진법을 나타내는 변수
    int base = 10;
    int targetBase = 2;

    // 입력을 받아 정수부와 소수부를 분리합니다.
    scanf("%d.%s", &integerPart, fractionalString);

    // 소수부를 정수로 변환합니다.
    for (int i = 0; i < 4; i++) {
        if ('0' <= fractionalString[i] && fractionalString[i] <= '9') {
            fractionalPart = fractionalPart * 10 + fractionalString[i] - '0';
        } else {
            fractionalPart *= 10;
        }
    }

    // 정수부를 이진법으로 변환하여 출력합니다.
    printIntegerInBinary(integerPart, targetBase);

    // 소수부를 이진법으로 변환하여 출력합니다.
    cout << ".";

    // 소수부를 4자리까지 이진법으로 변환합니다.
    for (int i = 0; i < 4; i++) {
        fractionalPart *= 2;
        cout << fractionalPart / 10000;
        fractionalPart %= 10000;
    }

    return 0;
}