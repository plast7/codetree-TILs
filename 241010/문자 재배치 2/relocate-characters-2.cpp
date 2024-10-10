#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 변수 선언: 입력받을 문자 개수를 저장할 변수
    int numCharacters;
    // 사용자로부터 문자 개수를 입력받습니다.
    cin >> numCharacters;
    
    // 입력받은 문자들을 저장할 벡터를 선언합니다.
    vector<char> characters(numCharacters);
    
    // 각 문자를 입력받아 벡터에 저장합니다.
    for (int i = 0; i < numCharacters; i++) {
        cin >> characters[i];
    }
    
    // 문자를 역순으로 출력합니다.
    // numCharacters - 1부터 0까지 감소하면서 각 문자를 출력합니다.
    for (int i = numCharacters - 1; i >= 0; i--) {
        cout << characters[i] << " ";
    }
    
    // 프로그램이 정상적으로 종료되었음을 알립니다.
    return 0;
}