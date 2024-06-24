#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100000

// 달리는 사람의 속도와 위치를 저장하는 구조체입니다.
struct Runner {
    long long speed;  // 속도
    long long position;  // 위치
    int rank;  // 순위
};

// BIT (Binary Indexed Tree) 배열과 길이를 정의합니다.
int bit[MAX_N + 1];
int bitlen;

// BIT를 초기화하는 함수입니다.
void bit_init(int n) {
    for(int i = 1; i <= n; i++) {
        bit[i] = 0;
    }
    bitlen = n;
}

// BIT의 prefix sum을 구하는 함수입니다.
int bit_prefix_sum(int i) {
    int sum = 0;
    for(int j = i; j > 0; j -= (j & (-j))) {
        sum += bit[j];
    }
    return sum;
}

// BIT의 값을 증가시키는 함수입니다.
void bit_inc(int i) {
    for(int j = i; j <= bitlen; j += (j & (-j))) {
        bit[j]++;
    }
}

// 위치를 기준으로 정렬하기 위한 비교 함수입니다.
bool compare_by_position(const Runner& a, const Runner& b) {
    return a.position < b.position;
}

// 속도를 기준으로 정렬하기 위한 비교 함수입니다.
bool compare_by_speed(const Runner& a, const Runner& b) {
    return a.speed < b.speed;
}

int main() {
    int n, l, c;
    cin >> n >> l >> c;

    vector<Runner> runners(n);
    long long max_speed = 0;

    // 각 달리는 사람의 속도를 입력받습니다.
    for(int i = 0; i < n; i++) {
        cin >> runners[i].speed;
        if(runners[i].speed > max_speed) {
            max_speed = runners[i].speed;
        }
    }

    // 각 달리는 사람의 위치를 계산합니다.
    for(int i = 0; i < n; i++) {
        runners[i].position = (l * c * runners[i].speed) % (c * max_speed);
    }

    // 위치를 기준으로 달리는 사람들을 정렬합니다.
    sort(runners.begin(), runners.end(), compare_by_position);

    // 순위를 매깁니다.
    int rank = 1;
    for(int i = 0; i < n; i++) {
        if(i > 0 && runners[i].position != runners[i - 1].position) {
            rank++;
        }
        runners[i].rank = rank;
    }

    // 속도를 기준으로 달리는 사람들을 정렬합니다.
    sort(runners.begin(), runners.end(), compare_by_speed);
    bit_init(n);

    long long total_meetings = 0;
    long long sum_of_floors = 0;

    // 각 달리는 사람에 대해 만남의 횟수를 계산합니다.
    for(int i = 0; i < n; i++) {
        long long floor = (l * runners[i].speed) / max_speed;
        long long addition = floor * i - sum_of_floors - i + bit_prefix_sum(runners[i].rank);

        total_meetings += addition;
        sum_of_floors += floor;
        bit_inc(runners[i].rank);
    }

    // 총 만남의 횟수를 출력합니다.
    cout << total_meetings << endl;
    return 0;
}