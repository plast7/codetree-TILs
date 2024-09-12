#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

// 회의의 시작 시간과 종료 시간을 나타내기 위해 매크로를 정의합니다.
#define START first
#define END second

// dp[i][0]: i번째 회의를 참석하지 않았을 때의 최대 참석 인원 수
// dp[i][1]: i번째 회의를 참석했을 때의 최대 참석 인원 수
ll dp[100001][2]; 

// 회의 정보를 저장할 벡터를 정의합니다.
vector<pair<pair<ll, ll>, ll>> meetings;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll num_meetings;
    cin >> num_meetings;
    
    // 회의 정보를 입력받습니다.
    meetings.resize(num_meetings + 1);
    for (int i = 1; i <= num_meetings; i++) {
        cin >> meetings[i].START.START >> meetings[i].START.END >> meetings[i].END;
    }

    // 초기 조건을 설정합니다.
    dp[1][1] = meetings[1].END; // 첫 번째 회의를 참석했을 때의 인원 수
    dp[2][1] = meetings[2].END; // 두 번째 회의를 참석했을 때의 인원 수
    dp[2][0] = meetings[1].END; // 두 번째 회의를 참석하지 않았을 때의 인원 수는 첫 번째 회의를 참석했을 때의 인원 수와 같습니다.

    // dp를 이용해 최대 참석 인원 수를 계산합니다.
    for (int i = 3; i <= num_meetings; i++) {
        // i번째 회의를 참석하지 않았을 때의 최대 참석 인원 수는
        // i-1번째 회의를 참석했을 때와 참석하지 않았을 때 중 최대값입니다.
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        
        // i번째 회의를 참석했을 때의 최대 참석 인원 수는
        // i-1번째 회의를 참석하지 않았을 때의 최대 참석 인원 수에
        // i번째 회의의 참석 인원 수를 더한 값입니다.
        dp[i][1] = dp[i - 1][0] + meetings[i].END;
    }

    // 최종적으로 최대 참석 인원 수를 출력합니다.
    cout << max(dp[num_meetings][0], dp[num_meetings][1]) << endl;

    return 0;
}