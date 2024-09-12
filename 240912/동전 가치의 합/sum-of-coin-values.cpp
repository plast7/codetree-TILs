#include <iostream>
#include <vector>

using namespace std;

// MOD 값을 정의합니다. 이는 결과를 1,000,000,007로 나눈 나머지를 구하기 위함입니다.
const int MOD = 1e9 + 7;

int main() {
    // 입출력 속도를 높이기 위해 사용합니다.
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 동전의 종류 수와 목표 금액을 입력받습니다.
    int numCoins, targetAmount;
    cin >> numCoins >> targetAmount;

    // 동전의 각 금액을 저장할 벡터를 선언합니다.
    vector<int> coinValues(numCoins);
    for (int i = 0; i < numCoins; ++i) {
        cin >> coinValues[i];
    }

    // 각 금액을 만들 수 있는 경우의 수를 저장할 벡터를 선언합니다.
    // 초기값은 0으로 설정하고, waysToMakeAmount[0]은 1로 설정합니다.
    vector<int> waysToMakeAmount(targetAmount + 1, 0);
    waysToMakeAmount[0] = 1;

    // 각 동전에 대해 반복합니다.
    for (int i = 0; i < numCoins; ++i) {
        // 현재 동전의 금액부터 목표 금액까지 반복합니다.
        for (int amount = coinValues[i]; amount <= targetAmount; ++amount) {
            // 현재 금액을 만들 수 있는 경우의 수를 갱신합니다.
            waysToMakeAmount[amount] = (waysToMakeAmount[amount] + waysToMakeAmount[amount - coinValues[i]]) % MOD;
        }
    }

    // 목표 금액을 만들 수 있는 경우의 수를 출력합니다.
    // 만약 만들 수 없는 경우 -1을 출력합니다.
    cout << (waysToMakeAmount[targetAmount] != 0 ? waysToMakeAmount[targetAmount] : -1) << '\n';

    return 0;
}