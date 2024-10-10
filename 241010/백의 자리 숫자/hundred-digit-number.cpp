#include <iostream>
using namespace std;

int main() {
    // 정수의 개수를 저장할 변수입니다.
    int numberOfIntegers;
    // 사용자로부터 정수의 개수를 입력받습니다.
    cin >> numberOfIntegers;

    // 최대 50개의 정수를 저장할 배열입니다.
    int numbers[50];
    // 각 백의 자리 숫자의 개수를 저장할 배열입니다.
    // 인덱스 0부터 9까지 사용합니다.
    int hundredsCount[10] = {0};

    // 주어진 정수들을 입력받습니다.
    for (int i = 0; i < numberOfIntegers; i++) {
        cin >> numbers[i];
    }

    // 각 정수의 백의 자리 숫자를 계산하고, 해당 숫자의 개수를 증가시킵니다.
    for (int i = 0; i < numberOfIntegers; i++) {
        // 백의 자리 숫자를 구하기 위해 100으로 나눕니다.
        int hundredsDigit = numbers[i] / 100;
        // 해당 백의 자리 숫자의 개수를 증가시킵니다.
        hundredsCount[hundredsDigit]++;
    }

    // 백의 자리 숫자가 존재하는 경우, 해당 숫자와 개수를 출력합니다.
    for (int i = 0; i < 10; i++) {
        // 백의 자리 숫자가 하나 이상 존재하는 경우에만 출력합니다.
        if (hundredsCount[i] > 0) {
            cout << i << " - " << hundredsCount[i] << endl;
        }
    }

    return 0;
}