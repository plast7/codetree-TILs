#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 1001

int n, m;

vector<int> map[MAX_N];
bool visited[MAX_N];
queue<int> q;
vector<pair<int, int>> v;
int cnt = 0; // 갈 수 있는 노드의 수

// DFS 탐색을 통해 주어진 노드 v로부터 갈 수 있는 노드의 수를 계산합니다.
void DFS(int v) {
    visited[v] = true;
    cnt++;

    // v로부터 이동 가능한 모든 노드에 대해 탐색합니다.
    for (int w = 0; w < map[v].size(); w++) {
        int nv = map[v][w];

        if (visited[nv] == 0) {
            visited[nv] = true;
            DFS(nv);
        }
    }
}

// visited 배열을 초기화합니다.
void resetVisit() {
    for (int i = 0; i <= n; i++) {
        visited[i] = 0;
    }
}

int main() {
    cin >> n >> m;
    // 그래프 정보를 입력받습니다.
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
    }

    // 각 노드를 시작점으로 하여 DFS를 수행합니다.
    for (int i = 1; i <= n; i++) {
        cnt = 0;
        DFS(i);
        resetVisit();
        v.push_back(make_pair(i, cnt));
    }

    // 갈 수 있는 최대 노드 수를 구합니다.
    int maxNode = -1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second > maxNode) {
            maxNode = v[i].second;
        }
    }

    // 갈 수 있는 최대 노드 수에 해당하는 노드 번호를 출력합니다.
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second == maxNode) {
            cout << v[i].first << " ";
        }
    }
}