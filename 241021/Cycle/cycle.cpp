#include <iostream>

using namespace std;

// 나머지의 위치를 저장할 배열을 선언합니다.
// 초기값은 0으로 설정합니다.
int remainder_position[1005];

int main() {
    // 초기 숫자와 나눌 수를 입력받습니다.
    int initial_number, divisor;
    cin >> initial_number >> divisor;

    // 초기 숫자의 위치를 1로 설정합니다.
    remainder_position[initial_number] = 1;

    // 현재 값을 초기 숫자로 설정합니다.
    int current_value = initial_number;

    // 무한 루프를 돌며 사이클을 찾습니다.
    for (int step = 2;; step++) {
        // 현재 값을 초기 숫자와 곱하고 나눗셈의 나머지를 구합니다.
        current_value = (current_value * initial_number) % divisor;

        // 만약 현재 값이 이미 등장한 적이 있다면 사이클이 시작된 것입니다.
        if (remainder_position[current_value]) {
            // 사이클의 크기를 출력합니다.
            cout << step - remainder_position[current_value] << endl;
            break;
        } else {
            // 현재 값의 위치를 저장합니다.
            remainder_position[current_value] = step;
        }
    }

    return 0;
}