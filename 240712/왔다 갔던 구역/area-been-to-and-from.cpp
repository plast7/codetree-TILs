#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> Interval;

int main()
{
    // intervals 벡터는 이동한 구간들을 저장합니다.
    vector<Interval> intervals;
    int n, currentPosition = 0, totalCovered = 0, maxCovered = 0;
    Interval currentInterval = {0, 0};
    
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++){
        char direction;
        int steps;
        cin >> steps >> direction;
        
        // 오른쪽으로 이동하는 경우
        if(direction == 'R'){
            currentPosition += steps;
            // 현재 위치에서 이동한 구간을 intervals에 추가합니다.
            intervals.push_back({currentPosition - steps, min(currentInterval.second, currentPosition)});
            // 만약 구간의 시작과 끝이 같다면, 구간을 제거합니다.
            if(intervals.back().first == intervals.back().second)
                intervals.pop_back();
            // 현재 구간의 끝을 갱신합니다.
            if(currentPosition > currentInterval.second)
                currentInterval.second = currentPosition;
        }
        // 왼쪽으로 이동하는 경우
        else{
            currentPosition -= steps;
            // 현재 위치에서 이동한 구간을 intervals에 추가합니다.
            intervals.push_back({max(currentInterval.first, currentPosition), currentPosition + steps});
            // 만약 구간의 시작과 끝이 같다면, 구간을 제거합니다.
            if(intervals.back().first == intervals.back().second)
                intervals.pop_back();
            // 현재 구간의 시작을 갱신합니다.
            if(currentPosition < currentInterval.first)
                currentInterval.first = currentPosition;
        }
    }
    
    // intervals 벡터를 정렬합니다.
    sort(intervals.begin(), intervals.end());
    // 각 구간을 순회하며 겹치는 부분을 계산합니다.
    for(const auto& interval : intervals){
        // 현재 구간이 이전에 계산된 구간의 끝보다 크다면, 겹치는 부분을 계산합니다.
        if(interval.second > maxCovered){
            totalCovered += interval.second - max(interval.first, maxCovered);
            maxCovered = interval.second;
        }
    }
    
    // 결과 출력:
    cout << totalCovered << endl;
    
    return 0;
}