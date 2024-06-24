#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100000

// 달리는 사람의 속도와 모듈러 값을 저장하는 구조체입니다.
struct Runner {
    long long speed;
    long long modulus;
    int rank;
};

// 변수 선언
int n, l, c;
Runner runners[MAX_N];
int bit[MAX_N + 1];
int bitlen;

// BIT 초기화 함수입니다.
void bit_init(int n) {
    for(int i = 1; i <= n; i++) {
        bit[i] = 0;
    }
    bitlen = n;
}

// BIT에서 i까지의 prefix sum을 구하는 함수입니다.
int bit_prefix_sum(int i) {
    int sum = 0;
    for(int j = i; j > 0; j -= (j & (-j))) {
        sum += bit[j];
    }
    return sum;
}

// BIT에서 i 위치의 값을 증가시키는 함수입니다.
void bit_inc(int i) {
    for(int j = i; j <= bitlen; j += (j & (-j))) {
        bit[j]++;
    }
}

// 모듈러 값을 기준으로 정렬하기 위한 비교 함수입니다.
bool sort_by_modulus(const Runner &a, const Runner &b) {
    return a.modulus < b.modulus;
}

// 속도를 기준으로 정렬하기 위한 비교 함수입니다.
bool sort_by_speed(const Runner &a, const Runner &b) {
    return a.speed < b.speed;
}

int main() {
    // 입력:
    cin >> n >> l >> c;

    long long max_speed = 0;
    for(int i = 0; i < n; i++) {
        cin >> runners[i].speed;
        if(runners[i].speed > max_speed) {
            max_speed = runners[i].speed;
        }
    }

    // 각 사람의 속도에 따른 모듈러 값을 계산합니다.
    for(int i = 0; i < n; i++) {
        runners[i].modulus = (l * c * runners[i].speed) % (c * max_speed);
    }
    // 모듈러 값을 기준으로 정렬합니다.
    sort(runners, runners + n, sort_by_modulus);

    // 모듈러 값에 따라 랭크를 부여합니다.
    int rank = 1;
    for(int i = 0; i < n; ) {
        int j = i;
        while(j < n && runners[i].modulus == runners[j].modulus) {
            runners[j].rank = rank;
            j++;
        }
        i = j;
        rank++;
    }

    // 속도를 기준으로 정렬합니다.
    sort(runners, runners + n, sort_by_speed);
    bit_init(n);

    long long total_meetings = 0;
    long long sum_of_floors = 0;
    for(int i = 0; i < n; i++) {
        // 현재 사람의 속도에 따른 floor 값을 계산합니다.
        long long floor = (l * runners[i].speed) / max_speed;
        // 현재 사람과 이전 사람들 간의 만남 횟수를 계산합니다.
        long long addition = floor * i - sum_of_floors - i + bit_prefix_sum(runners[i].rank);

        total_meetings += addition;

        sum_of_floors += floor;
        bit_inc(runners[i].rank);
    }

    // 총 만남 횟수를 출력합니다.
    cout << total_meetings << endl;
    return 0;
}