#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    // 두 개의 정수를 입력받습니다.
    cin >> num1 >> num2;

    // 두 수를 비교하여 작은 수에서 큰 수를 뺀 값을 출력합니다.
    if(num1 > num2)
        // num1이 num2보다 크다면, num2에서 num1을 뺍니다.
        cout << num2 - num1;
    else
        // num2가 num1보다 크거나 같다면, num1에서 num2를 뺍니다.
        cout << num1 - num2;

    return 0;
}