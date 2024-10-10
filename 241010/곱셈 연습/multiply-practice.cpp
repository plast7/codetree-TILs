#include <iostream>

using namespace std;

int main() {
    int first_number, second_number;
    
    // 두 개의 세 자리 수를 입력받습니다.
    cin >> first_number >> second_number;

    // 두 번째 숫자의 각 자리수를 구합니다.
    int unit_place = second_number % 10; // 일의 자리
    int tens_place = (second_number / 10) % 10; // 십의 자리
    int hundreds_place = second_number / 100; // 백의 자리

    // 각 자리수에 대해 첫 번째 숫자와 곱한 결과를 구합니다.
    int first_partial_product = unit_place * first_number; // 일의 자리 곱셈 결과
    int second_partial_product = tens_place * first_number; // 십의 자리 곱셈 결과
    int third_partial_product = hundreds_place * first_number; // 백의 자리 곱셈 결과
    int total_product = first_number * second_number; // 전체 곱셈 결과

    // 각 곱셈 결과를 출력합니다.
    cout << first_partial_product << endl; // 첫 번째 부분 곱셈 결과 출력
    cout << second_partial_product << endl; // 두 번째 부분 곱셈 결과 출력
    cout << third_partial_product << endl; // 세 번째 부분 곱셈 결과 출력
    cout << total_product << endl; // 전체 곱셈 결과 출력

    return 0;
}