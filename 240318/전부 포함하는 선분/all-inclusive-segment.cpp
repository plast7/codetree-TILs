#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 100

using namespace std;

int n;
int x1[MAX_N], x2[MAX_N];
int ans = INT_MAX;

int main() {
    // 입력
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x1[i] >> x2[i];
    
    for(int skip = 1; skip <= n; skip++) {
        int max_x2 = 0;
        int min_x1 = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(i == skip) continue;

            // 시작점 중 가장 앞에 있는 좌표와 끝점 중 가장 뒤에 있는 점의 좌표를 확인합니다.
            max_x2 = max(max_x2, x2[i]);
            min_x1 = min(min_x1, x1[i]);
        }

        // 조건을 만족하는 선분의 길이는 max_x2 - min_x1입니다.
        // 정답보다 이 선분의 길이가 작으면 업데이트합니다.
        ans = min(ans, max_x2 - min_x1);
    }

    cout << ans;
    return 0;
}