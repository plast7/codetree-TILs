#include <iostream>
#include <cmath>

using namespace std;

// 최대공약수(GCD)를 구하는 함수
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// 최소공배수(LCM)를 구하는 함수
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int numbers[1000005];

int main() {
    int numCount;
    cin >> numCount;

    for (int i = 0; i < numCount; i++) {
        cin >> numbers[i];
    }

    // 첫 번째 수를 기준으로 최대공약수와 최소공배수를 초기화합니다.
    int overallGCD = numbers[0];
    int overallLCM = numbers[0];

    // 모든 수에 대해 최대공약수와 최소공배수를 계산합니다.
    for (int i = 1; i < numCount; i++) {
        // 현재까지의 최대공약수와 다음 수의 최대공약수를 구합니다.
        overallGCD = gcd(overallGCD, numbers[i]);
        // 현재까지의 최소공배수와 다음 수의 최소공배수를 구합니다.
        overallLCM = lcm(overallLCM, numbers[i]);
    }

    // 결과를 출력합니다.
    cout << overallGCD << " " << overallLCM << endl;

    return 0;
}