#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define debug1 puts("--@111%--")
#define debug2 puts("--@222%--")
#define debug3 puts("--@333%--")
#define y1 ysgjowiaef
using namespace std;

#define INF 1987654321

int main() {
    int n;

    int cnt = 9;

    cin >> n;

    For(i, 1, n) {
        For(j, 1, n) {
            cout << cnt << " ";
            cnt -= 2;
            if(cnt == -1)
                cnt = 9;
        }
        cout << endl;
    }
}