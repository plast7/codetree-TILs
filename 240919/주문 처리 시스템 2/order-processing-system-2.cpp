#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 처리기 용량을 저장할 벡터
vector<int> processorCapacities;
// 두 처리기의 용량을 합친 값이 이미 존재하는지 확인하기 위한 배열
bool combinedCapacityExists[20001] = { false };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 최소 처리 횟수를 저장할 배열
    int minSteps[10001];
    fill(begin(minSteps), end(minSteps), 10001); // 초기값을 10001로 설정 (불가능한 큰 값)

    int numOrders, numProcessors;
    cin >> numOrders >> numProcessors;

    // 처리기 용량 입력 받기
    for (int i = 0; i < numProcessors; ++i) {
        int capacity;
        cin >> capacity;
        processorCapacities.push_back(capacity);
    }

    // 두 처리기의 용량을 합친 값을 추가
    for (int i = 0; i < numProcessors; ++i) {
        for (int j = i + 1; j < numProcessors; ++j) {
            int combinedCapacity = processorCapacities[i] + processorCapacities[j];
            if (!combinedCapacityExists[combinedCapacity]) {
                processorCapacities.push_back(combinedCapacity);
                combinedCapacityExists[combinedCapacity] = true;
            }
        }
    }

    // 중복된 용량을 제거하고 정렬
    sort(processorCapacities.begin(), processorCapacities.end());
    processorCapacities.erase(unique(processorCapacities.begin(), processorCapacities.end()), processorCapacities.end());

    // 초기값 설정: 0개의 주문을 처리하는데 필요한 처리 횟수는 0
    minSteps[0] = 0;

    // DP를 이용하여 최소 처리 횟수를 계산
    for (int capacity : processorCapacities) {
        for (int j = capacity; j <= numOrders; ++j) {
            minSteps[j] = min(minSteps[j], minSteps[j - capacity] + 1);
        }
    }

    // 결과 출력
    if (minSteps[numOrders] == 10001) {
        cout << -1;
    } else {
        cout << minSteps[numOrders];
    }

    return 0;
}