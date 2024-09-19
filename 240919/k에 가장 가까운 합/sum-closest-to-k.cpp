#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    // 변수 선언
    int num_elements, target_sum;
    // 첫 번째 줄에서 n과 k를 입력받습니다.
    cin >> num_elements >> target_sum;
    
    // n개의 정수를 저장할 배열을 선언합니다.
    int elements[num_elements];
    // 두 번째 줄에서 n개의 정수를 입력받습니다.
    for(int i = 0; i < num_elements; i++) {
        cin >> elements[i];
    }
    
    // 배열을 오름차순으로 정렬합니다.
    sort(elements, elements + num_elements);
    
    // 투 포인터를 사용하기 위해 시작 포인터와 끝 포인터를 설정합니다.
    int start = 0;
    int end = num_elements - 1;
    // k에 가장 가까운 합의 차이를 저장할 변수를 초기화합니다.
    int closest_diff = INT_MAX;
    // k에 가장 가까운 합이 나오는 경우의 수를 저장할 변수를 초기화합니다.
    long long count = 0;
    
    // 투 포인터를 사용하여 배열을 탐색합니다.
    while(start < end) {
        // 현재 두 포인터가 가리키는 두 수의 합을 계산합니다.
        int current_sum = elements[start] + elements[end];
        // 현재 두 수의 합과 k의 차이를 계산합니다.
        int current_diff = abs(current_sum - target_sum);
        
        // 현재 차이가 가장 작은 차이보다 작다면
        if(current_diff < closest_diff) {
            // 가장 작은 차이를 갱신하고
            closest_diff = current_diff;
            // 경우의 수를 1로 초기화합니다.
            count = 1;
        } 
        // 현재 차이가 가장 작은 차이와 같다면
        else if(current_diff == closest_diff) {
            // 경우의 수를 증가시킵니다.
            count++;
        }
        
        // 현재 두 수의 합이 k보다 작다면
        if(current_sum < target_sum) {
            // 시작 포인터를 오른쪽으로 이동시킵니다.
            start++;
        } 
        // 현재 두 수의 합이 k보다 크거나 같다면
        else {
            // 끝 포인터를 왼쪽으로 이동시킵니다.
            end--;
        }
    }
    
    // k에 가장 가까운 합이 나오는 경우의 수를 출력합니다.
    cout << count;
    return 0;
}