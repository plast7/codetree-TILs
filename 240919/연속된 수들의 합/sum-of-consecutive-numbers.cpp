#include <iostream>
using namespace std;

int main() {
    int targetSum;
    cin >> targetSum;
    
    // 연속된 자연수들의 합으로 나타내는 경우의 수를 저장할 변수입니다.
    int countWays = 0;
    // 투 포인터를 사용하여 연속된 수들의 합을 계산합니다.
    int left = 1, right = 1, currentSum = 0;
    
    // left와 right 포인터를 사용하여 연속된 수들의 합을 구합니다.
    while (left <= right && right <= targetSum + 1) {
        // 현재 합이 목표 합보다 큰 경우, left 포인터를 이동시켜 합을 줄입니다.
        if (currentSum > targetSum) {
            currentSum -= left;
            left++;
        } 
        // 현재 합이 목표 합보다 작은 경우, right 포인터를 이동시켜 합을 늘립니다.
        else if (currentSum < targetSum) {
            currentSum += right;
            right++;
        } 
        // 현재 합이 목표 합과 같은 경우, 경우의 수를 증가시키고 right 포인터를 이동시켜 다음 합을 계산합니다.
        else {
            countWays++;
            currentSum += right;
            right++;
        }
    }
    
    // 결과를 출력합니다.
    cout << countWays;
    return 0;
}