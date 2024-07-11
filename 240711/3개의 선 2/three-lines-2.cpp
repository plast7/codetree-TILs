#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 20;
const int MAX_VAL = MAX_N / 2 + 1;

int x[MAX_N], y[MAX_N];
int x_n[MAX_VAL], y_n[MAX_VAL];

int main() {
    int n;
    cin >> n;

    fill(begin(x_n), end(x_n), 0);
    fill(begin(y_n), end(y_n), 0);

    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        x_n[x[i]]++;
        y_n[y[i]]++;
    }

    int cnt = 0;
    
    for(int i = 0; i < n; i++) {
        if(!(x_n[x[i]] >= 2 || y_n[y[i]] >= 2)) {
            cnt++;
        }
    }
    if(cnt > 3) {
        cout << 0;
    } else {
        cout << 1;
    }

    return 0;
}