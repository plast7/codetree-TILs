#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

// 함수 호출 횟수를 저장할 배열을 선언합니다.
int call_count[51];

int main() {
    // 입출력 속도를 높이기 위해 사용합니다.
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    // n을 입력받습니다.
    int n;
    cin >> n;

    // 기저 조건을 설정합니다.
    // codetree(0)과 codetree(1)은 각각 1번 호출됩니다.
    call_count[0] = 1;
    call_count[1] = 1;
    // codetree(2)는 3번 호출됩니다.
    call_count[2] = 3;

    // 동적 계획법을 이용하여 codetree 함수의 호출 횟수를 계산합니다.
    for (int i = 3; i <= n; i++) {
        // codetree(i)는 codetree(i-1), codetree(i-2), 그리고 자신이 호출됩니다.
        call_count[i] = (call_count[i - 1] + call_count[i - 2] + 1) % MOD;
    }

    // 결과를 출력합니다.
    cout << call_count[n];
    return 0;
}