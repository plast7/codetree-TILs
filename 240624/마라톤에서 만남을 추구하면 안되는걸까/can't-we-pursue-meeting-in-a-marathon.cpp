#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 달리는 사람의 정보를 저장하는 구조체입니다.
struct Runner {
    long long speed;    // 속력
    long long position; // 위치
};

int main() {
    int n, l, c;
    cin >> n >> l >> c;

    // 달리는 사람들의 정보를 저장하기 위한 벡터입니다.
    vector<Runner> runners(n);
    
    // 각 사람의 속력을 입력받고, 이를 바탕으로 위치를 계산합니다.
    for (int i = 0; i < n; ++i) {
        cin >> runners[i].speed;
        // 각 사람의 위치는 속력 * 라운드 수를 트랙 길이로 나눈 나머지입니다.
        runners[i].position = runners[i].speed * l % c;
    }

    // 사람들을 속력 기준으로 오름차순 정렬합니다.
    sort(runners.begin(), runners.end(), [](const Runner& a, const Runner& b) {
        return a.speed < b.speed;
    });

    long long meet_count = 0; // 만남의 횟수를 저장할 변수입니다.
    map<long long, int> position_count; // 각 위치에 있는 사람의 수를 저장할 맵입니다.

    // 정렬된 사람들을 순서대로 처리합니다.
    for (const auto& runner : runners) {
        // 현재 사람보다 앞서 있는 사람들과의 만남을 계산합니다.
        for (const auto& [position, count] : position_count) {
            // 현재 사람의 위치보다 큰 위치에 있는 사람들과는 만날 수 없습니다.
            if (position > runner.position) {
                break;
            }
            // 현재 사람보다 앞서 있는 사람들과의 만남 횟수를 더해줍니다.
            meet_count += count;
        }
        // 현재 사람의 위치에 있는 사람의 수를 증가시킵니다.
        position_count[runner.position]++;
    }

    // 총 만남의 횟수를 출력합니다.
    cout << meet_count << endl;

    return 0;
}