#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int total_days, closed_days;
int dp[101][101];
bool is_closed_day[101]; // 리조트를 이용할 수 없는 날을 표시하는 배열

// 현재 날(day), 남은 쿠폰 수(coupons)를 입력받아 최소 비용을 계산하는 함수
int calculate_min_cost(int day, int coupons) {
    // 기저 조건: 모든 날이 지나면 비용은 0
    if (day > total_days) return 0;

    int &current_cost = dp[day][coupons];

    // 이미 계산된 값이 있으면 반환
    if (current_cost != -1) return current_cost;

    // 리조트를 이용할 수 없는 날이면 다음 날로 넘어감
    if (is_closed_day[day]) {
        current_cost = calculate_min_cost(day + 1, coupons);
    } else {
        current_cost = INT_MAX;
        // 하루 이용권 사용
        current_cost = min(current_cost, calculate_min_cost(day + 1, coupons) + 10000);
        // 연속 3일권 사용
        current_cost = min(current_cost, calculate_min_cost(day + 3, coupons + 1) + 25000);
        // 연속 5일권 사용
        current_cost = min(current_cost, calculate_min_cost(day + 5, coupons + 2) + 37000);

        // 쿠폰 3장 이상이면 쿠폰을 하루 이용권으로 교환
        if (coupons >= 3) {
            current_cost = min(current_cost, calculate_min_cost(day + 1, coupons - 3));
        }
    }
    return current_cost;
}

int main() {
    cin >> total_days >> closed_days;
    while (closed_days--) {
        int day;
        cin >> day;
        is_closed_day[day] = true;
    }
    memset(dp, -1, sizeof(dp));

    cout << calculate_min_cost(1, 0) << '\n';
}