#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 물건의 크기를 저장하는 벡터
vector<int> item_sizes(20001);
// 최소 비용을 저장하는 벡터
vector<long long> min_cost(21001, -1);
// 물건의 개수, 상자에 넣을 수 있는 최대 물건 개수, 포장비
int num_items, max_items_per_box, packaging_cost;

// 두 값 중 작은 값을 반환하는 함수
long long get_min_cost(long long a, long long b) {
    return a < b ? a : b;
}

// start부터 end까지의 물건을 포장하는 최소 비용을 계산하는 함수
long long calculate_cost(int start, int end) {
    // 현재 구간의 최소 비용을 가리키는 포인터
    long long *current_cost = &min_cost[start];
    // 현재 구간의 최대 크기와 최소 크기
    int max_size = 0, min_size = INT_MAX;
    // 현재 상자의 비용
    long long box_cost;

    // 시작 위치가 끝 위치보다 크거나 같으면 비용은 0
    if (start >= end) return 0;
    // 이미 계산된 최소 비용이 있으면 그 값을 반환
    if (*current_cost != -1) return *current_cost;

    // 초기 최소 비용을 매우 큰 값으로 설정
    *current_cost = LLONG_MAX;
    // 상자에 넣을 수 있는 물건의 최대 개수
    int size_limit = min(max_items_per_box, end - start + 1);
    // 상자에 물건을 하나씩 추가하면서 최소 비용을 계산
    for (int i = 0; i < size_limit; i++) {
        // 현재 물건의 크기를 최대 크기와 최소 크기와 비교하여 갱신
        if (max_size < item_sizes[start + i]) max_size = item_sizes[start + i];
        if (min_size > item_sizes[start + i]) min_size = item_sizes[start + i];
        // 현재 상자의 비용을 계산
        box_cost = 1LL * (i + 1) * (max_size - min_size) + packaging_cost;
        // 현재 구간의 최소 비용을 갱신
        *current_cost = get_min_cost(*current_cost, box_cost + calculate_cost(start + i + 1, end));
    }
    return *current_cost;
}

int main() {
    // 입력 받기
    cin >> num_items >> max_items_per_box >> packaging_cost;

    for (int i = 0; i < num_items; i++) {
        cin >> item_sizes[i];
    }

    // 모든 물건을 포장하는 최소 비용을 출력
    cout << calculate_cost(0, num_items) << endl;
    return 0;
}