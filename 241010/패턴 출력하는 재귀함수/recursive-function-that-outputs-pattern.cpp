#include <iostream>
using namespace std;

// 재귀함수를 통해 홀수만 출력하는 함수입니다.
void printOddNumbers(int current) {
    // 현재 값이 369일 경우, 369를 출력하고 종료합니다.
    if (current == 369) {
        cout << 369 << " ";
        return;
    }
    // 현재 값이 369보다 클 경우, 369까지 감소시키며 홀수를 출력합니다.
    if (current > 369) {
        // 재귀적으로 현재 값에서 2를 뺀 값을 호출하여 감소시킵니다.
        printOddNumbers(current - 2);
        // 재귀 호출이 끝난 후, 현재 값을 출력합니다.
        cout << current << " ";
    } 
    // 현재 값이 369보다 작을 경우, 369까지 증가시키며 홀수를 출력합니다.
    else {
        // 현재 값을 출력하고,
        cout << current << " ";
        // 재귀적으로 현재 값에서 2를 더한 값을 호출하여 증가시킵니다.
        printOddNumbers(current + 2);
    }
}

int main() {
    int n;
    // 사용자로부터 정수 n을 입력받습니다.
    cin >> n;
    // 입력받은 n을 기준으로 홀수를 출력하는 함수를 호출합니다.
    printOddNumbers(n);
}