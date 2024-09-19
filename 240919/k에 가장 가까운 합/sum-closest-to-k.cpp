#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int main() {
    // 변수 선언
    int num_elements, target_sum;
    // 첫 번째 줄에서 n과 k를 입력받습니다.
    cin >> num_elements >> target_sum;

    // n개의 정수를 저장할 벡터를 선언합니다.
    vector<int> numbers(num_elements);
    // 두 번째 줄에서 n개의 정수를 입력받습니다.
    for (int i = 0; i < num_elements; i++) {
        cin >> numbers[i];
    }

    // 입력받은 정수들을 오름차순으로 정렬합니다.
    sort(numbers.begin(), numbers.end());

    // k에 가장 가까운 합의 차이를 저장할 변수를 초기화합니다.
    int closest_diff = INT_MAX;
    // k에 가장 가까운 합이 나오는 경우의 수를 저장할 변수를 초기화합니다.
    long long count_closest_pairs = 0;

    // 투 포인터를 사용하기 위해 왼쪽 포인터와 오른쪽 포인터를 초기화합니다.
    int left = 0;
    int right = num_elements - 1;

    // 두 포인터가 교차할 때까지 반복합니다.
    while (left < right) {
        // 현재 두 포인터가 가리키는 정수의 합을 계산합니다.
        int current_sum = numbers[left] + numbers[right];
        // 현재 합과 k의 차이를 계산합니다.
        int current_diff = abs(current_sum - target_sum);

        // 현재 차이가 가장 작은 차이보다 작다면
        if (current_diff < closest_diff) {
            // 가장 작은 차이를 갱신하고
            closest_diff = current_diff;
            // 경우의 수를 1로 초기화합니다.
            count_closest_pairs = 1;
        } 
        // 현재 차이가 가장 작은 차이와 같다면
        else if (current_diff == closest_diff) {
            // 경우의 수를 증가시킵니다.
            count_closest_pairs++;
        }

        // 현재 합이 k보다 작다면 왼쪽 포인터를 오른쪽으로 이동시킵니다.
        if (current_sum < target_sum) {
            left++;
        } 
        // 현재 합이 k보다 크거나 같다면 오른쪽 포인터를 왼쪽으로 이동시킵니다.
        else {
            right--;
        }
    }

    // k에 가장 가까운 합이 나오는 경우의 수를 출력합니다.
    cout << count_closest_pairs;

    return 0;
}