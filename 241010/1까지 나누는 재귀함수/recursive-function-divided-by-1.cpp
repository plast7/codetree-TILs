#include <iostream>
using namespace std;

// 주어진 숫자를 1까지 나누는 재귀함수입니다.
void printDividedSequence(int number) {
    // 현재 숫자를 출력합니다.
    cout << number << " ";
    
    // 숫자가 1이 되면 재귀를 종료합니다.
    if (number == 1) {
        return;
    }
    
    // 숫자가 짝수인 경우 2로 나누어 재귀 호출합니다.
    if (number % 2 == 0) {
        printDividedSequence(number / 2);
    } 
    // 숫자가 홀수인 경우 3으로 나누어 재귀 호출합니다.
    else {
        printDividedSequence(number / 3);
    }
}

int main() {
    int inputNumber;
    // 사용자로부터 숫자를 입력받습니다.
    cin >> inputNumber;
    // 입력받은 숫자를 1까지 나누는 과정을 출력합니다.
    printDividedSequence(inputNumber);
}