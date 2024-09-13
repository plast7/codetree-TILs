#include <iostream>
using namespace std;

#define MAX_N 100

int p1[MAX_N] = {}; 
int p2[MAX_N] = {};

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p1[i] >> p2[i];
    }

    int max_win = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (i == j) continue;
            int win = 0;
            for (int k = 0; k < n; k++) {
                if (p1[k] == i && p2[k] == j) win++;
                if (p1[k] == j && p2[k] != i) win++;
                if (p1[k] != i && p1[k] != j && p2[k] == i) win++;
            }
            if (win > max_win) {
                max_win = win;
            }
        }
    }
    cout << max_win;
    return 0;
}