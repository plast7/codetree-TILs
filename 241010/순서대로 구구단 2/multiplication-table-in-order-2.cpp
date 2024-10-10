#include <iostream>

using namespace std;

// 주어진 숫자의 구구단을 출력하는 함수입니다.
void printMultiplicationTable(int number) {
    // 1부터 9까지의 곱셈을 수행합니다.
    for (int multiplier = 1; multiplier <= 9; multiplier++) {
        // 각 곱셈 결과를 포맷에 맞게 출력합니다.
        cout << number << " * " << multiplier << " = " << number * multiplier << "  ";
        // 3개의 결과를 출력할 때마다 줄바꿈을 합니다.
        if (multiplier % 3 == 0) {
            cout << endl;
        }
    }
    // 각 구구단 사이에 빈 줄을 추가합니다.
    cout << endl;
}

int main() {
    int start, end;
    // 사용자로부터 시작 단과 끝 단을 입력받습니다.
    cin >> start >> end;

    // 시작 단이 끝 단보다 큰 경우, 큰 단부터 작은 단으로 출력합니다.
    if (start > end) {
        for (int i = start; i >= end; i--) {
            printMultiplicationTable(i);
        }
    } 
    // 시작 단이 끝 단보다 작거나 같은 경우, 작은 단부터 큰 단으로 출력합니다.
    else {
        for (int i = start; i <= end; i++) {
            printMultiplicationTable(i);
        }
    }

    return 0;
}