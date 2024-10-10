#include <iostream>
#include <string>

using namespace std;

int main() {
    // 문자열을 입력받습니다.
    string input;
    getline(cin, input);

    // 단어의 개수를 세기 위한 변수를 초기화합니다.
    int word_count = 1; // 공백이 없으면 단어는 하나이므로 초기값은 1입니다.
    
    // 입력된 문자열을 순회하며 공백의 개수를 셉니다.
    for (int i = 0; i < input.length(); i++) {
        // 공백을 발견할 때마다 단어의 개수를 증가시킵니다.
        if (input[i] == ' ')
            word_count++;
    }

    // 단어의 개수를 출력합니다.
    cout << word_count << "\n";

    // 입력된 문자열을 다시 순회하며 단어를 출력합니다.
    for (int i = 0; i < input.length(); i++) {
        // 공백을 만나면 줄바꿈을 출력하여 다음 단어를 새 줄에 출력합니다.
        if (input[i] == ' ')
            cout << "\n";
        else
            // 공백이 아닌 경우 해당 문자를 출력합니다.
            cout << input[i];
    }
}