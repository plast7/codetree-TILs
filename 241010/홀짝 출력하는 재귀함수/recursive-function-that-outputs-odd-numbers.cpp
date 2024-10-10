#include <iostream>
using namespace std;

// 재귀함수를 통해 숫자를 출력하는 함수입니다.
// current는 현재 출력할 숫자, n은 최대 숫자, step은 증가할 간격입니다.
void printNumbers(int current, int n, int step) {
    // 현재 숫자가 n을 초과하면 종료합니다.
    if (current > n) {
        return;
    }
    // 현재 숫자를 출력합니다.
    cout << current << " ";
    // 다음 숫자를 출력하기 위해 재귀 호출을 합니다.
    printNumbers(current + step, n, step);
}

int main() {
    int n;
    // 사용자로부터 정수 n을 입력받습니다.
    cin >> n;

    // n이 짝수인 경우
    if (n % 2 == 0) {
        // 2부터 시작하여 2씩 증가하는 숫자를 출력합니다.
        printNumbers(2, n, 2);
    } else {
        // n이 홀수인 경우
        // 1부터 시작하여 2씩 증가하는 숫자를 출력합니다.
        printNumbers(1, n, 2);
    }

    return 0;
}