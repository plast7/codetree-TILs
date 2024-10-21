#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool is_used[2505];

int main() {
    string str;
    cin >> str;
    int ans = 0;
    
    while(true) {
        ans++;
        bool is_changed = false;
        char cur = 'a';
        for(int i = 0; i < str.length(); i++) {
            if(is_used[i]) continue;
            if(str[i] == cur) {
                is_used[i] = true;
                is_changed = true;
                cur++;
                if(cur > 'e') cur = 'a';
            }
        }
        if(cur != 'a') {
            cout << -1;
            return 0;
        }
        if(!is_changed) {
            break;
        }
        bool is_all_used = true;
        for(int i = 0; i < str.length(); i++) {
            if(!is_used[i]) is_all_used = false;
        }
        if(is_all_used) break;
    }

    bool is_all_used = true;
    for(int i = 0; i < str.length(); i++) {
        if(!is_used[i]) is_all_used = false;
    }

    if(is_all_used) {
        cout << ans;
    }
    else {
        cout << -1;
    }
}