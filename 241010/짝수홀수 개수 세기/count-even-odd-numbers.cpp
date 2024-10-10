#include <iostream>
using namespace std;

int main() {
    // 정수의 개수를 저장할 변수입니다.
    int numberOfIntegers;
    // 사용자로부터 정수의 개수를 입력받습니다.
    cin >> numberOfIntegers;

    // 짝수와 홀수의 개수를 저장할 변수를 초기화합니다.
    int evenCount = 0, oddCount = 0;

    // 주어진 정수의 개수만큼 반복합니다.
    for (int i = 0; i < numberOfIntegers; i++) {
        // 현재 정수를 저장할 변수를 선언합니다.
        int currentNumber;
        // 사용자로부터 정수를 입력받습니다.
        cin >> currentNumber;

        // 입력받은 정수가 0이라면 반복을 종료합니다.
        if (currentNumber == 0) {
            break;
        }

        // 입력받은 정수가 짝수인지 확인합니다.
        if (currentNumber % 2 == 0) {
            // 짝수라면 짝수의 개수를 증가시킵니다.
            evenCount++;
        } else {
            // 홀수라면 홀수의 개수를 증가시킵니다.
            oddCount++;
        }
    }

    // 짝수의 개수를 출력합니다.
    cout << evenCount << endl;
    // 홀수의 개수를 출력합니다.
    cout << oddCount << endl;

    // 프로그램을 종료합니다.
    return 0;
}