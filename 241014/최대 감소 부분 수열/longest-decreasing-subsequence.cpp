#include <iostream>
#include <algorithm>

#define MAX_N 1000

using namespace std;

// 변수 선언
int n;
int arr[MAX_N];

// dp[i] :
// 마지막으로 고른 원소의 위치가 i인
// 부분 수열 중 최장 감소 부분 수열의 길이
int dp[MAX_N];

int main() {
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++){
        // 현재 위치에서 시작할 때에는
        // dp값이 1이 되므로
        // 초기 셋팅은 1입니다.
        dp[i] = 1;

        // i번째 보다 앞에 있는 원소들 중 
        // arr[i]보다는 값이 큰 곳에 
        // 새로운 원소인 arr[i]를 추가했을 때의 
        // 부분 수열 중 최대 감소 부분 수열의 길이를 계산합니다.
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    // 마지막 원소의 위치가 i일 때의 부분 수열들 중
    // 가장 길이가 긴 감소 부분 수열을 고릅니다.
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i]);

    cout << ans;
    return 0;
}