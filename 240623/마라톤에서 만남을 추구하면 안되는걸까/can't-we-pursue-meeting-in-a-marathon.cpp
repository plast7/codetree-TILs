#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100000

// 달리는 사람의 속력과 특정 시간 동안의 위치 정보를 저장할 구조체를 정의합니다.
struct Runner {
    long long speed;     // 속력
    long long modulus;   // 특정 시간 동안의 위치 정보 (modulus)
    int rank;            // BIT를 이용한 계산을 위해 매긴 순위
};

// 변수 선언
long long n, l, c;
Runner runners[MAX_N];
int bit[MAX_N + 1];
long long max_speed = 0;

// BIT(Binary Indexed Tree)를 초기화하는 함수입니다.
void bit_init(int n) {
    for(int i = 1; i <= n; i++) {
        bit[i] = 0;
    }
}

// BIT를 이용해 i번째까지의 합을 구하는 함수입니다.
int bit_prefix_sum(int i) {
    int sum = 0;
    for(int j = i; j > 0; j -= (j & (-j))) {
        sum += bit[j];
    }
    return sum;
}

// BIT를 이용해 i번째 값을 증가시키는 함수입니다.
void bit_inc(int i) {
    for(int j = i; j <= MAX_N; j += (j & (-j))) {
        bit[j]++;
    }
}

// Runner 구조체를 modulus 기준으로 정렬하기 위한 비교 함수입니다.
bool sort_by_modulus(const Runner& a, const Runner& b) {
    return a.modulus < b.modulus;
}

// Runner 구조체를 speed 기준으로 정렬하기 위한 비교 함수입니다.
bool sort_by_speed(const Runner& a, const Runner& b) {
    return a.speed < b.speed;
}

int main() {
    // 입력:
    cin >> n >> l >> c;
    for(int i = 0; i < n; i++) {
        cin >> runners[i].speed;
        if(runners[i].speed > max_speed) {
            max_speed = runners[i].speed;
        }
    }

    // 각 달리는 사람의 특정 시간 동안의 위치 정보를 계산합니다.
    for(int i = 0; i < n; i++) {
        runners[i].modulus = (l * c * runners[i].speed) % (c * max_speed);
    }

    // 위치 정보에 따라 정렬합니다.
    sort(runners, runners + n, sort_by_modulus);
    
    // 위치 정보가 같은 경우 동일한 순위를 매깁니다.
    int rank = 1;
    for(int i = 0; i < n; ) {
        int j = i;
        while(j < n && runners[i].modulus == runners[j].modulus) {
            runners[j++].rank = rank;
        }
        i = j;
        rank++;
    }

    // 속력에 따라 정렬합니다.
    sort(runners, runners + n, sort_by_speed);
    bit_init(n);

    // 총 만남 횟수를 계산합니다.
    long long total_meetings = 0;
    long long sum_of_floors = 0;

    for(int i = 0; i < n; i++) {
        long long floor = (l * runners[i].speed) / max_speed;
        long long addition = floor * i - sum_of_floors - i + bit_prefix_sum(runners[i].rank);

        total_meetings += addition;
        sum_of_floors += floor;
        bit_inc(runners[i].rank);
    }

    // 결과 출력:
    cout << total_meetings << endl;
    return 0;
}