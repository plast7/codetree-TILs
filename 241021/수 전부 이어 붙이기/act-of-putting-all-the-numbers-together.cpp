#include <iostream>

using namespace std;

// 각 숫자를 문자열로 저장할 배열을 선언합니다.
int numbers[35];

int main() {
    int numCount;
    cin >> numCount;

    // 모든 숫자를 이어붙인 결과를 저장할 문자열을 선언합니다.
    string concatenatedNumbers;

    // 주어진 n개의 숫자를 입력받고, 이를 이어붙입니다.
    for (int i = 0; i < numCount; i++) {
        cin >> numbers[i];
        // 각 숫자를 문자열로 변환하여 concatenatedNumbers에 추가합니다.
        concatenatedNumbers += numbers[i];
    }

    // 이어붙인 문자열의 총 길이를 계산합니다.
    int totalLength = concatenatedNumbers.length();
    // 이어붙인 문자열을 5개 숫자씩 나누어 출력합니다.
    for (int i = 0; i < totalLength; i++) {
        // 현재 문자를 출력합니다.
        cout << concatenatedNumbers[i];
        // 5번째마다 줄바꿈을 수행합니다.
        if (i % 5 == 4) {
            cout << endl;
        }
    }

    // 마지막 줄이 5개 숫자로 완성되지 않은 경우 줄바꿈을 추가합니다.
    if (totalLength % 5 != 0) {
        cout << endl;
    }

    return 0;
}