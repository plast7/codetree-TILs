#include <iostream>
#include <queue>

using namespace std;

// Point 구조체는 좌표를 나타냅니다.
struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
    Point() : x(0), y(0) {}
};

// BFS를 위한 큐를 두 개 사용합니다.
// zero_distance_queue는 빨간 점을 지나지 않은 경로를 저장합니다.
// one_distance_queue는 빨간 점을 지난 경로를 저장합니다.
queue<Point> zero_distance_queue, one_distance_queue;

// 빨간 점의 위치를 저장하는 배열입니다.
int red_points[1002][1002];

// 각 좌표까지의 최소 빨간 점 경유 횟수를 저장하는 배열입니다.
int distance[1002][1002];

// 현재 위치에서 새로운 위치로 이동할 때의 거리를 업데이트하는 함수입니다.
void updateDistance(int current_x, int current_y, int new_x, int new_y) {
    // 새로운 좌표가 유효한 범위 내에 있는지 확인합니다.
    if (new_x >= 0 && new_x <= 1001 && new_y >= 0 && new_y <= 1001 && 
        (distance[new_x][new_y] == 0 || distance[current_x][current_y] + red_points[new_x][new_y] < distance[new_x][new_y])) {
        
        // 새로운 위치의 거리를 업데이트합니다.
        distance[new_x][new_y] = distance[current_x][current_y] + red_points[new_x][new_y];
        
        // 빨간 점이 없는 경우 zero_distance_queue에 추가합니다.
        if (red_points[new_x][new_y] == 0) {
            zero_distance_queue.push(Point(new_x, new_y));
        } else {
            // 빨간 점이 있는 경우 one_distance_queue에 추가합니다.
            one_distance_queue.push(Point(new_x, new_y));
        }
    }
}

int main() {
    Point start_point;
    int num_red_points;

    // 입력을 받습니다.
    cin >> num_red_points >> start_point.x >> start_point.y;
    // 시작점의 거리를 1로 설정합니다.
    distance[start_point.x][start_point.y] = 1;
    // 시작점을 zero_distance_queue에 추가합니다.
    zero_distance_queue.push(start_point);

    // 빨간 점의 위치를 입력받아 저장합니다.
    for (int i = 0; i < num_red_points; i++) {
        Point red_point;
        cin >> red_point.x >> red_point.y;
        red_points[red_point.x][red_point.y] = 1;
    }

    // BFS를 수행합니다.
    while (!zero_distance_queue.empty() || !one_distance_queue.empty()) {
        // zero_distance_queue가 비어있다면, one_distance_queue의 내용을 이동시킵니다.
        if (zero_distance_queue.empty()) {
            while (!one_distance_queue.empty()) {
                zero_distance_queue.push(one_distance_queue.front());
                one_distance_queue.pop();
            }
        }

        // 현재 위치를 가져옵니다.
        Point current_point = zero_distance_queue.front();
        zero_distance_queue.pop();

        // 상하좌우로 이동하면서 거리를 업데이트합니다.
        updateDistance(current_point.x, current_point.y, current_point.x - 1, current_point.y);
        updateDistance(current_point.x, current_point.y, current_point.x + 1, current_point.y);
        updateDistance(current_point.x, current_point.y, current_point.x, current_point.y - 1);
        updateDistance(current_point.x, current_point.y, current_point.x, current_point.y + 1);
    }

    // 원점까지의 최소 빨간 점 경유 횟수를 출력합니다.
    cout << distance[0][0] - 1 << endl;

    return 0;
}