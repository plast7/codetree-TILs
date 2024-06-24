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
vector<long long> positions;

int main() {
    // 입력:
    cin >> N >> L >> C;
    runners.resize(N);
    positions.resize(N);

    // 각 사람의 속력을 입력받습니다.
    for (int i = 0; i < N; ++i) {
        cin >> runners[i].speed;
    }

    // 각 사람의 최종 위치를 계산합니다.
    for (int i = 0; i < N; ++i) {
        runners[i].position = (runners[i].speed * L) % C;
    }

    // 최종 위치를 기준으로 정렬합니다.
    sort(runners.begin(), runners.end(), [](const Runner &a, const Runner &b) {
        return a.position < b.position;
    });

    long long meet_count = 0;

    // 만나는 횟수를 계산합니다.
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            // 만약 두 사람의 최종 위치가 같다면 만나는 횟수를 증가시킵니다.
            if (runners[i].position == runners[j].position) {
                meet_count++;
            }
        }
    }

    // 결과를 출력합니다.
    cout << meet_count << endl;

    return 0;
}