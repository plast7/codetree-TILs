#include <iostream>
#include <algorithm>
#include <climits> 

using namespace std;

int main() {
    // 입력받을 원소의 개수와 목표 합을 저장할 변수를 선언합니다.
    int num_elements, target_sum;
    cin >> num_elements >> target_sum; 

    // 원소들을 저장할 배열을 동적으로 할당합니다.
    int* elements = new int[num_elements];
    for(int i = 0; i < num_elements; i++) {
        cin >> elements[i];
    }

    // 배열을 오름차순으로 정렬합니다.
    sort(elements, elements + num_elements); 
    
    // 가장 가까운 차이를 저장할 변수를 초기화합니다.
    int closest_diff = INT_MAX;
    // 가장 가까운 합이 나오는 경우의 수를 저장할 변수를 초기화합니다.
    long long count_closest_pairs = 0; 

    // 두 포인터를 사용하여 배열의 양 끝에서부터 탐색을 시작합니다.
    int left = 0;
    int right = num_elements - 1;
    while(left < right) {
        // 현재 두 원소의 합을 계산합니다.
        int current_sum = elements[left] + elements[right];
        // 목표 합과의 차이를 계산합니다.
        int current_diff = abs(current_sum - target_sum);

        // 현재 차이가 가장 작은 차이보다 작다면, 갱신합니다.
        if(current_diff < closest_diff) {
            closest_diff = current_diff;
            count_closest_pairs = 1;
        } 
        // 현재 차이가 가장 작은 차이와 같다면, 경우의 수를 증가시킵니다.
        else if(current_diff == closest_diff) {
            count_closest_pairs++;
        }

        // 현재 합이 목표 합보다 작다면, 왼쪽 포인터를 오른쪽으로 이동시킵니다.
        if(current_sum < target_sum) {
            left++;
        } 
        // 현재 합이 목표 합보다 크다면, 오른쪽 포인터를 왼쪽으로 이동시킵니다.
        else {
            right--;
        }
    }
    
    // 가장 가까운 합이 나오는 경우의 수를 출력합니다.
    cout << count_closest_pairs; 

    // 동적으로 할당한 배열을 해제합니다.
    delete[] elements;
    return 0;
}