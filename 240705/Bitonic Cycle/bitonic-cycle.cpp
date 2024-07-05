#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

#define MAX_N 1000

using namespace std;

// 변수 선언
int n;
vector<pair<int, int> > points;

// dp[i][j] : 둘 다 시작점에서 출발하여 서로 겹치지 않게 점을 순서대로 선택하면서
//            하나는 i번 점에 있고, 나머지 하나는 j번 점에 있는 상황이 되었을 떄
//            지금까지 온 거리의 합 중 가능한 최솟값
long long dp[MAX_N][MAX_N];

// i번 점과 j번 점 사이의 거리를 계산합니다.
int Dist(int i, int j) {
    int x1, y1;
    int x2, y2;

    tie(x1, y1) = points[i];
    tie(x2, y2) = points[j];

    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    // 입력:
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    // x좌표 순으로 오름차순 정렬을 진행합니다.
    sort(points.begin(), points.end());
    
    // 최소를 구하는 문제이므로 
    // 처음에 dp값을 큰 값으로 설정합니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = (long long)1e16;

    // 초기조건을 설정합니다.
    // Bitonic Cycle 유형에서
    // 둘 다 시작점인 0번 점에 서있는 순간입니다.
    dp[0][0] = 0;

    // 뿌려주는 dp를 진행합니다.
    // 이는 이미 값이 구해져 있다는 가정 하에서
    // 그 다음 값을 갱신하는 형태입니다.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // 하나는 i번 점에 있고, 나머지 하나는 j번 점에 있는 상황에서
            // 그 다음 점으로의 이동을 고민해야 합니다.

            // dp[i][j] 값이 구해져있다는 가정 하에서
            // 그 다음 상황에 해당하는 값을 갱신해야합니다.

            // Bitonic Cycle 유형의 특성상
            // max(i, j)까지는 이미 전부 해결했기에
            // max(i, j) + 1번 점을 고려해야 하는 순간입니다.
            int next = max(i, j) + 1;

            // 이미 next가 n이면 더 이상 진행하지 않습니다.
            if(next == n)
                continue;
            
            // i번 점을 next로 이동하는 경우입니다.
            // 이 경우에는 i번 점과 next점 간의 거리만큼 더 더해줘야 합니다.
            // 이 경우를 기존 값과 비교하여 최솟값을 적어줍니다.
            dp[next][j] = min(dp[next][j], dp[i][j] + Dist(i, next));

            // j번 점을 next로 이동하는 경우입니다.
            // 이 경우에는 j번 점과 next점 간의 거리만큼 더 더해줘야 합니다.
            // 이 경우를 기존 값과 비교하여 최솟값을 적어줍니다.
            dp[i][next] = min(dp[i][next], dp[i][j] + Dist(j, next));
        }
    }

    // 여기서의 답은 둘 다 n - 1번 점으로 도착했을 상황이므로
    // 한 쪽이 n - 1인 경우에 대해서 
    // 다른 한 쪽을 n - 1로 바로 연결시켜주는 경우 중 최솟값을 구해줍니다.
    // 문제 특성상 dp[i][j]는 dp[j][i]와 값이 같을 것이므로
    // 답 계산시 한쪽만 고려해도 됩니다.
    long long ans = (long long)1e16;
    for(int i = 0; i < n - 1; i++)
        ans = min(ans, dp[i][n - 1] + Dist(i, n - 1));

    cout << ans;
    return 0;
}