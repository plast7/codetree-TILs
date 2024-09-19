#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // 정수의 개수를 입력받습니다.
    int num_elements;
    cin >> num_elements;
    
    // 정수들을 저장할 벡터와 최대 차이를 저장할 벡터를 선언합니다.
    vector<int> elements(num_elements + 1);
    vector<int> max_difference(num_elements + 1, 0);

    // 정수들을 입력받습니다.
    for (int i = 1; i <= num_elements; i++) {
        cin >> elements[i];
    }

    // 각 위치까지의 최대 차이를 계산합니다.
    for (int i = 1; i <= num_elements; i++) {
        // 현재 구간의 최소값과 최대값을 초기화합니다.
        int min_value = elements[i];
        int max_value = elements[i];
        // 현재 위치부터 역순으로 구간을 확장해가며 최소값과 최대값을 갱신합니다.
        for (int j = i; j >= max(j - 2, 1); j--) {
            min_value = min(min_value, elements[j]);
            max_value = max(max_value, elements[j]);
            // 현재 구간의 최대 차이를 갱신합니다.
            max_difference[i] = max(max_difference[i], max_difference[j - 1] + max_value - min_value);
        }
    }

    // 모든 위치까지의 최대 차이 중 가장 큰 값을 찾습니다.
    int result = 0;
    for (int i = 1; i <= num_elements; i++) {
        result = max(result, max_difference[i]);
    }

    // 결과를 출력합니다.
    cout << result;
    return 0;
}