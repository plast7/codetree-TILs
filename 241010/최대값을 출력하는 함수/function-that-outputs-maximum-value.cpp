#include <iostream>
using namespace std;

// 세 개의 정수를 입력받아 그 중 최대값을 반환하는 함수입니다.
int find_maximum(int num1, int num2, int num3) {
    // 첫 번째 수가 두 번째 수와 세 번째 수보다 크거나 같으면 첫 번째 수가 최대값입니다.
    if (num1 >= num2 && num1 >= num3) {
        return num1;
    } 
    // 두 번째 수가 첫 번째 수와 세 번째 수보다 크거나 같으면 두 번째 수가 최대값입니다.
    else if (num2 >= num1 && num2 >= num3) {
        return num2;
    } 
    // 위의 두 조건에 해당하지 않으면 세 번째 수가 최대값입니다.
    else {
        return num3;
    }
}

int main() {
    int number1, number2, number3;
    // 세 개의 정수를 입력받습니다.
    cin >> number1 >> number2 >> number3;

    // find_maximum 함수를 호출하여 최대값을 구합니다.
    int maximum_value = find_maximum(number1, number2, number3);
    // 최대값을 출력합니다.
    cout << maximum_value;

    return 0;
}