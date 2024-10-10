#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    // 증가하는 패턴의 별을 출력합니다.
    // i는 1부터 n까지 증가합니다.
    for (int i = 1; i <= n; i++) {
        // j는 1부터 i까지 증가하며 별을 출력합니다.
        for (int j = 1; j <= i; j++) {
            cout << "*"; // 별을 출력합니다.
        }
        cout << endl; // 한 줄을 출력한 후 줄바꿈을 합니다.
    }

    // 감소하는 패턴의 별을 출력합니다.
    // i는 n-1부터 1까지 감소합니다.
    for (int i = n - 1; i >= 1; i--) {
        // j는 1부터 i까지 증가하며 별을 출력합니다.
        for (int j = 1; j <= i; j++) {
            cout << "*"; // 별을 출력합니다.
        }
        cout << endl; // 한 줄을 출력한 후 줄바꿈을 합니다.
    }

    return 0; // 프로그램을 종료합니다.
}