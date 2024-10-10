#include <iostream>

using namespace std;

int main() {
    // 정수 a를 입력받습니다.
    int upper_limit;
    cin >> upper_limit;

    // 현재 숫자를 1로 초기화합니다.
    int current_number = 1;
    // 합계를 저장할 변수를 0으로 초기화합니다.
    int sum = 0;

    // while문을 사용하여 1부터 a까지의 합을 구합니다.
    while (current_number <= upper_limit) {
        // 현재 숫자를 합계에 더합니다.
        sum += current_number;
        // 다음 숫자로 넘어갑니다.
        current_number++;
    }

    // 최종적으로 구한 합계를 출력합니다.
    cout << sum;
}