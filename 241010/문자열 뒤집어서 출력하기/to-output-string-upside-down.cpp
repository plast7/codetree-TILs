#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // 네 개의 문자열을 저장할 변수를 선언합니다.
    string word1, word2, word3, word4;

    // 각 문자열을 입력받습니다.
    cin >> word1;
    cin >> word2;
    cin >> word3;
    cin >> word4;

    // 네 번째 문자열을 뒤집습니다.
    reverse(word4.begin(), word4.end());
    // 뒤집은 문자열을 출력합니다.
    cout << word4 << endl;

    // 세 번째 문자열을 뒤집습니다.
    reverse(word3.begin(), word3.end());
    // 뒤집은 문자열을 출력합니다.
    cout << word3 << endl;

    // 두 번째 문자열을 뒤집습니다.
    reverse(word2.begin(), word2.end());
    // 뒤집은 문자열을 출력합니다.
    cout << word2 << endl;

    // 첫 번째 문자열을 뒤집습니다.
    reverse(word1.begin(), word1.end());
    // 뒤집은 문자열을 출력합니다.
    cout << word1 << endl;

    return 0;
}