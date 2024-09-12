#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 수열의 길이를 입력받습니다.
    int sequence_length;
    cin >> sequence_length;

    // 수열을 저장할 배열을 선언합니다.
    int sequence[100001];
    // 증가하는 부분 수열의 길이를 저장할 배열을 선언합니다.
    int increasing_dp[100001];
    // 감소하는 부분 수열의 길이를 저장할 배열을 선언합니다.
    int decreasing_dp[100001];
    // 가장 긴 연속 부분 수열의 길이를 저장할 변수를 선언합니다.
    int max_length = 1;

    // 수열의 원소를 입력받습니다.
    for(int i = 0; i < sequence_length; i++) {
        cin >> sequence[i];
        // 초기값으로 각 위치에서의 부분 수열 길이를 1로 설정합니다.
        increasing_dp[i] = 1;
        decreasing_dp[i] = 1;
    }

    // 수열을 순회하며 증가하는 부분 수열과 감소하는 부분 수열의 길이를 계산합니다.
    for(int i = 1; i < sequence_length; i++) {
        // 현재 원소가 이전 원소보다 크거나 같다면 증가하는 부분 수열의 길이를 갱신합니다.
        if(sequence[i] >= sequence[i - 1]) {
            increasing_dp[i] = increasing_dp[i - 1] + 1;
        }
        // 현재 원소가 이전 원소보다 작거나 같다면 감소하는 부분 수열의 길이를 갱신합니다.
        if(sequence[i] <= sequence[i - 1]) {
            decreasing_dp[i] = decreasing_dp[i - 1] + 1;
        }
        // 가장 긴 연속 부분 수열의 길이를 갱신합니다.
        max_length = max(max_length, max(increasing_dp[i], decreasing_dp[i]));
    }

    // 결과를 출력합니다.
    cout << max_length;
    return 0;
}