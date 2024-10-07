#include <iostream>
#include <set>
#include <vector>

using namespace std;

// 직사각형을 표현하는 구조체입니다.
struct Rectangle {
    int height; // 직사각형의 세로 길이
    int width;  // 직사각형의 가로 길이
};

int main() {
    int numRectangles, maxLayerWidth;
    cin >> numRectangles >> maxLayerWidth;

    // 직사각형 정보를 저장할 벡터입니다.
    vector<Rectangle> rectangles(numRectangles + 1);
    for (int i = 1; i <= numRectangles; i++) {
        cin >> rectangles[i].height >> rectangles[i].width;
    }

    // 각 직사각형까지의 최소 높이를 저장하는 벡터입니다.
    vector<long long> minHeight(numRectangles + 1, 0);
    // 각 세그먼트의 길이를 저장하는 벡터입니다.
    vector<int> segmentLengths(numRectangles + 1, 0);
    // 높이를 저장하는 멀티셋입니다.
    multiset<long long> heightSet;

    int currentWidthSum = 0; // 현재 층의 가로 길이 합
    int segmentSize = 0;     // 세그먼트의 크기
    for (int i = 1, j = 1; i <= numRectangles; i++) {
        // 현재 직사각형을 세그먼트에 추가합니다.
        segmentLengths[segmentSize++] = 1;

        // 현재 직사각형의 높이가 이전 세그먼트의 높이보다 크거나 같으면 세그먼트를 병합합니다.
        while (segmentSize > 1 && rectangles[i - segmentLengths[segmentSize - 1]].height <= rectangles[i].height) {
            // 이전 세그먼트의 높이를 멀티셋에서 제거합니다.
            heightSet.erase(heightSet.find(rectangles[i - segmentLengths[segmentSize - 1]].height + minHeight[i - segmentLengths[segmentSize - 1] - segmentLengths[segmentSize - 2]]));
            // 세그먼트를 병합합니다.
            segmentLengths[segmentSize - 2] += segmentLengths[segmentSize - 1];
            segmentSize--;
        }
        // 현재 직사각형의 높이를 멀티셋에 추가합니다.
        heightSet.insert(rectangles[i].height + minHeight[i - segmentLengths[segmentSize - 1]]);

        // 현재 층의 가로 길이 합을 업데이트합니다.
        currentWidthSum += rectangles[i].width;

        // 최대 층의 가로 길이를 초과하면 세그먼트를 조정합니다.
        while (currentWidthSum > maxLayerWidth) {
            currentWidthSum -= rectangles[j].width;
            // 세그먼트의 높이를 멀티셋에서 제거합니다.
            heightSet.erase(heightSet.find(rectangles[j + segmentLengths[0] - 1].height + minHeight[j - 1]));
            if (--segmentLengths[0] == 0) {
                // 세그먼트가 비어있으면 제거합니다.
                segmentLengths.erase(segmentLengths.begin());
                segmentSize--;
            } else {
                // 세그먼트의 높이를 멀티셋에 추가합니다.
                heightSet.insert(rectangles[j + segmentLengths[0]].height + minHeight[j]);
            }
            j++;
        }

        // 현재 직사각형까지의 최소 높이를 업데이트합니다.
        minHeight[i] = *heightSet.begin();
    }

    // 전체 층의 최소 높이를 출력합니다.
    cout << minHeight[numRectangles] << endl;
    return 0;
}