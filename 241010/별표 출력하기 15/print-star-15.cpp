#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    // 패턴의 윗부분을 출력합니다.
    // i는 0부터 n-1까지 반복합니다.
    for (int i = 0; i < n; i++) {
        // 각 줄에 출력할 별의 개수는 (n - i) * 2입니다.
        for (int j = 0; j < 2 * (n - i); j++) {
            cout << "*"; // 별을 출력합니다.
        }
        cout << endl; // 줄바꿈을 합니다.
    }

    // 패턴의 아랫부분을 출력합니다.
    // i는 1부터 n-1까지 반복합니다.
    for (int i = 1; i < n; i++) {
        // 각 줄에 출력할 별의 개수는 (n - 1 + i) * 2입니다.
        for (int j = 0; j < 2 * (i + 1); j++) {
            cout << "*"; // 별을 출력합니다.
        }
        cout << endl; // 줄바꿈을 합니다.
    }

    return 0;
}