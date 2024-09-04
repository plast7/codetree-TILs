#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 정수를 저장할 벡터와 최대 정수 합을 저장할 벡터를 선언합니다.
vector<int> numAmounts;
vector<int> maxSum;

// 최대 정수 합을 계산하는 함수입니다.
int getmaxSum() {
    // n은 실제 정수의 개수를 의미합니다.
    int n = numAmounts.size() - 3;

    // 3번째 인덱스부터 시작하여 최대 정수 합을 계산합니다.
    for (int i = 3; i < numAmounts.size(); ++i) {
        // maxSum[i]는 다음 세 가지 경우 중 최대값을 가집니다.
        // 1. i-3번째까지의 최대 정수 합 + i-1번째 정수 크기 + i번째 정수 크기
        // 2. i-2번째까지의 최대 정수 합 + i번째 정수 크기
        // 3. i-1번째까지의 최대 정수 합
        maxSum.push_back(max({maxSum[i-3] + numAmounts[i-1] + numAmounts[i], maxSum[i-2] + numAmounts[i], maxSum[i-1]}));
    }

    // 최종적으로 계산된 최대 정수 합을 반환합니다.
    return maxSum.back();
}

int main() {
    // 정수의 개수를 입력받습니다.
    int n;
    cin >> n;

    // 정수를 저장할 벡터를 초기화합니다. 앞에 3개의 0을 추가하여 인덱스를 맞춥니다.
    numAmounts.resize(n + 3, 0);
    // 최대 정수 합을 저장할 벡터를 초기화합니다. 초기값으로 3개의 0을 추가합니다.
    maxSum.resize(3, 0);

    // 정수를 입력받아 벡터에 저장합니다.
    for (int i = 3; i < n + 3; ++i) {
        cin >> numAmounts[i];
    }

    // 최대 정수 합을 계산하여 출력합니다.
    cout << getmaxSum() << endl;

    return 0;
}