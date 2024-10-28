#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[15];

int main() {
    cin >> n >> k;
    assert(1 <= n and n <= 10);
    assert(1 <= k and k <= 1e8);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        assert(1 <= a[i] and a[i] <= 1e8);
        if(i >= 2) {
            assert(a[i] % a[i - 1] == 0);
            assert(a[i] > a[i - 1]);
        }
    }
    int ans = 0;
    for(int i = n; i >= 1; i--) {
        ans += k / a[i];
        k %= a[i];
    }
    cout << ans;
    return 0;
}