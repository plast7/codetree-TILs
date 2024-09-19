#include <iostream>
#include <cstring>

using namespace std;

// 상자 안에 들어있는 숫자의 수를 저장하는 변수입니다.
int numOnes;

// dp 배열은 메모이제이션을 위해 사용됩니다.
// dp[remainingOnes][remainingHalves]는 remainingOnes개의 1과 remainingHalves개의 0.5가 남아있을 때
// 가능한 서로 다른 문자열의 개수를 저장합니다.
long long dp[61][61];

// 가능한 서로 다른 문자열의 개수를 세는 함수입니다.
long long countDistinctStrings(int remainingOnes, int remainingHalves) {
    // 만약 남아있는 1이 없다면, 가능한 문자열은 하나뿐입니다.
    if (remainingOnes == 0) return 1;
    
    // 이미 계산된 값이 있다면, 그 값을 반환합니다.
    long long &result = dp[remainingOnes][remainingHalves];
    if (result != -1) return result;
    
    // 결과를 초기화합니다.
    result = 0;
    
    // 남아있는 1이 있다면, 1을 하나 빼고 0.5를 하나 추가합니다.
    if (remainingOnes > 0) {
        result += countDistinctStrings(remainingOnes - 1, remainingHalves + 1);
    }
    // 남아있는 0.5가 있다면, 0.5를 하나 뺍니다.
    if (remainingHalves > 0) {
        result += countDistinctStrings(remainingOnes, remainingHalves - 1);
    }
    
    // 결과를 반환합니다.
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    // 상자 안에 들어있는 숫자의 수를 입력받습니다.
    cin >> numOnes;
    
    // dp 배열을 -1로 초기화합니다.
    memset(dp, -1, sizeof(dp));
    
    // 가능한 서로 다른 문자열의 개수를 계산하고 출력합니다.
    cout << countDistinctStrings(numOnes - 1, 1) << "\n";
    
    return 0;
}