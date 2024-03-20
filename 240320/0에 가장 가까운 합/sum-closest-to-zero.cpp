#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n;
int a[MAX_N + 1];

int main() {
    // 입력:
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    // 0에 가장 가까운 합을 구합니다.
    int ans = INT_MAX;

    // 구간을 잡아봅니다.
    int j = n;
    for(int i = 1; i <= n; i++) {
        if(i < j)
            ans = min(ans, abs(a[i] + a[j]));

        // 두 수의 합이 0 이하가 될 때 까지 j 구간을 내리면서 정답을 살펴봅니다.
        while(i < j - 1 && a[i] + a[j] > 0) {
            j--;
            ans = min(ans, abs(a[i] + a[j]));
        }
    }
    
    // 정답을 출력합니다.
    cout << ans;
    return 0;
}