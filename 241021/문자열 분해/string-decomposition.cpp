#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 사용된 문자를 표시하기 위한 배열을 선언합니다.
// 문자열의 최대 길이가 2500이므로, 인덱스는 0부터 2504까지 가능합니다.
bool usedCharacters[2505];

int main() {
    // 입력받을 문자열을 저장할 변수입니다.
    string inputString;
    cin >> inputString;

    // 필요한 부분 문자열의 개수를 세기 위한 변수입니다.
    int substringCount = 0;

    // 모든 문자가 사용될 때까지 반복을 수행합니다.
    while(true) {
        // 새로운 부분 문자열을 시작하므로, 카운트를 증가시킵니다.
        substringCount++;

        // 현재 부분 문자열이 확장되었는지를 확인하기 위한 변수입니다.
        bool substringExtended = false;

        // 현재 부분 문자열에서 찾고 있는 문자입니다. 'a'부터 시작합니다.
        char currentChar = 'a';

        // 원본 문자열을 처음부터 끝까지 순회합니다.
        for(int index = 0; index < inputString.length(); index++) {
            // 현재 문자가 이미 다른 부분 문자열에 사용되었으면, 다음 문자로 넘어갑니다.
            if(usedCharacters[index]) continue;

            // 현재 문자가 찾고 있는 문자와 일치하는지 확인합니다.
            if(inputString[index] == currentChar) {
                // 문자를 사용된 것으로 표시합니다.
                usedCharacters[index] = true;

                // 부분 문자열이 확장되었음을 표시합니다.
                substringExtended = true;

                // 다음에 찾을 문자를 'b'부터 'e'까지 순차적으로 설정합니다.
                currentChar++;

                // 만약 현재 문자가 'e'를 초과하면, 다시 'a'로 초기화합니다.
                if(currentChar > 'e') currentChar = 'a';
            }
        }

        // 부분 문자열을 완성하지 못했다면, -1을 출력하고 프로그램을 종료합니다.
        if(currentChar != 'a') {
            cout << -1;
            return 0;
        }

        // 부분 문자열이 더 이상 확장되지 않았으면, 반복을 종료합니다.
        if(!substringExtended) {
            break;
        }

        // 모든 문자가 사용되었는지를 확인하기 위한 변수입니다.
        bool allCharactersUsed = true;

        // 원본 문자열의 모든 문자를 확인합니다.
        for(int index = 0; index < inputString.length(); index++) {
            // 사용되지 않은 문자가 하나라도 있으면, 모든 문자가 사용된 것이 아닙니다.
            if(!usedCharacters[index]) {
                allCharactersUsed = false;
                break;
            }
        }

        // 모든 문자가 사용되었다면, 반복을 종료합니다.
        if(allCharactersUsed) break;
    }

    // 최종적으로 모든 문자가 사용되었는지를 다시 한번 확인합니다.
    bool allCharactersUsed = true;
    for(int index = 0; index < inputString.length(); index++) {
        if(!usedCharacters[index]) {
            allCharactersUsed = false;
            break;
        }
    }

    // 모든 문자가 사용되었다면, 필요한 부분 문자열의 개수를 출력합니다.
    if(allCharactersUsed) {
        cout << substringCount;
    }
    // 모든 문자를 사용할 수 없었다면, -1을 출력합니다.
    else {
        cout << -1;
    }
}