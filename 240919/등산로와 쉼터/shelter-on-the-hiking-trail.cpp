#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 각 쉼터와 연결된 쉼터들을 저장하는 인접 리스트입니다.
vector<int> adj[5005];

// dp[i]는 i번 쉼터에서 시작하여 방문할 수 있는 최대 쉼터의 개수를 저장합니다.
int dp[5005];

// 각 쉼터의 높이를 저장합니다.
int heights[5005];

// 현재 쉼터에서 시작하여 방문할 수 있는 최대 쉼터의 개수를 계산하는 함수입니다.
int dfs(int current) {
    // 이미 계산된 값이 있다면 그 값을 반환합니다.
    if (dp[current] != 0)
        return dp[current];

    // 인접한 쉼터들을 탐색합니다.
    for (int next : adj[current])
        // 인접한 쉼터에서 시작하는 최대 쉼터의 개수를 계산하여 현재 쉼터의 dp 값을 갱신합니다.
        dp[current] = max(dp[current], dfs(next));
    
    // 현재 쉼터를 포함하여 개수를 세기 위해 1을 더합니다.
    return (++dp[current]);
}

int main() {
    int numShelters, numPaths;
    cin >> numShelters >> numPaths;

    // 각 쉼터의 높이를 입력받습니다.
    for (int i = 1; i <= numShelters; i++)
        cin >> heights[i];

    // 각 길을 입력받아 인접 리스트를 구성합니다.
    for (int i = 0; i < numPaths; i++) {
        int shelterA, shelterB;
        cin >> shelterA >> shelterB;

        // 높이가 낮은 쉼터에서 높은 쉼터로 가는 방향으로 인접 리스트를 구성합니다.
        if (heights[shelterA] < heights[shelterB])
            adj[shelterA].push_back(shelterB);
        else
            adj[shelterB].push_back(shelterA);
    }

    // 각 쉼터에서 시작하여 방문할 수 있는 최대 쉼터의 개수를 출력합니다.
    for (int i = 1; i <= numShelters; i++)
        cout << dfs(i) << "\n";
    
    return 0;
}