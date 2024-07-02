#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int arr[101][101];
int val[101];
int height, width;

void init_arr();
void print_arr();

bool validation(int L) {
    if (L >= height || L < 0)
        return false;

    for(int i = 0; i < width; i++) {
        memset(val, 0, sizeof(int) * 101);
        for(int j = 0; j < height; j++) {
            if (val[arr[i][j]] != 0)
                return true;
            val[arr[i][j]] = 1;
        }
    }
    return false;
}

//0 -> L, 1 -> R
void solve(int L, bool D) {
    if (L >= height || L < 0)
        return ;
    
    //left
    if (D == false) {
        int first = arr[L][0];
        for(int i = 0; i < width - 1; i++) {
            arr[L][i] = arr[L][i + 1];
        }
        arr[L][width - 1] = first;
    } else {
    //right
        int last = arr[L][width - 1];
        for(int i = width - 1; i > 0; i--) {
            arr[L][i] = arr[L][i - 1];
        }
        arr[L][0] = last;
    }

    if (validation(L - 1)) {
        solve(L - 1, !D);
    }
    if (validation(L + 1)) {
        solve(L + 1, !D);
    }
}

int main() {
    int command;
    int line;
    char direction;

    cin >> height >> width >> command;

    init_arr();
    while(command--) {
        cin >> line >> direction;
        //0 -> L, 1 -> R
        if (direction == 'L')
            solve(line - 1, false);
        else
            solve(line - 1, true);
    }

    print_arr();
    return 0;
}

void init_arr() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cin >> arr[i][j];
        }
    }
}

void print_arr() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}