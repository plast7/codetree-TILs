#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef pair<int, int> Interval;

int main() {
    int numCommands;
    cin >> numCommands;

    // 명령어를 저장할 벡터
    vector<Interval> intervals;
    int currentPosition = 0;

    // 명령어를 입력받아 intervals 벡터에 저장합니다.
    for (int i = 0; i < numCommands; ++i) {
        int steps;
        char direction;
        cin >> steps >> direction;

        if (direction == 'R') {
            int newPosition = currentPosition + steps;
            intervals.push_back({currentPosition, newPosition});
            currentPosition = newPosition;
        } else {
            int newPosition = currentPosition - steps;
            intervals.push_back({newPosition, currentPosition});
            currentPosition = newPosition;
        }
    }

    // intervals 벡터를 정렬합니다.
    sort(intervals.begin(), intervals.end());

    // 구간의 시작과 끝을 기록할 맵
    map<int, int> pointCount;

    // 각 구간의 시작과 끝을 맵에 기록합니다.
    for (const auto& interval : intervals) {
        pointCount[interval.first]++;
        pointCount[interval.second]--;
    }

    int overlappedLength = 0;
    int currentOverlap = 0;
    int lastPoint = pointCount.begin()->first;

    // 맵을 순회하며 2번 이상 지나간 구간의 길이를 계산합니다.
    for (const auto& point : pointCount) {
        if (currentOverlap >= 2) {
            overlappedLength += point.first - lastPoint;
        }
        currentOverlap += point.second;
        lastPoint = point.first;
    }

    cout << overlappedLength << endl;

    return 0;
}