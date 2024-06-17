#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100005

// BIT 배열을 선언합니다.
int bit[MAX_N];
int bitlen;

// BIT를 초기화합니다.
inline void bit_init(int n) {
    for(int i = 1; i <= n; i++) {
        bit[i] = 0;
    }
    bitlen = n;
}

// BIT에서 i번째까지의 prefix sum을 구합니다.
inline int bit_prefix_sum(int i) {
    int sum = 0;
    for(int j = i; j > 0; j -= (j & (-j))) {
        sum += bit[j];
    }
    return sum;
}

// BIT에서 i번째 값을 증가시킵니다.
inline void bit_inc(int i) {
    for(int j = i; j <= bitlen; j += (j & (-j))) {
        bit[j]++;
    }
}

// 사람의 속도 및 모듈러 값을 저장하는 구조체 입니다.
struct Person {
    long long speed;
    long long modulus;
    int rank;
};

Person people[MAX_N];
long long max_speed = 0;
long long n, l, c;

// 모듈러 값을 기준으로 정렬하기 위한 비교 함수입니다.
inline bool sort_person_by_modulus(const Person& a, const Person& b) {
    return a.modulus < b.modulus;
}

// 속도를 기준으로 정렬하기 위한 비교 함수입니다.
inline bool sort_person_by_speed(const Person& a, const Person& b) {
    return a.speed < b.speed;
}

int main() {
    // 입력을 받습니다.
    cin >> n >> l >> c;
    for(int i = 0; i < n; i++) {
        cin >> people[i].speed;
        if(people[i].speed > max_speed) {
            max_speed = people[i].speed;
        }
    }

    // 각 사람의 모듈러 값을 계산합니다.
    for(int i = 0; i < n; i++) {
        people[i].modulus = (l * c * people[i].speed) % (c * max_speed);
    }

    // 모듈러 값을 기준으로 정렬합니다.
    sort(people, people + n, sort_person_by_modulus);

    // 모듈러 값에 따라 랭크를 부여합니다.
    int a = 0;
    int rank = 1;
    while(a < n) {
        int b = a + 1;
        while(b < n && people[a].modulus == people[b].modulus) {
            b++;
        }
        for(int i = a; i < b; i++) {
            people[i].rank = rank;
        }
        a = b;
        rank++;
    }

    // 속도를 기준으로 정렬합니다.
    sort(people, people + n, sort_person_by_speed);

    // BIT를 초기화합니다.
    bit_init(n);

    long long total_meetings = 0;
    long long sum_of_floors = 0;

    // 사람들을 순회하면서 만남의 횟수를 계산합니다.
    for(int i = 0; i < n; i++) {
        long long floor = (l * people[i].speed) / max_speed;
        long long addition = floor * i - sum_of_floors - i + bit_prefix_sum(people[i].rank);

        total_meetings += addition;

        sum_of_floors += floor;
        bit_inc(people[i].rank);
    }

    // 결과를 출력합니다.
    cout << total_meetings << endl;

    return 0;
}