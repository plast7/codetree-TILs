#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int number;
    cin >> number;

    // 소수 여부를 판단하기 위한 배열을 초기화합니다.
    // isNotPrime[i]가 true이면 i는 소수가 아닙니다.
    vector<bool> isNotPrime(1000001, false);
    // 소수를 저장할 벡터를 선언합니다.
    vector<int> primes;

    // 에라토스테네스의 체를 사용하여 1,000,000까지의 모든 소수를 찾습니다.
    for (int i = 2; i <= 1000000; i++) {
        // i가 소수라면
        if (!isNotPrime[i]) {
            // 소수 목록에 추가합니다.
            primes.push_back(i);
            // i의 배수들을 모두 소수가 아니라고 표시합니다.
            for (int j = i * 2; j <= 1000000; j += i) {
                isNotPrime[j] = true;
            }
        }
    }

    // 가장 가까운 소수와의 차이를 저장할 변수를 초기화합니다.
    int closestDifference = INT_MAX;
    // 가장 가까운 소수 두 개를 저장할 변수를 초기화합니다.
    int closestPrime1 = 0, closestPrime2 = 0;

    // 주어진 숫자와 가장 가까운 소수를 찾습니다.
    for (int prime : primes) {
        // 현재 소수와 주어진 숫자와의 차이를 계산합니다.
        int currentDifference = abs(number - prime);
        // 현재 차이가 가장 작은 차이보다 작다면
        if (currentDifference < closestDifference) {
            // 가장 작은 차이를 갱신하고
            closestDifference = currentDifference;
            // 가장 가까운 소수를 갱신합니다.
            closestPrime1 = prime;
            closestPrime2 = 0; // 두 번째 소수는 초기화합니다.
        } 
        // 현재 차이가 가장 작은 차이와 같다면
        else if (currentDifference == closestDifference) {
            // 두 번째 소수로 저장합니다.
            closestPrime2 = prime;
        }
    }

    // 가장 가까운 소수를 출력합니다.
    if (closestPrime2 != 0) {
        // 두 개의 소수가 있다면 둘 다 출력합니다.
        cout << closestPrime1 << " " << closestPrime2 << endl;
    } else {
        // 하나의 소수만 있다면 그 소수만 출력합니다.
        cout << closestPrime1 << endl;
    }

    return 0;
}