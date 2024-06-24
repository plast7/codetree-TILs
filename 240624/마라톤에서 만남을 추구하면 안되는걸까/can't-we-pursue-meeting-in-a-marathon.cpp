#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100000

struct Runner {
    long long speed;
    long long position;
};

int N, L, C;
vector<Runner> runners;

int main() {
    // 입력:
    cin >> N >> L >> C;
    runners.resize(N);

    // 각 사람의 속력을 입력받습니다.
    for (int i = 0; i < N; i++) {
        cin >> runners[i].speed;
    }

    long long total_meetings = 0;

    // 모든 사람들의 쌍을 확인합니다.
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // 두 사람의 속력 차이를 계산합니다.
            long long speed_diff = abs(runners[i].speed - runners[j].speed);
            if (speed_diff != 0) {
                // 두 사람이 만날 때까지 걸리는 시간을 계산합니다.
                long long time_to_meet = C / speed_diff;
                // 만약 그 시간이 L보다 작거나 같다면, 두 사람은 만납니다.
                if (time_to_meet <= L) {
                    total_meetings++;
                }
            }
        }
    }

    // 총 만남 횟수를 출력합니다.
    cout << total_meetings << endl;

    return 0;
}