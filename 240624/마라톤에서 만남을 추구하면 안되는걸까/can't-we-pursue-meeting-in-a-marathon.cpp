#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 100005

// 펜윅 트리 배열과 크기를 정의합니다.
int fenwick_tree[MAX_N];
int fenwick_tree_size;

// 펜윅 트리를 초기화하는 함수입니다.
inline void fenwick_tree_init(int n) {
    for(int i = 1; i <= n; i++) {
        fenwick_tree[i] = 0;
    }
    fenwick_tree_size = n;
}

// 펜윅 트리에서 i번째 위치까지의 prefix sum을 구하는 함수입니다.
inline int fenwick_tree_prefix_sum(int i) {
    int sum = 0;
    for(int j = i; j > 0; j -= (j & (-j))) {
        sum += fenwick_tree[j];
    }
    return sum;
}

// 펜윅 트리에서 i번째 위치의 값을 증가시키는 함수입니다.
inline void fenwick_tree_increment(int i) {
    for(int j = i; j <= fenwick_tree_size; j += (j & (-j))) {
        fenwick_tree[j]++;
    }
}

// Runner 구조체를 정의합니다.
struct Runner {
    long long speed;
    long long modulus;
    int rank;
};

// 전역 변수들을 정의합니다.
Runner runners[MAX_N];
long long max_speed = 0;
long long num_runners, num_laps, track_length;

// modulus 값을 기준으로 정렬하기 위한 비교 함수입니다.
inline bool compare_by_modulus(const Runner& a, const Runner& b) {
    return a.modulus < b.modulus;
}

// speed 값을 기준으로 정렬하기 위한 비교 함수입니다.
inline bool compare_by_speed(const Runner& a, const Runner& b) {
    return a.speed < b.speed;
}

int main() {
    // 입력을 받습니다.
    cin >> num_runners >> num_laps >> track_length;

    // 각 주자의 속력을 입력받고 최대 속력을 갱신합니다.
    for(int i = 0; i < num_runners; i++) {
        cin >> runners[i].speed;
        if(runners[i].speed > max_speed) {
            max_speed = runners[i].speed;
        }
    }

    // 각 주자의 modulus 값을 계산합니다.
    for(int i = 0; i < num_runners; i++) {
        runners[i].modulus = (num_laps * track_length * runners[i].speed) % (track_length * max_speed);
    }
    // modulus 값을 기준으로 정렬합니다.
    sort(runners, runners + num_runners, compare_by_modulus);

    // modulus 값이 같은 주자들에게 같은 rank를 부여합니다.
    int current_index = 0;
    int rank = 1;
    while(current_index < num_runners) {
        int next_index = current_index + 1;
        while(next_index < num_runners && runners[current_index].modulus == runners[next_index].modulus) {
            next_index++;
        }
        for(int i = current_index; i < next_index; i++) {
            runners[i].rank = rank;
        }
        current_index = next_index;
        rank++;
    }

    // speed 값을 기준으로 정렬합니다.
    sort(runners, runners + num_runners, compare_by_speed);
    // 펜윅 트리를 초기화합니다.
    fenwick_tree_init(num_runners);

    long long total_meetings = 0;
    long long sum_of_floors = 0;
    // 각 주자에 대해 만나게 되는 횟수를 계산합니다.
    for(int i = 0; i < num_runners; i++) {
        long long floor_value = (num_laps * runners[i].speed) / max_speed;
        long long additional_meetings = floor_value * i - sum_of_floors - i + fenwick_tree_prefix_sum(runners[i].rank);

        total_meetings += additional_meetings;

        sum_of_floors += floor_value;
        fenwick_tree_increment(runners[i].rank);
    }

    // 결과를 출력합니다.
    cout << total_meetings << endl;
    return 0;
}