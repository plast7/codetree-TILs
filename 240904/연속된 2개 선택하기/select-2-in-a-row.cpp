#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 와인 양을 저장할 벡터와 최대 와인 합을 저장할 벡터를 선언합니다.
vector<int> wineAmounts;
vector<int> maxWineSum;

// 최대 와인 합을 계산하는 함수입니다.
int getMaxWineSum() {
    // n은 실제 와인 양의 개수를 의미합니다.
    int n = wineAmounts.size() - 3;

    // 3번째 인덱스부터 시작하여 최대 와인 합을 계산합니다.
    for (int i = 3; i < wineAmounts.size(); ++i) {
        // maxWineSum[i]는 다음 세 가지 경우 중 최대값을 가집니다.
        // 1. i-3번째까지의 최대 와인 합 + i-1번째 와인 양 + i번째 와인 양
        // 2. i-2번째까지의 최대 와인 합 + i번째 와인 양
        // 3. i-1번째까지의 최대 와인 합
        maxWineSum.push_back(max({maxWineSum[i-3] + wineAmounts[i-1] + wineAmounts[i], maxWineSum[i-2] + wineAmounts[i], maxWineSum[i-1]}));
    }

    // 최종적으로 계산된 최대 와인 합을 반환합니다.
    return maxWineSum.back();
}

int main() {
    // 와인의 개수를 입력받습니다.
    int n;
    cin >> n;

    // 와인 양을 저장할 벡터를 초기화합니다. 앞에 3개의 0을 추가하여 인덱스를 맞춥니다.
    wineAmounts.resize(n + 3, 0);
    // 최대 와인 합을 저장할 벡터를 초기화합니다. 초기값으로 3개의 0을 추가합니다.
    maxWineSum.resize(3, 0);

    // 와인 양을 입력받아 벡터에 저장합니다.
    for (int i = 3; i < n + 3; ++i) {
        cin >> wineAmounts[i];
    }

    // 최대 와인 합을 계산하여 출력합니다.
    cout << getMaxWineSum() << endl;

    return 0;
}