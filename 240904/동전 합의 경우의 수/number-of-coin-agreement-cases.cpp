#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int numCoins, targetSum;
    cin >> numCoins >> targetSum;
    vector<int> coinValues(numCoins);
    vector<int> waysToMakeSum(targetSum + 1);

    // 동전의 가치를 입력받습니다.
    for (int i = 0; i < numCoins; i++)
        cin >> coinValues[i];

    // 합이 0을 만드는 방법은 동전을 사용하지 않는 한 가지 방법뿐입니다.
    waysToMakeSum[0] = 1;

    // 각 동전에 대해 가능한 모든 합을 계산합니다.
    for (int i = 0; i < numCoins; i++) { // 각 동전에 대해
        for (int currentSum = coinValues[i]; currentSum <= targetSum; currentSum++) {
            // 현재 동전을 사용하여 currentSum을 만드는 방법의 수를 갱신합니다.
            waysToMakeSum[currentSum] += waysToMakeSum[currentSum - coinValues[i]];
            // 결과를 MOD로 나눈 나머지를 저장합니다.
            waysToMakeSum[currentSum] %= MOD;
        }
    }

    // 목표 합을 만드는 방법의 수를 출력합니다.
    cout << waysToMakeSum[targetSum] << endl;
    return 0;
}