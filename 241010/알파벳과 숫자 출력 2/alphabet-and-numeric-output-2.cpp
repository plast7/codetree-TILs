#include <iostream>
using namespace std;

int main() {
    // 정수 n을 입력받습니다.
    int n;
    cin >> n;

    // 알파벳과 숫자를 출력하기 위한 카운터를 초기화합니다.
    int alphabetCount = 0;
    int numberCount = 0;

    // n+1개의 줄을 출력하기 위한 반복문입니다.
    for (int i = 0; i <= n; i++) {
        // 각 줄에서 n-i개의 알파벳을 출력합니다.
        for (int j = 0; j < n - i; j++) {
            // 현재 알파벳을 출력합니다.
            cout << (char)('A' + alphabetCount) << " ";
            // 다음 알파벳으로 이동합니다.
            alphabetCount++;
            // 알파벳이 Z를 넘어가면 다시 A로 돌아갑니다.
            if (alphabetCount == 26)
                alphabetCount = 0;
        }
        // 각 줄에서 i개의 숫자를 출력합니다.
        for (int j = 0; j < i; j++) {
            // 현재 숫자를 출력합니다.
            cout << numberCount << " ";
            // 다음 숫자로 이동합니다.
            numberCount++;
            // 숫자가 9를 넘어가면 다시 0으로 돌아갑니다.
            if (numberCount == 10)
                numberCount = 0;
        }
        // 줄바꿈을 합니다.
        cout << endl;
    }
}