#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // 사용자로부터 n을 입력받습니다.

    int current_number = 9;  // 시작 숫자는 9로 설정합니다.

    // n번 반복하여 각 줄을 출력합니다.
    for (int i = 0; i < n; i++) {
        int number_to_print = current_number;  // 현재 줄에서 출력할 숫자를 설정합니다.
        
        // 각 줄에서 n개의 숫자를 출력합니다.
        for (int j = 0; j < n; j++) {
            cout << number_to_print << " ";  // 현재 숫자를 출력합니다.
            number_to_print -= 2;  // 숫자를 2 감소시킵니다.
            
            // 숫자가 1보다 작아지면 9로 다시 설정합니다.
            if (number_to_print < 1) {
                number_to_print = 9;
            }
        }
        
        cout << endl;  // 한 줄의 숫자 출력을 마치고 줄바꿈을 합니다.
        
        current_number -= 2;  // 다음 줄의 시작 숫자를 2 감소시킵니다.
        
        // 시작 숫자가 1보다 작아지면 9로 다시 설정합니다.
        if (current_number < 1) {
            current_number = 9;
        }
    }

    return 0;  // 프로그램을 종료합니다.
}