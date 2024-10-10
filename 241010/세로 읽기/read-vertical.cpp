#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char words[5][16]; // 최대 5개의 단어를 저장할 배열을 선언합니다. 각 단어는 최대 15개의 문자로 구성됩니다.

    // 5개의 단어를 입력받습니다.
    for (int i = 0; i < 5; i++) {
        cin >> words[i]; // 각 단어를 배열에 저장합니다.
    }

    // 최대 15개의 열을 순회합니다.
    for (int column = 0; column < 15; column++) {
        // 5개의 행(단어)을 순회합니다.
        for (int row = 0; row < 5; row++) {
            // 현재 문자가 null이 아닌지 확인합니다. (문자열의 끝이 아님을 의미)
            if (words[row][column] != '\0') {
                cout << words[row][column]; // null이 아니라면 해당 문자를 출력합니다.
            }
        }
    }

    return 0;
}