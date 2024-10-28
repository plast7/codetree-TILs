#include <bits/stdc++.h>
using namespace std;

string a[10];

int main() {
    for(int i = 0; i < 4; i++) cin >> a[i];
    for(int i = 0; i < 4; i++) {
        assert(1 <= a[i].length() and a[i].length() <= 15);
        for(int j = 0; j < a[i].length(); j++) {
            assert('0' <= a[i][j] and a[i][j] <= '9' or 'a' <= a[i][j] and a[i][j] <= 'z' or 'A' <= a[i][j] and a[i][j] <= 'Z');
        }
    }
    for(int j = 0; j < 15; j++) {
        for(int i = 0; i < 4; i++) {
            if(j < a[i].length()) cout << a[i][j];
        }
    }

    return 0;
}