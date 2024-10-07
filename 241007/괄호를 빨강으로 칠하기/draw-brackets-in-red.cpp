#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

// MOD 값을 정의합니다. 이는 결과를 2012로 나누기 위한 값입니다.
#define MOD 2012
// 최대 문자열 길이를 정의합니다.
#define MAX_LENGTH 1010

// ways 배열은 각 균형 상태에서 가능한 색칠 방법의 수를 저장합니다.
int ways[MAX_LENGTH];

int main() {
    // 초기 균형 상태를 1로 설정합니다. 이는 첫 번째 '('에 대한 기본 균형입니다.
    int balance = 1;
    // 첫 번째 '('에 대한 기본 경우의 수는 1입니다.
    ways[1] = 1;

    // 입력 문자열을 한 문자씩 읽어들입니다.
    for (int ch = cin.get(); balance > 0 && (ch == '(' || ch == ')'); ch = cin.get()) {
        // 현재 문자가 '('이면 1을 더하고, ')'이면 1을 뺍니다.
        int direction = (ch == '(') ? 1 : -1;
        balance += direction;

        // 현재 균형 상태에서 가능한 모든 경우의 수를 업데이트합니다.
        for (int j = (direction < 0) ? 1 : balance; 1 <= j && j <= balance; j -= direction) {
            // 현재 상태에서 가능한 경우의 수를 업데이트합니다.
            ways[j] += ways[j - direction];
            // MOD 값을 초과하지 않도록 조정합니다.
            if (ways[j] >= MOD) ways[j] -= MOD;
        }
        // 다음 위치의 경우의 수를 초기화합니다.
        ways[balance + 1] = 0;
    }

    // 최종 균형 상태가 1이면 가능한 경우의 수를 출력합니다. 그렇지 않으면 0을 출력합니다.
    cout << (balance == 1 ? ways[1] : 0) << endl;
}