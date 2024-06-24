#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100000

// 주자의 속력과 위치를 저장하는 구조체입니다.
struct Runner {
    long long speed;
    long long position;
};

// 전역 변수 선언
int N, L, C;
vector<Runner> runners;

int main() {
    // 입력:
    cin >> N >> L >> C;
    runners.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> runners[i].speed;
    }

    // 최대 속력을 찾습니다.
    long long max_speed = 0;
    for (int i = 0; i < N; i++) {
        if (runners[i].speed > max_speed) {
            max_speed = runners[i].speed;
        }
    }

    // 각 주자의 모듈러 값을 계산합니다.
    for (int i = 0; i < N; i++) {
        runners[i].position = (L * C * runners[i].speed) % (C * max_speed);
    }

    // 모듈러 값으로 주자들을 정렬합니다.
    sort(runners.begin(), runners.end(), [](const Runner &a, const Runner &b) {
        return a.position < b.position;
    });

    // 같은 모듈러 값을 가진 주자들에게 같은 rank를 부여합니다.
    vector<int> ranks(N);
    int rank = 1;
    for (int i = 0; i < N; i++) {
        if (i > 0 && runners[i].position != runners[i - 1].position) {
            rank++;
        }
        ranks[i] = rank;
    }

    // 속도로 주자들을 정렬합니다.
    sort(runners.begin(), runners.end(), [](const Runner &a, const Runner &b) {
        return a.speed < b.speed;
    });

    // BIT 초기화
    vector<int> bit(N + 1, 0);
    auto bit_inc = [&](int i) {
        for (; i <= N; i += i & -i) {
            bit[i]++;
        }
    };
    auto bit_prefix_sum = [&](int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    };

    long long total = 0;
    long long sum_of_floors = 0;

    // 각 주자에 대해 만나게 되는 횟수를 계산합니다.
    for (int i = 0; i < N; i++) {
        long long floor = (L * runners[i].speed) / max_speed;
        long long addition = floor * i - sum_of_floors - i + bit_prefix_sum(ranks[i]);

        total += addition;

        sum_of_floors += floor;
        bit_inc(ranks[i]);
    }

    // 결과를 출력합니다.
    cout << total << endl;

    return 0;
}