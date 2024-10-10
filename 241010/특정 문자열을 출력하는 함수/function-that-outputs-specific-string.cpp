#include <iostream>

using namespace std;

// 이 함수는 주어진 횟수만큼 특정 문자열 패턴을 출력합니다.
void printPattern(int repeatCount) {
    // repeatCount 횟수만큼 반복합니다.
    for (int i = 0; i < repeatCount; i++) {
        // "Hello" 문자열을 출력합니다.
        cout << "Hello" << endl;
        // "#@#@#@#@#@" 문자열을 출력합니다.
        cout << "#@#@#@#@#@" << endl;
        // "CodeTree" 문자열을 출력합니다.
        cout << "CodeTree" << endl;
        // "@#@#@#@#@#" 문자열을 출력합니다.
        cout << "@#@#@#@#@#" << endl;
        // "Students!" 문자열을 출력합니다.
        cout << "Students!" << endl;
        // 각 패턴 사이에 빈 줄을 추가합니다.
        cout << endl;
    }
}

int main() {
    // 반복 횟수를 저장할 변수를 선언합니다.
    int repeatCount;
    // 사용자로부터 반복 횟수를 입력받습니다.
    cin >> repeatCount;
    // 입력받은 횟수만큼 패턴을 출력하는 함수를 호출합니다.
    printPattern(repeatCount);
}