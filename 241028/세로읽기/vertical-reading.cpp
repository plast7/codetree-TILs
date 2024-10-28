#include <bits/stdc++.h>
using namespace std;

string a[10];

int main() {
    for(int i = 0; i < 4; i++) cin >> a[i];
    for(int j = 0; j < 15; j++) {
        for(int i = 0; i < 4; i++) {
            if(j < a[i].length()) cout << a[i][j];
        }
    }    

    return 0;
}