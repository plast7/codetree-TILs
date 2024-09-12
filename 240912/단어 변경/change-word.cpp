#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 초기 단어의 길이와 목표 단어의 길이를 저장합니다.
int initialLength, targetLength;
// 초기 단어와 목표 단어를 저장합니다.
string initialWord, targetWord;

// 두 문자가 규칙에 따라 동등한지 확인하는 함수입니다.
bool isEquivalent(char initialChar, char targetChar) {
    // 두 문자가 같으면 동등합니다.
    if (initialChar == targetChar)
        return true;
    // 'i'는 'i', 'j', 'l'과 동등합니다.
    else if (initialChar == 'i' && (targetChar == 'i' || targetChar == 'j' || targetChar == 'l'))
        return true;
    // 'v'는 'v', 'w'와 동등합니다.
    else if (initialChar == 'v' && (targetChar == 'v' || targetChar == 'w'))
        return true;
    // 그 외의 경우는 동등하지 않습니다.
    else
        return false;
}

// 편집 거리를 계산하는 함수입니다.
int calculateEditDistance() {
    // DP 테이블을 초기화합니다.
    vector<vector<int>> dp(initialLength + 1, vector<int>(targetLength + 1, 0));

    // 초기 단어의 길이만큼 삭제 연산을 수행하는 경우를 초기화합니다.
    for (int i = 1; i <= initialLength; i++) 
        dp[i][0] = i;
    // 목표 단어의 길이만큼 추가 연산을 수행하는 경우를 초기화합니다.
    for (int j = 1; j <= targetLength; j++) 
        dp[0][j] = j;

    // DP 테이블을 채워나갑니다.
    for (int i = 1; i <= initialLength; i++) {
        for (int j = 1; j <= targetLength; j++) {
            // 두 문자가 동등한 경우, 변환 연산이 필요 없습니다.
            if (isEquivalent(initialWord[i - 1], targetWord[j - 1])) 
                dp[i][j] = dp[i - 1][j - 1];
            else
                // 변환, 삭제, 추가 연산 중 최소값을 선택합니다.
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
        }
    }
    // 최종 편집 거리를 반환합니다.
    return dp[initialLength][targetLength];
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    // 입력을 받습니다.
    cin >> initialLength >> targetLength;
    cin >> initialWord >> targetWord;

    // 편집 거리를 계산하고 출력합니다.
    cout << calculateEditDistance() << "\n";
}