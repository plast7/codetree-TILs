#include <iostream>
using namespace std;

int main() {
    int numCharacters; // 입력받을 문자의 개수를 저장할 변수입니다.
    cin >> numCharacters; // 문자의 개수를 입력받습니다.
    
    char characters[52]; // 문자를 저장할 배열입니다. 최대 50개까지 입력받을 수 있으므로 넉넉하게 52로 설정합니다.
    
    // 입력받은 문자를 배열에 저장합니다.
    // 인덱스를 1부터 시작하여 입력받습니다.
    for (int i = 1; i <= numCharacters; i++) {
        cin >> characters[i]; // 각 문자를 입력받아 배열에 저장합니다.
    }
    
    // 세 번째, 다섯 번째, 여덟 번째 문자를 차례로 출력합니다.
    // 배열의 인덱스는 1부터 시작하므로 characters[3], characters[5], characters[8]을 출력합니다.
    cout << characters[3] << " " << characters[5] << " " << characters[8];
    
    return 0; // 프로그램이 정상적으로 종료되었음을 알립니다.
}