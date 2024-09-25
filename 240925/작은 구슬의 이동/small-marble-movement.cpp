#include <bits/stdc++.h>
using namespace std;
int const dy[] = {0, -1, 0, 1}, dx[] = {1, 0, -1, 0};
int n, t, r, c, a[54][54];
char d;
int Dir(char c){
    if(c == 'R') return 0;
    if(c == 'D') return 1;
    if(c == 'L') return 2;
    if(c == 'U') return 3;
}
bool isin(int ny, int nx, int n){
    if(ny <= 0 || nx <= 0 || ny > n || nx >  n) return 0;
    return 1;
}
int main(){
    cin >> n >> t >> r >> c >> d;
    int dir = Dir(d);
    while(t--){
        int nr = r + dy[dir];
        int nc = c + dx[dir];
        if(isin(nr, nc, n)){
            r = nr, c = nc;
        }else{
            dir = (dir + 2) % 4;
        }
    }
    cout << r << " " << c;
}