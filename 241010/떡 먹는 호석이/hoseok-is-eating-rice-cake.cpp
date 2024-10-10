#include <iostream>
using namespace std;

int main() {
    // 변수 선언: day는 d번째 날, rice_cakes는 그 날 먹은 떡의 개수
    int day, rice_cakes;
    cin >> day >> rice_cakes;

    // 첫째 날에 먹은 떡의 개수를 1부터 시작하여 가능한 모든 경우를 탐색합니다.
    for (int first_day_cakes = 1; first_day_cakes <= 49999; first_day_cakes++) {
        // 둘째 날에 먹은 떡의 개수를 찾기 위한 변수
        int second_day_cakes = -1;

        // 이분 탐색을 위한 변수 설정
        int left = first_day_cakes;
        int right = 100000 - first_day_cakes;
        int mid;

        // 이분 탐색을 통해 둘째 날에 먹은 떡의 개수를 찾습니다.
        while (left <= right) {
            mid = (left + right) / 2;

            // 첫째 날과 둘째 날에 먹은 떡의 개수를 설정합니다.
            int previous = first_day_cakes;
            int current = mid;

            // 셋째 날부터 d번째 날까지의 떡의 개수를 계산합니다.
            for (int j = 3; j <= day; j++) {
                int temp = current;
                current = previous + current;
                previous = temp;

                // 만약 떡의 개수가 100,000을 넘으면 중단합니다.
                if (current > 100000) {
                    break;
                }
            }

            // 계산된 떡의 개수가 주어진 떡의 개수와 같다면 둘째 날의 떡의 개수를 저장합니다.
            if (current == rice_cakes) {
                second_day_cakes = mid;
                break;
            } 
            // 계산된 떡의 개수가 주어진 떡의 개수보다 크다면 오른쪽 범위를 줄입니다.
            else if (current > rice_cakes) {
                right = mid - 1;
            } 
            // 계산된 떡의 개수가 주어진 떡의 개수보다 작다면 왼쪽 범위를 늘립니다.
            else {
                left = mid + 1;
            }
        }

        // 둘째 날의 떡의 개수가 유효하다면 결과를 출력하고 종료합니다.
        if (second_day_cakes >= 0) {
            cout << first_day_cakes << " " << second_day_cakes << endl;
            break;
        }
    }

    return 0;
}