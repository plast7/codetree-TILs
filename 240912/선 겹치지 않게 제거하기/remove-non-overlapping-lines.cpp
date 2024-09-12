#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// dp[i] : i번째 점을 마지막으로 하는 가장 긴 증가 부분 수열의 길이
int dp[102];

int main() {
    int num_lines, point_a, point_b;
    int max_non_overlapping = 0;
    cin >> num_lines;
    
    // 선들을 저장할 벡터
    vector<pair<int, int>> lines;
    // 인덱싱을 쉽게 하기 위해 더미 라인을 추가합니다.
    lines.emplace_back(0, 0);
    
    // 선들의 정보를 입력받습니다.
    for (int i = 0; i < num_lines; i++) {
        cin >> point_a >> point_b;
        lines.emplace_back(point_a, point_b);
    }
    
    // x=a의 점 번호를 기준으로 선들을 정렬합니다.
    sort(lines.begin(), lines.end());
    
    // 가장 긴 증가 부분 수열을 찾습니다.
    for (int i = 1; i <= num_lines; i++) {
        for (int j = 0; j < i; j++) {
            // lines[i]의 y좌표가 lines[j]의 y좌표보다 큰 경우
            if (lines[i].second > lines[j].second) {
                // dp[i]를 갱신합니다.
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        // 가장 긴 증가 부분 수열의 길이를 갱신합니다.
        max_non_overlapping = max(max_non_overlapping, dp[i]);
    }
    
    // 제거해야 하는 최소한의 선의 개수를 출력합니다.
    cout << num_lines - max_non_overlapping << endl;
    return 0;
}