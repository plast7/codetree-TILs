#include <iostream>
#include <vector>

using namespace std;

// 인접 행렬을 사용하여 그래프를 표현합니다.
// 101 x 101 크기의 2차원 벡터를 생성하고, 모든 값을 0으로 초기화합니다.
vector<vector<int>> adjacency_matrix(101, vector<int>(101, 0));

// 방문 여부를 체크하기 위한 벡터를 생성하고, 모든 값을 0으로 초기화합니다.
vector<int> visited(101, 0);

// 노드의 총 개수를 저장할 변수와 1번 노드와 연결된 노드의 개수를 저장할 변수를 선언합니다.
int node_count, connected_node_count = 0;

// 깊이 우선 탐색(DFS)을 수행하는 함수입니다.
void depth_first_search(int node) {
    // 현재 노드를 방문했으므로, 연결된 노드의 개수를 증가시킵니다.
    connected_node_count++;
    // 현재 노드를 방문했음을 표시합니다.
    visited[node] = 1;
    // 모든 노드에 대해 인접한 노드를 탐색합니다.
    for (int i = 1; i <= node_count; i++) {
        // 현재 노드와 인접하고, 아직 방문하지 않은 노드에 대해 DFS를 재귀적으로 호출합니다.
        if (adjacency_matrix[node][i] && !visited[i]) {
            depth_first_search(i);
        }
    }
}

int main() {
    // 간선의 개수를 저장할 변수를 선언합니다.
    int edge_count;
    // 노드의 총 개수와 간선의 개수를 입력받습니다.
    cin >> node_count >> edge_count;
    // 각 간선에 대해 연결된 두 노드를 입력받고, 인접 행렬에 표시합니다.
    for (int i = 0; i < edge_count; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        // 무방향 그래프이므로, 양방향으로 연결을 표시합니다.
        adjacency_matrix[node1][node2] = adjacency_matrix[node2][node1] = 1;
    }

    // 1번 노드부터 DFS를 시작합니다.
    depth_first_search(1);
    // 1번 노드와 연결된 모든 노드의 개수를 출력합니다. 단, 자기 자신은 제외합니다.
    cout << connected_node_count - 1 << endl;
    return 0;
}