#include <iostream>
#include <vector>

using namespace std;

// 문자열을 저장할 배열을 선언합니다.
string strings[205];

int main() {
    int stringIdx = 0;
    string input;

    // 무한 루프를 통해 문자열을 계속 입력받습니다.
    while (true) {
        // 문자열을 입력받습니다.
        cin >> input;
        // 입력받은 문자열이 "0"이라면 입력을 종료합니다.
        if (input == "0") {
            break;
        }
        // 입력받은 문자열을 벡터에 추가합니다.
        strings[stringIdx++] = input;
    }

    // 입력받은 문자열의 총 개수를 출력합니다.
    cout << stringIdx << "\n";
    // 짝수 번째로 주어진 문자열을 출력합니다.
    // 벡터의 인덱스는 0부터 시작하므로, 1부터 시작하여 2씩 증가시킵니다.
    for (int i = 1; i < stringIdx; i += 2) {
        cout << strings[i] << "\n";
    }

    return 0;
}