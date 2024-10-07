#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 격자 정보를 저장할 배열
char grid[50][50];
// 격자의 크기
int n, m;
// 각 돌 덩어리의 좌표를 저장할 벡터 배열
vector<pair<int, int>> clusters[3];
// 돌 덩어리의 개수를 저장할 변수
int cluster_count = 0;

// 주어진 좌표에서 연결된 돌 덩어리를 탐색하여 표시하는 함수
void markCluster(int x, int y, int cluster_num) {
    // 격자 범위를 벗어나거나 돌이 아닌 경우 반환
    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != 'X') return;
    // 방문한 돌은 'V'로 표시
    grid[x][y] = 'V';
    // 현재 돌의 좌표를 해당 클러스터에 추가
    clusters[cluster_num].emplace_back(x, y);
    // 상하좌우로 재귀적으로 탐색
    markCluster(x - 1, y, cluster_num);
    markCluster(x + 1, y, cluster_num);
    markCluster(x, y - 1, cluster_num);
    markCluster(x, y + 1, cluster_num);
}

// 두 점 사이의 맨해튼 거리를 계산하는 함수
int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// 주어진 좌표에 돌을 추가했을 때 필요한 최소 돌의 개수를 계산하는 함수
int calculateMinStones(int x, int y) {
    // 이미 방문한 곳이면 큰 값을 반환하여 무시
    if (grid[x][y] == 'V') return 1000;
    int total_distance = 0;
    // 각 클러스터에 대해
    for (int i = 0; i < 3; i++) {
        int min_distance = 101;
        // 클러스터 내의 모든 점과의 거리 중 최소값을 찾음
        for (const auto& point : clusters[i]) {
            int distance = manhattanDistance(point.first, point.second, x, y) - 1;
            min_distance = min(min_distance, distance);
        }
        // 최소 거리를 누적
        total_distance += min_distance;
    }
    // 총 거리 + 1을 반환
    return total_distance + 1;
}

int main() {
    // 입력 받기
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    // 각 돌 덩어리를 탐색하여 클러스터로 표시
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'X') {
                markCluster(i, j, cluster_count++);
            }
        }
    }

    // 최소 돌의 개수를 저장할 변수
    int min_stones = 301;
    // 모든 빈 공간에 대해 필요한 돌의 개수를 계산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int stones_needed = calculateMinStones(i, j);
            min_stones = min(min_stones, stones_needed);
        }
    }

    // 각 클러스터 간의 최소 거리 계산
    int min_pairwise[3];
    for (int i = 0; i < 3; i++) {
        min_pairwise[i] = 101;
        for (const auto& point1 : clusters[i]) {
            for (const auto& point2 : clusters[(i + 1) % 3]) {
                int distance = manhattanDistance(point1.first, point1.second, point2.first, point2.second) - 1;
                min_pairwise[i] = min(min_pairwise[i], distance);
            }
        }
    }

    // 두 클러스터 간의 최소 거리의 합을 계산하여 최소 돌의 개수 갱신
    for (int i = 0; i < 3; i++) {
        min_stones = min(min_stones, min_pairwise[i] + min_pairwise[(i + 1) % 3]);
    }

    // 결과 출력
    cout << min_stones << endl;

    return 0;
}