#include <iostream>
#include <cstring>
using namespace std;

// dp 배열을 선언합니다. dp[a][b][c][d][e][prev1][prev2]는
// 각 문자의 개수가 a, b, c, d, e일 때, 이전 두 문자가 prev1, prev2인 경우의 유효한 문자열의 수를 저장합니다.
long long dp[11][11][11][11][11][5][5];

// 각 문자의 개수를 저장하는 배열입니다.
int charCount[5];

// 사용할 문자의 종류 수를 저장하는 변수입니다.
int numChars;

// 유효한 문자열의 수를 계산하는 함수입니다.
long long countValidStrings(int prev1, int prev2) {
    // 현재 상태에 대한 결과를 dp 배열에서 가져옵니다.
    long long &result = dp[charCount[0]][charCount[1]][charCount[2]][charCount[3]][charCount[4]][prev1][prev2];
    
    // 이미 계산된 결과가 있다면 그 값을 반환합니다.
    if (result != -1) {
        return result;
    } 
    // 모든 문자를 다 사용한 경우, 유효한 문자열이므로 1을 반환합니다.
    else if (charCount[0] + charCount[1] + charCount[2] + charCount[3] + charCount[4] == 0) {
        return 1;
    } 
    // 새로운 결과를 계산합니다.
    else {
        result = 0;
        // 각 문자를 하나씩 선택하여 유효한 문자열을 만듭니다.
        for (int i = 0; i < numChars; i++) {
            // 문자가 남아있지 않거나, 이전 두 문자와 같은 경우는 건너뜁니다.
            if (charCount[i] == 0 || i == prev1 || i == prev2) {
                continue;
            }
            // 선택한 문자의 개수를 줄이고, 재귀적으로 유효한 문자열의 수를 계산합니다.
            charCount[i]--;
            result += countValidStrings(prev2, i);
            // 선택한 문자의 개수를 원래대로 돌려놓습니다.
            charCount[i]++;
        }
        return result;
    }
}

int main() {
    long long totalCount = 0;
    // 사용할 문자의 종류 수를 입력받습니다.
    cin >> numChars;
    // 각 문자의 개수를 입력받습니다.
    for (int i = 0; i < numChars; i++) {
        cin >> charCount[i];
    }
    // dp 배열을 -1로 초기화합니다.
    memset(dp, -1, sizeof(dp));
    // 첫 번째와 두 번째 문자를 선택하여 유효한 문자열의 수를 계산합니다.
    for (int first = 0; first < numChars; first++) {
        for (int second = 0; second < numChars; second++) {
            // 첫 번째와 두 번째 문자가 같은 경우는 건너뜁니다.
            if (first == second) {
                continue;
            }
            // 선택한 두 문자의 개수를 줄이고, 유효한 문자열의 수를 계산합니다.
            charCount[first]--;
            charCount[second]--;
            totalCount += countValidStrings(first, second);
            // 선택한 두 문자의 개수를 원래대로 돌려놓습니다.
            charCount[first]++;
            charCount[second]++;
        }
    }
    // 유효한 문자열의 수를 출력합니다.
    cout << totalCount;
}