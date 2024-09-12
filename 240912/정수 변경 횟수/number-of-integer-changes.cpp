#include <iostream>
#include <cstring>
using namespace std;

// 연산을 저장할 배열
int operations[1010];
// dp 배열
int dp[1010][2];

int main() {
    // 배열 초기화
    memset(operations, 0, sizeof(operations));
    memset(dp, 0, sizeof(dp));

    // 변수 선언
    int num_operations, initial_value, max_value;
    // 입력 받기
    cin >> num_operations >> initial_value >> max_value;

    // 연산 값 입력 받기
    for (int i = 1; i <= num_operations; ++i) {
        cin >> operations[i];
    }

    // 초기 값 설정
    dp[initial_value][0] = 1;

    // 각 연산에 대해 dp 갱신
    for (int i = 1; i <= num_operations; ++i) {
        // 현재 상태에서 가능한 모든 값에 대해
        for (int j = 0; j <= max_value; ++j) {
            // 현재 값이 유효한 경우
            if (dp[j][0] != 0) {
                // 연산을 통해 값이 0 이상인 경우
                if (j - operations[i] >= 0) {
                    dp[j - operations[i]][1] = 1;
                }
                // 연산을 통해 값이 최대값 이하인 경우
                if (j + operations[i] <= max_value) {
                    dp[j + operations[i]][1] = 1;
                }
            }
        }
        // dp 배열 갱신
        for (int j = 0; j <= max_value; ++j) {
            dp[j][0] = dp[j][1];
            dp[j][1] = 0;
        }
    }

    // 최종 결과 중 최댓값 찾기
    for (int i = max_value; i >= 0; --i) {
        if (dp[i][0] == 1) {
            cout << i << endl;
            return 0;
        }
    }

    // 가능한 결과가 없는 경우 -1 출력
    cout << "-1" << endl;
    return 0;
}