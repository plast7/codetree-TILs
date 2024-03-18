#include <bits/stdc++.h>
using namespace std;

int n;
int a[55];

int ss;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    cout << fixed;
    cout.precision(1);

    for(int i = 1; i <= n; i++) {
        ss += a[i];
        if(a[i] >= 100) {
            cout << ss << endl;
            cout << (double)ss / i << endl;
            return 0;
        }
    }

    assert(false);
}