#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

using namespace std;

// Point 구조체를 정의하여 x, y 좌표를 저장합니다.
struct Point {
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
};

// 전역 변수 선언
int numPoints, xCoords[100], yCoords[100], pointIndex[100];
set<pair<int, int>> pointSet; // 점의 (x, y) 좌표를 저장하는 집합
vector<Point> nodes; // 모든 노드들을 저장하는 벡터
vector<int> adjacencyList[500]; // 인접 리스트

// 두 노드 간의 맨해튼 거리를 계산하는 함수
int calculateDistance(int a, int b) {
    return abs(nodes[a].x - nodes[b].x) + abs(nodes[a].y - nodes[b].y);
}

// 첫 번째 점이 두 번째와 세 번째 점을 잇는 선분 위에 있는지 확인하는 함수
bool isInSegment(int x1, int y1, int x2, int y2, int x3, int y3) {
    if (x2 == x3)
        return x1 == x2 && y1 > min(y2, y3) && y1 < max(y2, y3);
    else if (y2 == y3)
        return y1 == y2 && x1 > min(x2, x3) && x1 < max(x2, x3);
    else
        return false;
}

// 두 노드 간의 경로가 가능한지 확인하는 함수 (원래 점들과 교차하지 않는지)
bool isPathPossible(int a, int b) {
    // 방법 1: 세로로 먼저 이동한 후 가로로 이동
    bool verticalFirst = nodes[a].x == nodes[b].x || nodes[a].y == nodes[b].y || pointSet.find(make_pair(nodes[a].x, nodes[b].y)) == pointSet.end();
    for (int i = 0; i < numPoints; i++) {
        if (isInSegment(xCoords[i], yCoords[i], nodes[a].x, nodes[a].y, nodes[a].x, nodes[b].y) || 
            isInSegment(xCoords[i], yCoords[i], nodes[a].x, nodes[b].y, nodes[b].x, nodes[b].y)) {
            verticalFirst = false;
            break;
        }
    }
    if (verticalFirst)
        return true;

    // 방법 2: 가로로 먼저 이동한 후 세로로 이동
    bool horizontalFirst = nodes[a].x == nodes[b].x || nodes[a].y == nodes[b].y || pointSet.find(make_pair(nodes[b].x, nodes[a].y)) == pointSet.end();
    for (int i = 0; i < numPoints; i++) {
        if (isInSegment(xCoords[i], yCoords[i], nodes[a].x, nodes[a].y, nodes[b].x, nodes[a].y) || 
            isInSegment(xCoords[i], yCoords[i], nodes[b].x, nodes[a].y, nodes[b].x, nodes[b].y)) {
            horizontalFirst = false;
            break;
        }
    }
    if (horizontalFirst)
        return true;

    return false;
}

// 두 노드 간의 최단 경로의 길이를 찾는 함수
bool visited[500];
int distances[500], infinity = 1023456789;
int findShortestPath(int a, int b) {
    // 초기화
    for (int i = 0; i < nodes.size(); i++) {
        distances[i] = infinity;
        visited[i] = false;
    }
    // 시작 및 종료 위치를 제외한 점들은 방문하지 않도록 설정
    for (int i = 0; i < numPoints; i++) {
        if (pointIndex[i] != a && pointIndex[i] != b)
            visited[pointIndex[i]] = true;
    }

    distances[a] = 0;
    for (int i = 0; i < nodes.size(); i++) {
        int next = 0;
        for (int j = 0; j < nodes.size(); j++) {
            if (!visited[j] && (distances[j] < distances[next] || visited[next]))
                next = j;
        }
        if (visited[next] || distances[next] == infinity)
            return -1;
        if (next == b)
            return distances[next];
        visited[next] = true;
        for (int j = 0; j < adjacencyList[next].size(); j++) {
            if (!visited[adjacencyList[next][j]])
                distances[adjacencyList[next][j]] = min(distances[adjacencyList[next][j]], distances[next] + calculateDistance(next, adjacencyList[next][j]));
        }
    }
    return -1;
}

int main() {
    // 입력 받기
    scanf("%d", &numPoints);
    for (int i = 0; i < numPoints; i++) {
        scanf("%d %d", &xCoords[i], &yCoords[i]);
        pointSet.insert(make_pair(xCoords[i], yCoords[i]));
    }

    // 노드 생성
    for (int i = 0; i < numPoints; i++) {
        for (int a = -1; a <= 1; a++) {
            for (int b = -1; b <= 1; b++) {
                if (a == 0 && b == 0) {
                    nodes.push_back(Point(xCoords[i], yCoords[i]));
                    pointIndex[i] = nodes.size() - 1;
                } else if (a * b == 0 && pointSet.find(make_pair(xCoords[i] + a, yCoords[i] + b)) == pointSet.end()) {
                    nodes.push_back(Point(xCoords[i] + a, yCoords[i] + b));
                }
            }
        }
    }

    // 간선 생성
    for (int i = 0; i < nodes.size(); i++) {
        for (int j = i + 1; j < nodes.size(); j++) {
            if (isPathPossible(i, j)) {
                adjacencyList[i].push_back(j);
                adjacencyList[j].push_back(i);
            }
        }
    }

    // 다익스트라 알고리즘을 사용하여 최단 경로 찾기
    int totalDistance = 0;
    for (int i = 0; i < numPoints; i++) {
        int nextDistance = findShortestPath(pointIndex[i], pointIndex[(i + 1) % numPoints]);
        if (nextDistance < 0) {
            totalDistance = -1;
            break;
        } else {
            totalDistance += nextDistance;
        }
    }

    // 결과 출력
    printf("%d\n", totalDistance);

    return 0;
}