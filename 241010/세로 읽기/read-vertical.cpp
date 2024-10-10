#include <iostream>
#include <cstring>

using namespace std;

int main() {
    // 최대 5개의 단어를 저장할 배열을 선언합니다. 각 단어의 최대 길이는 15입니다.
    char words[5][16]; 

    // 5개의 단어를 입력받습니다.
    for (int i = 0; i < 5; i++) {
        cin >> words[i];
    }

    // 각 단어의 최대 길이인 15까지 열을 순회합니다.
    for (int col = 0; col < 15; col++) {
        // 각 단어를 순회합니다.
        for (int row = 0; row < 5; row++) {
            // 현재 문자가 널 종단 문자가 아닌 경우에만 출력합니다.
            if (words[row][col] != '\0') {
                cout << words[row][col];
            }
        }
    }

    return 0;
}