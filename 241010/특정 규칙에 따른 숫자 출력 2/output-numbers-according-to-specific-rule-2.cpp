#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; // 사용자로부터 n을 입력받습니다.

    // n개의 줄을 출력하기 위해 반복문을 사용합니다.
    int current_number = 9;
    for (int row = 0; row < n; row++) {
        // 각 줄에 n개의 숫자를 출력하기 위해 반복문을 사용합니다.
        for (int col = 0; col < n; col++) {
            cout << current_number << " "; // 현재 숫자를 출력합니다.
            
            // 다음 숫자는 현재 숫자에서 2를 뺀 값입니다.
            current_number -= 2;
            
            // 만약 숫자가 1보다 작아지면, 다시 9로 돌아갑니다.
            if (current_number < 1) {
                current_number = 9;
            }
        }
        cout << endl; // 한 줄의 숫자 출력을 마치면 줄바꿈을 합니다.
    }
}