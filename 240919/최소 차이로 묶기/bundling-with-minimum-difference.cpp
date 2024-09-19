#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

// 최대값 상수를 정의합니다.
const int MAX = 1000000007;

// 수열 a와 b의 원소 개수를 저장할 변수입니다.
int num_elements_a, num_elements_b;

// dp 배열을 정의합니다. dp[i][j]는 a의 i번째 원소와 b의 j번째 원소까지 고려했을 때의 최소 차이 합을 저장합니다.
int dp[1234][1234];

// 두 수열을 저장할 배열입니다.
int sequences[2][1234];

// 최소 차이 합을 찾는 재귀 함수입니다.
int find_min_difference(int index_a, int index_b) {
    // a의 인덱스가 음수인 경우, 더 이상 고려할 원소가 없으므로 0을 반환합니다.
    if (index_a < 0) return 0;
    // b의 인덱스가 음수인 경우, 유효하지 않은 상태이므로 최대값을 반환합니다.
    if (index_b < 0) return MAX;

    // dp 배열에 저장된 값이 있다면, 그 값을 반환합니다.
    int &result = dp[index_a][index_b];
    if (result != -1) return result;
    result = MAX;

    // 현재 원소의 차이를 계산하고, 다음 원소로 넘어갑니다.
    result = min(result, abs(sequences[0][index_a] - sequences[1][index_b]) + find_min_difference(index_a - 1, index_b - 1));
    // b의 다음 원소로 넘어가면서 최소값을 갱신합니다.
    result = min(result, find_min_difference(index_a, index_b - 1));

    return result;
}

int main() {
    // dp 배열을 -1로 초기화합니다.
    memset(dp, -1, sizeof dp);
    
    // 수열 a와 b의 원소 개수를 입력받습니다.
    cin >> num_elements_a >> num_elements_b;
    
    // 수열 a의 원소를 입력받습니다.
    for (int i = 0; i < num_elements_a; i++) cin >> sequences[0][i];
    
    // 수열 b의 원소를 입력받습니다.
    for (int i = 0; i < num_elements_b; i++) cin >> sequences[1][i];

    // 수열 a와 b를 오름차순으로 정렬합니다.
    sort(sequences[0], sequences[0] + num_elements_a);
    sort(sequences[1], sequences[1] + num_elements_b);

    // 수열 b의 원소 개수가 수열 a의 원소 개수보다 작다면, 두 수열을 교환합니다.
    if (num_elements_b < num_elements_a) {
        swap(num_elements_a, num_elements_b);
        swap(sequences[0], sequences[1]);
    }

    // 최소 차이 합을 출력합니다.
    cout << find_min_difference(num_elements_a - 1, num_elements_b - 1) << endl;

    return 0;
}