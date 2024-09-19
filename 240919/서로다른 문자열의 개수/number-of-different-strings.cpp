#include <iostream>
#include <cstring>
 
using namespace std;

// 상자 안에 들어있는 숫자 1의 개수를 저장하는 변수입니다.
int numOnes;

// 메모이제이션을 위한 배열입니다. memoization[i][j]는 i개의 1과 j개의 0이 남아있을 때 가능한 서로 다른 문자열의 개수를 저장합니다.
long long memoization[61][61];

// 남아있는 1의 개수와 0의 개수를 인자로 받아 가능한 서로 다른 문자열의 개수를 계산하는 함수입니다.
long long countDistinctStrings(int remainingOnes, int remainingZeros) {
    // 남아있는 1의 개수가 0이라면, 더 이상 1을 꺼낼 수 없으므로 가능한 문자열은 1개입니다.
    if (remainingOnes == 0) return 1;
    
    // 메모이제이션 배열에서 이미 계산된 값이 있다면 그 값을 반환합니다.
    long long &result = memoization[remainingOnes][remainingZeros];
    if (result != -1) return result;
    
    // 결과 값을 0으로 초기화합니다.
    result = 0;
    
    // 남아있는 1의 개수가 0보다 크다면, 1을 꺼내고 0을 넣는 경우를 고려합니다.
    if (remainingOnes > 0) {
        result += countDistinctStrings(remainingOnes - 1, remainingZeros + 1);
    }
    // 남아있는 0의 개수가 0보다 크다면, 0을 꺼내는 경우를 고려합니다.
    if (remainingZeros > 0) {
        result += countDistinctStrings(remainingOnes, remainingZeros - 1);
    }
    
    // 계산된 결과 값을 반환합니다.
    return result;
}
 
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    
    // 상자 안에 들어있는 숫자 1의 개수를 입력받습니다.
    cin >> numOnes;
    
    // 메모이제이션 배열을 -1로 초기화합니다.
    memset(memoization, -1, sizeof(memoization));
    
    // 가능한 서로 다른 문자열의 개수를 계산하여 출력합니다.
    cout << countDistinctStrings(numOnes - 1, 1) << "\n";
    
    return 0;
}