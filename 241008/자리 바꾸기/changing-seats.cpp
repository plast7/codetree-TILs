#include <bits/stdc++.h>
using namespace std;

// 변수 선언
int num_people, num_swaps;
int swap_from[200001], swap_to[200001];
int position_after_swaps[100001];
vector<int> reachable_positions[100001];
int original_position[100001];
int position_count[100001];
int unique_positions_count;

// 특정 사람이 도달할 수 있는 자리들을 추가합니다.
void add_reachable_positions(int person) {
    for (int pos : reachable_positions[person]) {
        // 해당 자리에 처음 도달하는 경우, 고유한 자리의 개수를 증가시킵니다.
        if (position_count[pos] == 0)
            unique_positions_count++;
        position_count[pos]++;
    }
}

// 특정 사람이 도달할 수 있는 자리들을 제거합니다.
void remove_reachable_positions(int person) {
    for (int pos : reachable_positions[person]) {
        // 해당 자리에서 마지막으로 빠져나가는 경우, 고유한 자리의 개수를 감소시킵니다.
        if (position_count[pos] == 1)
            unique_positions_count--;
        position_count[pos]--;
    }
}

bool visited[100001];
queue<int> cycle_queue;

// 깊이 우선 탐색을 통해 사이클을 찾고, 각 사람의 도달 가능한 자리를 계산합니다.
void dfs(int person) {
    visited[person] = true;
    add_reachable_positions(person);
    cycle_queue.push(person);
    if (!visited[position_after_swaps[person]])
        dfs(position_after_swaps[person]);
}

int main() {
    // 입력 받기
    cin >> num_people >> num_swaps;
    for (int i = 0; i < num_swaps; i++)
        cin >> swap_from[i] >> swap_to[i];

    // 초기 설정: 각 사람의 원래 자리를 기록합니다.
    for (int i = 1; i <= num_people; i++) {
        original_position[i] = i;
        reachable_positions[i].push_back(i);
    }

    // 각 스왑에 대해 도달 가능한 자리를 업데이트합니다.
    for (int i = 0; i < num_swaps; i++) {
        reachable_positions[original_position[swap_from[i]]].push_back(swap_to[i]);
        reachable_positions[original_position[swap_to[i]]].push_back(swap_from[i]);
        swap(original_position[swap_from[i]], original_position[swap_to[i]]);
    }

    // 스왑 후의 위치를 기록합니다.
    for (int i = 1; i <= num_people; i++)
        position_after_swaps[original_position[i]] = i;

    int result[100001];
    // 각 사람에 대해 사이클을 찾아 도달 가능한 자리의 개수를 계산합니다.
    for (int i = 1; i <= num_people; i++) {
        if (!visited[i]) {
            dfs(i);
            int temp_result = unique_positions_count;
            while (!cycle_queue.empty()) {
                remove_reachable_positions(cycle_queue.front());
                result[cycle_queue.front()] = temp_result;
                cycle_queue.pop();
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= num_people; i++)
        cout << result[i] << endl;

    return 0;
}