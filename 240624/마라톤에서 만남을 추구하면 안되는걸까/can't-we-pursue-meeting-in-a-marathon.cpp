#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100000

// 달리는 사람의 정보를 담는 구조체입니다.
struct Runner {
    long long speed;   // 속력
    long long position; // 위치
    int rank;          // 순위
};

// 달리는 사람들을 저장할 벡터입니다.
vector<Runner> runners;

// BIT(Binary Indexed Tree)를 사용하여 순위별로 만남 횟수를 계산합니다.
int bit[MAX_N + 1];
int bit_len;

// BIT를 초기화하는 함수입니다.
void initializeBIT(int n) {
    fill(bit, bit + n + 1, 0);
    bit_len = n;
}

// BIT에서 i까지의 prefix sum을 구하는 함수입니다.
int getPrefixSum(int i) {
    int sum = 0;
    while (i > 0) {
        sum += bit[i];
        i -= (i & -i);
    }
    return sum;
}

// BIT에서 i번째 값을 증가시키는 함수입니다.
void incrementBIT(int i) {
    while (i <= bit_len) {
        bit[i]++;
        i += (i & -i);
    }
}

// 위치를 기준으로 정렬하기 위한 비교 함수입니다.
bool compareByPosition(const Runner& a, const Runner& b) {
    return a.position < b.position;
}

// 속력을 기준으로 정렬하기 위한 비교 함수입니다.
bool compareBySpeed(const Runner& a, const Runner& b) {
    return a.speed < b.speed;
}

int main() {
    int n, l, c;
    cin >> n >> l >> c;

    // 달리는 사람들의 정보를 입력받습니다.
    runners.resize(n);
    long long max_speed = 0;

    for (int i = 0; i < n; ++i) {
        cin >> runners[i].speed;
        if (runners[i].speed > max_speed) {
            max_speed = runners[i].speed;
        }
    }

    // 각 사람의 위치를 계산합니다.
    for (int i = 0; i < n; ++i) {
        runners[i].position = (l * c * runners[i].speed) % (c * max_speed);
    }

    // 위치를 기준으로 정렬합니다.
    sort(runners.begin(), runners.end(), compareByPosition);

    // 순위를 매깁니다.
    int rank = 1;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && runners[i].position != runners[i - 1].position) {
            rank++;
        }
        runners[i].rank = rank;
    }

    // 속력을 기준으로 정렬합니다.
    sort(runners.begin(), runners.end(), compareBySpeed);

    // BIT를 초기화합니다.
    initializeBIT(n);

    long long total_meetings = 0;
    long long sum_of_floors = 0;

    // 각 사람에 대해 만남 횟수를 계산합니다.
    for (int i = 0; i < n; ++i) {
        long long floor = (l * runners[i].speed) / max_speed;
        long long addition = floor * i - sum_of_floors - i + getPrefixSum(runners[i].rank);
        
        total_meetings += addition;
        sum_of_floors += floor;
        incrementBIT(runners[i].rank);
    }

    // 총 만남 횟수를 출력합니다.
    cout << total_meetings << endl;

    return 0;
}