#include <iostream>


#define MAXN 1001
#define MAXK 4001
#define MAXDIR 4

using namespace std;

int n;
int k;

char arr[MAXN][MAXN];
int arr_k[MAXK];

// current x, y
int x, y;
int dir;

int dx[MAXDIR] = {0,1,0,-1};
int dy[MAXDIR] = {1,0,-1,0};

int count;

bool InRange(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

bool InRange_k(int x, int y){

    return x >= 0 && x <= n + 1 && y >= 0 && y <= n + 1;
}

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            char slash;
            cin >> slash;
            if (slash == '/'){
                arr[i][j] = 's';
            }else{
                arr[i][j] = 'b';
            }
        }
    }

    cin >> k;

    arr_k[1] = 1;
    arr[0][1] = 1;

    int x_k = 0;
    int y_k = 1;
    int dir_k = 0;

    for(int i = 2; i <= k; i++){
        int nx_k = x_k + dx[dir_k];
        int ny_k = y_k + dy[dir_k];

        if (!InRange_k(nx_k, ny_k)){
            dir_k = (dir_k + 1) % MAXDIR; 
 
      }
       

         x_k = x_k + dx[dir_k];
         y_k = y_k + dy[dir_k];
    }  


    dir = (dir_k + 1) % MAXDIR;

    x = x_k + dx[dir];
    y = y_k + dy[dir];


    // k 값에 따라서 행동이 틀려져.
    // /
    // 상하좌우
    // 시계, 시계, 반시계, 반시계
    // \
    // 상하좌우
    // 반시계, 반시계, 시계, 시계

    // k

    while(InRange(x, y)){
       
        count++;
        // back slash
        if(arr[x][y] == 'b'){
            if(dir == 1 || dir == 3){
                dir = (dir + 3) % MAXDIR;
            }else{
                dir = (dir + 1) % MAXDIR;
            }     
        }else{
            //slash
            if(dir == 2 || dir == 0){
                dir = (dir + 3) % MAXDIR;
            }else{
                dir = (dir + 1) % MAXDIR;
            }   
        }

        x = x + dx[dir];
        y = y + dy[dir];

        // cout << x << " " << y << endl;
    }


    cout << count << endl;
 
    return 0;
}