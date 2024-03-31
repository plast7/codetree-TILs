#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m; cin >> n >> m;
    vector<pair<int, int> > v;
    for(int i = 0; i < n; i++){
        int x1, x2; cin >> x1 >> x2;
        v.push_back(make_pair(x2, x1));
    }
    sort(v.begin(), v.end());

    int minans = INT_MAX;
    int st = 0;
    int en = 1;
    while(st < n - 1){
        while(en < n && abs(v[en].first - v[st].first) < m){
            en++;
        }
        if(en == n){
            break;
        }
        int temp = (v[en].second - v[st].second);
        minans = min(minans, abs(temp));
        if(st + 1 == en){
            en++;
        }
        else{
            st++;
        }
    }
    if(minans == INT_MAX){
        cout << -1;
    }
    else{
        cout << minans;
    }

    return 0;
}