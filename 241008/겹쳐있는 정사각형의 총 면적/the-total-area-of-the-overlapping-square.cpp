#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int numSquares, sideLength;
    cin >> numSquares >> sideLength;

    // 각 정사각형의 중심 좌표를 저장할 벡터입니다.
    vector<pair<int, int>> squareCenters;
    for(int i = 0; i < numSquares; i++) {
        int x, y;
        cin >> x >> y;
        // 중심 좌표를 벡터에 추가합니다.
        squareCenters.push_back(make_pair(x, y));
    }
    // x 좌표를 기준으로 정렬합니다.
    sort(squareCenters.begin(), squareCenters.end());

    // 현재 활성화된 정사각형들을 저장할 집합입니다.
    set<pair<int, int>> activeSquares;
    // 겹치는 정사각형 쌍을 저장할 벡터입니다.
    vector<pair<int, int>> overlappingPairs;
    
    // i는 현재 검사 중인 정사각형의 인덱스, j는 활성화된 정사각형의 시작 인덱스입니다.
    for(int i = 0, j = 0; i < squareCenters.size() && overlappingPairs.size() < 2; i++) {
        // 현재 정사각형의 x 좌표가 j번째 정사각형의 x 좌표 + K보다 크거나 같으면 j번째 정사각형을 활성화 집합에서 제거합니다.
        while(squareCenters[j].first + sideLength <= squareCenters[i].first) {
            activeSquares.erase(make_pair(squareCenters[j].second, j));
            j++;
        }

        // 현재 정사각형을 활성화 집합에 추가합니다.
        auto current = activeSquares.insert(make_pair(squareCenters[i].second, i)).first;
        auto previous = current;
        // 이전 정사각형과의 y 좌표 차이를 검사하여 겹치는지 확인합니다.
        if(previous-- != activeSquares.begin() && squareCenters[i].second < previous->first + sideLength) {
            overlappingPairs.push_back(make_pair(i, previous->second));
        }
        auto next = current;
        // 다음 정사각형과의 y 좌표 차이를 검사하여 겹치는지 확인합니다.
        if(++next != activeSquares.end() && next->first < squareCenters[i].second + sideLength) {
            overlappingPairs.push_back(make_pair(i, next->second));
        }
    }

    long long totalOverlapArea = 0;
    // 겹치는 쌍이 2개 이상이면 -1을 출력합니다.
    if(overlappingPairs.size() > 1) {
        totalOverlapArea = -1;
    } 
    // 겹치는 쌍이 1개이면 겹치는 면적을 계산합니다.
    else if(overlappingPairs.size() == 1) {
        int dx = abs(squareCenters[overlappingPairs[0].first].first - squareCenters[overlappingPairs[0].second].first);
        int dy = abs(squareCenters[overlappingPairs[0].first].second - squareCenters[overlappingPairs[0].second].second);
        totalOverlapArea = 1LL * (sideLength - dx) * (sideLength - dy);
    }
    // 결과를 출력합니다.
    cout << totalOverlapArea << endl;
}