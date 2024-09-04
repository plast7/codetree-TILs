#include <iostream>
using namespace std;

// 피보나치 수열을 저장하기 위한 배열을 선언합니다.
long long fibonacci_cache[50] = {0, 1};

// 피보나치 수열을 계산하는 함수입니다.
long long fibonacci(int n) {
    // n이 0 또는 1일 경우, 미리 저장된 값을 반환합니다.
    if (n == 0 || n == 1) {
        return fibonacci_cache[n];
    } 
    // 피보나치 수열의 값이 계산되지 않았을 경우, 재귀적으로 계산합니다.
    else if (fibonacci_cache[n] == 0) {
        fibonacci_cache[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
    // 계산된 값을 반환합니다.
    return fibonacci_cache[n];
}

int main() {
    int n;
    // 입력을 받습니다.
    cin >> n;

    // n이 0일 경우, 0은 1번 출력되고 1은 0번 출력됩니다.
    if (n == 0) {
        cout << "1 0" << '\n';
    } 
    // n이 1 이상일 경우, 피보나치 수열을 이용하여 0과 1의 출력 횟수를 계산합니다.
    else {
        cout << fibonacci(n - 1) << ' ' << fibonacci(n) << '\n';
    }

    return 0;
}