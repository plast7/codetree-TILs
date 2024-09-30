#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    // 입력 문자열을 저장할 변수입니다.
    string inputString;
    // 한 줄 전체를 입력받습니다.
    getline(cin, inputString);
    // 마지막 단어 처리를 위해 문자열 끝에 공백을 추가합니다.
    inputString += ' ';

    // 문자를 저장할 스택입니다.
    stack<char> charStack;
    // 결과 문자열을 저장할 변수입니다.
    string resultString;

    // 현재 인덱스를 저장할 변수입니다.
    int index = 0;
    // 입력 문자열의 길이를 저장합니다.
    int length = inputString.length();

    // 문자열의 끝까지 반복합니다.
    while (index <= length) {
        // 현재 문자가 '<'인 경우입니다.
        if (inputString[index] == '<') {
            // 스택에 남아있는 문자를 모두 결과 문자열에 추가합니다.
            while (!charStack.empty()) {
                resultString += charStack.top();
                charStack.pop();
            }
            // '>'가 나올 때까지 현재 문자를 결과 문자열에 추가합니다.
            while (inputString[index] != '>') {
                resultString += inputString[index++];
            }
            // '>'를 결과 문자열에 추가합니다.
            resultString += inputString[index++];
        } else {
            // 현재 문자를 스택에 추가합니다.
            charStack.push(inputString[index]);
            // 현재 문자가 공백인 경우입니다.
            if (inputString[index] == ' ') {
                // 스택에 남아있는 문자를 모두 결과 문자열에 추가합니다.
                charStack.pop();
                while (!charStack.empty()) {
                    resultString += charStack.top();
                    charStack.pop();
                }
                // 공백을 결과 문자열에 추가합니다.
                resultString += ' ';
            }
            // 인덱스를 증가시킵니다.
            index++;
        }
    }

    // 결과 문자열을 출력합니다.
    for (int i = 0; i < length; i++) {
        cout << resultString[i];
    }

    return 0;
}