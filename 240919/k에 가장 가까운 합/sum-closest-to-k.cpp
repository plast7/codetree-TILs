#include <iostream>
#include <algorithm>
#include <climits> 

using namespace std;

int main() {
    // 변수 선언
    int num_elements, target_sum;
    // n과 k를 입력받습니다.
    cin >> num_elements >> target_sum;

    // n개의 정수를 저장할 배열을 동적 할당합니다.
    int* elements = new int[num_elements];
    // n개의 정수를 입력받습니다.
    for (int i = 0; i < num_elements; i++) {
        cin >> elements[i];
    }

    // 배열을 오름차순으로 정렬합니다.
    sort(elements, elements + num_elements);

    // k에 가장 가까운 합과 그 합이 나오는 경우의 수를 저장할 변수들을 초기화합니다.
    int closest_difference = INT_MAX;
    long long closest_count = 0;

    // 투 포인터를 사용하여 배열의 양 끝에서 시작합니다.
    int left = 0;
    int right = num_elements - 1;

    // 두 포인터가 교차할 때까지 반복합니다.
    while (left < right) {
        // 현재 두 포인터가 가리키는 값의 합을 계산합니다.
        int current_sum = elements[left] + elements[right];
        // 현재 합과 k의 차이를 계산합니다.
        int current_difference = abs(current_sum - target_sum);

        // 현재 차이가 가장 작은 차이보다 작다면, 가장 작은 차이를 갱신하고 경우의 수를 1로 초기화합니다.
        if (current_difference < closest_difference) {
            closest_difference = current_difference;
            closest_count = 1;
        } 
        // 현재 차이가 가장 작은 차이와 같다면, 경우의 수를 증가시킵니다.
        else if (current_difference == closest_difference) {
            closest_count++;
        }

        // 현재 합이 k보다 작다면, 왼쪽 포인터를 오른쪽으로 이동시킵니다.
        if (current_sum < target_sum) {
            left++;
        } 
        // 현재 합이 k보다 크거나 같다면, 오른쪽 포인터를 왼쪽으로 이동시킵니다.
        else {
            right--;
        }
    }

    // k에 가장 가까운 합이 나오는 경우의 수를 출력합니다.
    cout << closest_count;

    // 동적 할당한 배열을 해제합니다.
    delete[] elements;
    return 0;
}