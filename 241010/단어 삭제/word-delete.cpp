#include <iostream>
#include <string>

using namespace std;

int main() {
    string mainStr, subStr; // 주 문자열과 부 문자열을 선언합니다.

    // 문자열을 입력받습니다.
    cin >> mainStr >> subStr;

    // 부 문자열이 주 문자열 내에 존재하는 동안 반복하여 삭제합니다.
    while (true) {
        int foundIdx = mainStr.find(subStr); // 부 문자열의 시작 인덱스를 찾습니다.

        // 만약 부 문자열을 찾지 못하면 반복문을 종료합니다.
        if (foundIdx == string::npos) {
            break;
        }

        // 부 문자열을 주 문자열에서 삭제합니다.
        mainStr.erase(foundIdx, subStr.length());
    }

    // 부 문자열이 모두 삭제된 주 문자열을 출력합니다.
    cout << mainStr << endl;

    return 0;
}