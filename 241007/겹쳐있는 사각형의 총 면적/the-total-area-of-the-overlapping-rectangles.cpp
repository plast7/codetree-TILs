#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// 최대 사각형 개수 정의
const int MAX_RECTANGLES = 1111;

// 사각형의 개수와 각 사각형의 좌표를 저장할 배열
int numRectangles, x1[MAX_RECTANGLES], y1[MAX_RECTANGLES], x2[MAX_RECTANGLES], y2[MAX_RECTANGLES], allXCoordinates[2 * MAX_RECTANGLES];

int main() {
    // 사각형의 개수를 입력받습니다.
    scanf("%d", &numRectangles);
    // 각 사각형의 좌표를 입력받고, x좌표를 따로 저장합니다.
    for(int i = 0; i < numRectangles; i++) {
        scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
        allXCoordinates[2 * i] = x1[i];
        allXCoordinates[2 * i + 1] = x2[i];
    }
    // x좌표들을 정렬합니다.
    sort(allXCoordinates, allXCoordinates + 2 * numRectangles);

    // 총 면적을 저장할 변수
    long long totalArea = 0;
    // x좌표를 기준으로 면적을 계산합니다.
    for(int i = 0; i < 2 * numRectangles; ) {
        int currentX = allXCoordinates[i];
        // 중복된 x좌표는 건너뜁니다.
        if(i != 0 && currentX == allXCoordinates[i - 1]) {
            i++;
            continue;
        }
        // 현재 x좌표에 포함되는 y좌표들을 저장할 벡터
        vector<pair<int, int>> yCoordinates;
        // 각 사각형에 대해 현재 x좌표에 포함되는 y좌표를 찾습니다.
        for(int j = 0; j < numRectangles; j++) {
            if(x1[j] <= currentX && x2[j] > currentX) {
                yCoordinates.push_back(make_pair(y2[j], 1));  // 상단 y좌표
                yCoordinates.push_back(make_pair(y1[j], -1)); // 하단 y좌표
            }
        }
        // y좌표가 없다면 다음 x좌표로 넘어갑니다.
        if(yCoordinates.empty()) {
            i++;
            continue;
        }
        // y좌표들을 정렬합니다.
        sort(yCoordinates.begin(), yCoordinates.end());
        // 현재 x좌표에서의 면적을 계산합니다.
        long long currentArea = 0;
        int activeRectangles = 0, pos = 0;
        // y좌표를 순회하며 면적을 계산합니다.
        while(pos < yCoordinates.size()) {
            int bottomY = yCoordinates[pos].first;
            activeRectangles += yCoordinates[pos].second;
            // 활성화된 사각형이 있을 동안 y좌표를 계속 확인합니다.
            while(activeRectangles > 0) {
                activeRectangles += yCoordinates[++pos].second;
            }
            int topY = yCoordinates[pos].first;
            // 활성화된 y좌표 구간의 길이를 더합니다.
            currentArea += topY - bottomY;
            pos++;
        }
        // 다음 x좌표를 찾습니다.
        int nextXIndex = i + 1;
        while(allXCoordinates[nextXIndex] == allXCoordinates[i]) {
            nextXIndex++;
        }
        // 현재 x좌표 구간의 면적을 총 면적에 더합니다.
        totalArea += currentArea * (allXCoordinates[nextXIndex] - currentX);
        i = nextXIndex;
    }

    // 총 면적을 출력합니다.
    printf("%lld\n", totalArea);

    return 0;
}