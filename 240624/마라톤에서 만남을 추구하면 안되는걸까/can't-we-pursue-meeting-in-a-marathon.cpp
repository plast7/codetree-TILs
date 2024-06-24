#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 각 사람의 속력과 위치를 저장하는 구조체
struct Runner {
    long long speed; // 속력
    long long position; // 위치
};

int main() {
    // 입력 받기
    int n, l, c;
    cin >> n >> l >> c;

    // 모든 사람들의 속력을 저장할 벡터
    vector<Runner> runners(n);
    for (int i = 0; i < n; ++i) {
        cin >> runners[i].speed;
    }

    // 총 만남 횟수를 저장할 변수
    long long total_meetings = 0;

    // 두 사람의 모든 조합에 대해 만남 횟수를 계산합니다.
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // 두 사람의 속력 차이를 계산합니다.
            long long speed_diff = abs(runners[i].speed - runners[j].speed);
            if (speed_diff != 0) {
                // 속력 차이가 0이 아닌 경우에만 만남 횟수를 계산합니다.
                // (L * C) / speed_diff는 두 사람이 만나는 횟수를 의미합니다.
                total_meetings += (l * c) / speed_diff;
            }
        }
    }

    // 총 만남 횟수를 출력합니다.
    cout << total_meetings << endl;

    return 0;
}