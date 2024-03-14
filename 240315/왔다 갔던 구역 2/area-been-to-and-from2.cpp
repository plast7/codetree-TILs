#include<iostream>
using namespace std;

int main() { int n, x; char side; cin >> n; int arr[2001] = {}; cin >> x >> side; int temp = 1000;

for (int j = 0; j < n; ++j) {
    for (int i = 0; i <= x; ++i) {
        if (side == 'R') {
            arr[temp + i]++;
            
            if (i == x) {
                temp = temp + x;
            }
        } else {
            // Adjust the index to avoid negative values
            if (temp - i >= 0) {
                arr[temp - i]++;
            }
            
            if (i == x) {
                temp = temp - x;
            }
        }
    }
    cin >> x >> side;
}

int length = 0;
int temp1 = 0;

for (int i = 0; i < 2001; ++i) {
    i += temp1;
    if (arr[i] >= 2) {
        for (int j = i + 1; j < 2001; ++j) {
            if (arr[j] >= 2) {
                length++;
                temp1 = j - i;
            } else {
                break;
            }
        }
    } else {
        temp1 = 0;
    }
}

cout << length;
return 0;
}