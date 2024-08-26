#include <cstdio>
#include <queue>
using namespace std;
int n,m,w,h,si,sj,ei,ej;
int a[1001][1001];
bool visit[1001][1001];
const int dx[]={0,0,-1,1}, dy[]={-1,1,0,0};
struct pos{
    int x,y,t;
};
bool wallCheck(int i,int x, int y){
    if (i==0){ // 왼쪽이동
        for(int j= x;j<x+h;j++) if(a[j][y]) return false;
    }else if (i==1){ //오른쪽이동
        for(int j=x;j<x+h;j++) if (a[j][y+w-1]) return false;
    }else if (i==2){ //위쪽이동
        for(int j=y;j<y+w;j++) if(a[x][j]==1) return false;
    }else { //아래 이동
        for(int j=y;j<y+w;j++) if (a[x+h-1][j]==1) return false;
    }
    return true;
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d", &a[i][j]);
        }
    }
    scanf("%d %d %d %d %d %d", &h, &w, &si, &sj, &ei, &ej);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(a[si + i][sj + j]) {
                printf("-1");
                return 0;
            }
        }
    }
    queue<pos> q;
    q.push({si,sj,0});
    visit[si][sj]=true;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int t = q.front().t;
        if(x == ei && y == ej){
            printf("%d\n",t);
            return 0;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i], ny=y+dy[i];
            if(nx<1 || nx+h -1 > n || ny <1 || ny+w-1 > m || visit[nx][ny]) continue;
            if(wallCheck(i,nx,ny)){
                q.push({nx,ny,t+1});
                visit[nx][ny]=true;
            }
        }

    }
    printf("-1\n");
    return 0;
}