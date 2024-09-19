#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 수열을 저장할 벡터와 각 위치까지의 최대 합을 저장할 벡터를 선언합니다.
    vector<int> sequence(n);
    vector<int> max_sum(n);

    // 수열을 입력받고, 각 위치의 최대 합을 초기화합니다.
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
        max_sum[i] = sequence[i];
    }

    // 각 위치에 대해 이전 위치들을 확인하며 최대 합을 갱신합니다.
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // 현재 위치의 값이 이전 위치의 값보다 작다면, 감소하는 부분 수열 조건을 만족합니다.
            if (sequence[j] > sequence[i]) {
                // 현재 위치의 최대 합을 갱신합니다.
                max_sum[i] = max(max_sum[i], max_sum[j] + sequence[i]);
            }
        }
    }

    // 최대 합을 구합니다.
    int result = *max_element(max_sum.begin(), max_sum.end());
    cout << result << endl;

    return 0;
}