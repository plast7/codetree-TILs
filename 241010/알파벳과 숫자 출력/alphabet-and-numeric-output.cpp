#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // n을 입력받습니다.

    // 알파벳과 숫자를 순차적으로 출력하기 위한 카운터를 초기화합니다.
    int alphabetCounter = 0, numberCounter = 1;

    // n개의 행을 출력합니다.
    for (int row = 1; row <= n; row++) {
        // 각 행에서 알파벳을 출력합니다.
        // 첫 번째 열부터 n-row+1 열까지 알파벳을 출력합니다.
        for (int col = 1; col <= n - row + 1; col++) {
            // 현재 알파벳 카운터에 해당하는 알파벳을 출력합니다.
            cout << static_cast<char>('A' + alphabetCounter) << " ";
            alphabetCounter++;  // 다음 알파벳으로 이동합니다.
            if (alphabetCounter == 26) {  // 알파벳이 Z까지 도달하면 A로 돌아갑니다.
                alphabetCounter = 0;
            }
        }
        // 각 행에서 숫자를 출력합니다.
        // n-row+2 열부터 n 열까지 숫자를 출력합니다.
        for (int col = 1; col <= row; col++) {
            // 현재 숫자 카운터에 해당하는 숫자를 출력합니다.
            cout << numberCounter << " ";
            numberCounter++;  // 다음 숫자로 이동합니다.
            if (numberCounter == 10) {  // 숫자가 9까지 도달하면 1로 돌아갑니다.
                numberCounter = 1;
            }
        }
        cout << endl;  // 각 행의 출력이 끝나면 줄바꿈을 합니다.
    }
}