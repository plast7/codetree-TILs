#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 각 달리기 선수를 나타내는 구조체입니다.
struct Runner {
    long long speed;  // 속력
    long long modulus;  // (L * C * speed) % (C * max_speed) 값
    int rank;  // modulus 값에 따른 순위
};

int n, l, c;
vector<Runner> runners;
vector<int> bit;  // Binary Indexed Tree (BIT) 배열입니다.

// BIT 초기화 함수입니다.
void bit_init(int size) {
    bit.assign(size + 1, 0);
}

// BIT에서 index 위치의 값을 증가시키는 함수입니다.
void bit_inc(int index) {
    while (index < bit.size()) {
        bit[index]++;
        index += index & -index;
    }
}

// BIT에서 index 위치까지의 합을 구하는 함수입니다.
int bit_prefix_sum(int index) {
    int sum = 0;
    while (index > 0) {
        sum += bit[index];
        index -= index & -index;
    }
    return sum;
}

// modulus 값을 기준으로 정렬하기 위한 비교 함수입니다.
bool compare_by_modulus(const Runner &a, const Runner &b) {
    return a.modulus < b.modulus;
}

// speed 값을 기준으로 정렬하기 위한 비교 함수입니다.
bool compare_by_speed(const Runner &a, const Runner &b) {
    return a.speed < b.speed;
}

int main() {
    // 입력:
    cin >> n >> l >> c;
    runners.resize(n);
    long long max_speed = 0;

    // 각 선수의 속력을 입력받고, 최대 속력을 구합니다.
    for (int i = 0; i < n; ++i) {
        cin >> runners[i].speed;
        max_speed = max(max_speed, runners[i].speed);
    }

    // 각 선수의 modulus 값을 계산합니다.
    for (int i = 0; i < n; ++i) {
        runners[i].modulus = (l * c * runners[i].speed) % (c * max_speed);
    }

    // modulus 값을 기준으로 정렬합니다.
    sort(runners.begin(), runners.end(), compare_by_modulus);

    // modulus 값에 따른 순위를 매깁니다.
    int rank = 1;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && runners[i].modulus != runners[i - 1].modulus) {
            rank++;
        }
        runners[i].rank = rank;
    }

    // 속력 값을 기준으로 정렬합니다.
    sort(runners.begin(), runners.end(), compare_by_speed);

    // BIT를 초기화합니다.
    bit_init(rank);

    long long total_meetings = 0;
    long long sum_of_floors = 0;

    // 각 선수에 대해 만남 횟수를 계산합니다.
    for (int i = 0; i < n; ++i) {
        long long floor = (l * runners[i].speed) / max_speed;
        long long addition = floor * i - sum_of_floors - i + bit_prefix_sum(runners[i].rank);
        total_meetings += addition;
        sum_of_floors += floor;
        bit_inc(runners[i].rank);
    }

    // 결과를 출력합니다.
    cout << total_meetings << endl;

    return 0;
}