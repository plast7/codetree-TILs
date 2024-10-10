#include <iostream>
using namespace std;

int main() {
    int size;
    cin >> size;

    // 패턴의 윗부분을 출력합니다.
    for (int i = 1; i <= size / 2 + 1; i++) {
        // 각 줄의 앞부분에 공백을 출력합니다.
        for (int j = 1; j < i; j++) {
            cout << " ";
        }
        // 별을 출력합니다. 별의 개수는 2*i - 1개입니다.
        for (int j = 1; j < i * 2; j++) {
            cout << "*";
        }
        // 줄바꿈을 합니다.
        cout << "\n";
    }

    // 패턴의 아랫부분을 출력합니다.
    for (int i = size / 2; i >= 1; i--) {
        // 각 줄의 앞부분에 공백을 출력합니다.
        for (int j = 1; j < i; j++) {
            cout << " ";
        }
        // 별을 출력합니다. 별의 개수는 2*i - 1개입니다.
        for (int j = 1; j < i * 2; j++) {
            cout << "*";
        }
        // 줄바꿈을 합니다.
        cout << "\n";
    }

    return 0;
}