#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 달리는 사람의 정보를 담는 구조체입니다.
struct Runner {
    long long speed; // 속력
    long long modulus; // 속력에 대한 모듈러 연산 결과
    int rank; // 속력에 대한 순위
};

const int MAX_N = 100000;
vector<Runner> runners(MAX_N);
vector<int> BIT(MAX_N + 1, 0);
int N, L, C;
long long max_speed = 0;

// BIT를 업데이트하는 함수입니다.
void updateBIT(int index, int value) {
    while (index <= N) {
        BIT[index] += value;
        index += index & -index;
    }
}

// BIT에서 값을 조회하는 함수입니다.
int queryBIT(int index) {
    int sum = 0;
    while (index > 0) {
        sum += BIT[index];
        index -= index & -index;
    }
    return sum;
}

// 모듈러 연산 결과를 기준으로 정렬하기 위한 비교 함수입니다.
bool compareByModulus(const Runner &a, const Runner &b) {
    return a.modulus < b.modulus;
}

// 속력을 기준으로 정렬하기 위한 비교 함수입니다.
bool compareBySpeed(const Runner &a, const Runner &b) {
    return a.speed < b.speed;
}

int main() {
    // 입력:
    cin >> N >> L >> C;

    // 각 사람의 속력을 입력받습니다.
    for (int i = 0; i < N; i++) {
        cin >> runners[i].speed;
        if (runners[i].speed > max_speed) {
            max_speed = runners[i].speed;
        }
    }

    // 각 사람의 속력에 대해 모듈러 연산 결과를 계산합니다.
    for (int i = 0; i < N; i++) {
        runners[i].modulus = (L * C * runners[i].speed) % (C * max_speed);
    }

    // 모듈러 연산 결과를 기준으로 정렬합니다.
    sort(runners.begin(), runners.begin() + N, compareByModulus);

    // 모듈러 연산 결과에 따라 순위를 매깁니다.
    int rank = 1;
    for (int i = 0; i < N; i++) {
        if (i > 0 && runners[i].modulus != runners[i - 1].modulus) {
            rank++;
        }
        runners[i].rank = rank;
    }

    // 속력을 기준으로 정렬합니다.
    sort(runners.begin(), runners.begin() + N, compareBySpeed);

    long long total_meetings = 0;
    long long sum_of_floors = 0;

    // 각 사람에 대해 만남의 횟수를 계산합니다.
    for (int i = 0; i < N; i++) {
        long long floor = (L * runners[i].speed) / max_speed;
        long long addition = floor * i - sum_of_floors - i + queryBIT(runners[i].rank);
        total_meetings += addition;
        sum_of_floors += floor;
        updateBIT(runners[i].rank, 1);
    }

    // 결과를 출력합니다.
    cout << total_meetings << endl;

    return 0;
}