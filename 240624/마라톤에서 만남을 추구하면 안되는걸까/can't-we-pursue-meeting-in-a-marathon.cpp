#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100005

// 펜윅 트리 배열과 길이를 정의합니다.
int fenwick_tree[MAX_N];
int fenwick_length;

// 달리는 사람의 정보를 담는 구조체를 정의합니다.
struct Runner {
    long long speed; // 속력
    long long position_modulus; // 위치 모듈러 값
    int rank; // 랭크
};

// 달리는 사람들의 정보를 담는 벡터를 정의합니다.
vector<Runner> runners(MAX_N);
long long max_speed = 0; // 최대 속력
long long num_runners, num_laps, track_length; // 달리는 사람 수, 랩 수, 트랙 길이

// 펜윅 트리를 초기화하는 함수입니다.
void initialize_fenwick_tree(int n) {
    fill(fenwick_tree, fenwick_tree + n + 1, 0);
    fenwick_length = n;
}

// 펜윅 트리의 prefix sum을 구하는 함수입니다.
int fenwick_prefix_sum(int i) {
    int sum = 0;
    for (int j = i; j > 0; j -= (j & (-j))) {
        sum += fenwick_tree[j];
    }
    return sum;
}

// 펜윅 트리의 값을 증가시키는 함수입니다.
void fenwick_increment(int i) {
    for (int j = i; j <= fenwick_length; j += (j & (-j))) {
        fenwick_tree[j]++;
    }
}

// 위치 모듈러 값을 기준으로 정렬하는 함수입니다.
bool compare_by_modulus(const Runner& a, const Runner& b) {
    return a.position_modulus < b.position_modulus;
}

// 속력을 기준으로 정렬하는 함수입니다.
bool compare_by_speed(const Runner& a, const Runner& b) {
    return a.speed < b.speed;
}

int main() {
    // 입력을 받습니다.
    cin >> num_runners >> num_laps >> track_length;

    for (int i = 0; i < num_runners; i++) {
        cin >> runners[i].speed;
        if (runners[i].speed > max_speed) {
            max_speed = runners[i].speed;
        }
    }

    // 각 달리는 사람의 위치 모듈러 값을 계산합니다.
    for (int i = 0; i < num_runners; i++) {
        runners[i].position_modulus = (num_laps * track_length * runners[i].speed) % (track_length * max_speed);
    }

    // 위치 모듈러 값을 기준으로 정렬합니다.
    sort(runners.begin(), runners.begin() + num_runners, compare_by_modulus);

    // 랭크를 매깁니다.
    int current_index = 0;
    int rank = 1;
    while (current_index < num_runners) {
        int next_index = current_index + 1;
        while (next_index < num_runners && runners[current_index].position_modulus == runners[next_index].position_modulus) {
            next_index++;
        }
        for (int i = current_index; i < next_index; i++) {
            runners[i].rank = rank;
        }
        current_index = next_index;
        rank++;
    }

    // 속력을 기준으로 정렬합니다.
    sort(runners.begin(), runners.begin() + num_runners, compare_by_speed);
    initialize_fenwick_tree(num_runners);

    long long total_meetings = 0;
    long long sum_of_floors = 0;
    for (int i = 0; i < num_runners; i++) {
        long long floor_value = (num_laps * runners[i].speed) / max_speed;
        long long additional_meetings = floor_value * i - sum_of_floors - i + fenwick_prefix_sum(runners[i].rank);

        total_meetings += additional_meetings;

        sum_of_floors += floor_value;
        fenwick_increment(runners[i].rank);
    }

    // 총 만남의 횟수를 출력합니다.
    cout << total_meetings << endl;
    return 0;
}