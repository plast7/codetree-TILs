#include <iostream>

using namespace std;

// 이 함수는 주어진 횟수만큼 "CodeTree!"를 출력합니다.
void printCodeTree(int repetitions) {
    // 반복문을 사용하여 지정된 횟수만큼 출력합니다.
    for (int i = 0; i < repetitions; i++) {
        // 각 줄에 "CodeTree!"를 출력합니다.
        cout << "CodeTree!" << endl;
    }
}

int main() {
    // 반복 횟수를 저장할 변수를 선언합니다.
    int numberOfRepetitions;
    // 사용자로부터 반복 횟수를 입력받습니다.
    cin >> numberOfRepetitions;
    // 입력받은 횟수만큼 "CodeTree!"를 출력하는 함수를 호출합니다.
    printCodeTree(numberOfRepetitions);
}