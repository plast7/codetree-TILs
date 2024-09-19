#include <bits/stdc++.h>
using namespace std;

// 체크포인트의 수와 건너뛸 체크포인트의 수를 저장할 변수
int num_checkpoints, skip_checkpoints;

// 체크포인트의 좌표를 저장할 벡터
vector<pair<int, int>> checkpoints(501);

// 두 체크포인트 간의 거리를 저장할 배열
int distance_matrix[501][501];

// 메모이제이션을 위한 배열
int memo[501][501];

// 최소 거리를 찾는 함수
int find_min_distance(int current_checkpoint, int remaining_skips) {
    // 메모이제이션 배열에서 이미 계산된 값이 있다면 그 값을 반환합니다.
    int &result = memo[current_checkpoint][remaining_skips];
    if (result != -1) return result;

    // 1번 체크포인트에 도달한 경우 거리는 0입니다.
    if (current_checkpoint == 1) return 0;

    // 초기값을 무한대로 설정합니다.
    result = INT_MAX;

    // 현재 체크포인트에서 건너뛸 수 있는 모든 경우를 탐색합니다.
    for (int i = 0; i <= remaining_skips; i++) {
        // 건너뛸 수 있는 체크포인트가 범위 내에 있는지 확인합니다.
        if (1 <= current_checkpoint - i - 1) {
            // 최소 거리를 갱신합니다.
            result = min(find_min_distance(current_checkpoint - i - 1, remaining_skips - i) + distance_matrix[current_checkpoint - i - 1][current_checkpoint], result);
        }
    }

    // 계산된 최소 거리를 반환합니다.
    return result;
}

int main() {
    // 입력을 받습니다.
    cin >> num_checkpoints >> skip_checkpoints;
    for (int i = 1; i <= num_checkpoints; i++) {
        cin >> checkpoints[i].first >> checkpoints[i].second;
    }

    // 메모이제이션 배열을 초기화합니다.
    memset(memo, -1, sizeof(memo));

    // 두 체크포인트 간의 거리를 계산하여 distance_matrix에 저장합니다.
    for (int i = 1; i <= num_checkpoints - 1; i++) {
        for (int j = i + 1; j <= num_checkpoints; j++) {
            distance_matrix[i][j] = abs(checkpoints[i].first - checkpoints[j].first) + abs(checkpoints[i].second - checkpoints[j].second);
        }
    }

    // 최소 거리를 계산하여 출력합니다.
    cout << find_min_distance(num_checkpoints, skip_checkpoints);
}