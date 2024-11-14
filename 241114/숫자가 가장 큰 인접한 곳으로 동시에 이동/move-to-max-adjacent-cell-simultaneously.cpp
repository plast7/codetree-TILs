#include <iostream>
#include <vector>
using namespace std;

int n, m, t;
vector<vector<int>> arr, temp;
vector<int> x, y, nx, ny;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void Input()
{
    cin >> n >> m >> t;

    arr.resize(n, vector<int>(n));
    temp.resize(n, vector<int>(n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    
    x.resize(m);
    y.resize(m);
    for (int i=0; i<m; i++) {
        cin >> x[i] >> y[i];
        temp[x[i]][y[i]]++; 
    }
}

bool In_Range(int x, int y)
{
    return x>=0 && x<n && y>=0 && y<n;
}

void Check(int m)
{
    int nx, ny;
    for(int i=0; i<4; i++) {
        nx = x[m] + dx[i];
        ny = y[m] + dy[i];

        if (In_Range(nx, ny) && arr[nx][ny] > arr[x[m]][y[m]]) {
            temp[x[m]][y[m]]--;
            x[m] = nx;
            y[m] = ny;
            temp[nx][ny]++;
            break;
        }
    }
}

void Result()
{
    while (t>0) {
        for (int i=0; i<m; i++) {
            Check(i);
        }

        for (int i=0; i<m; i++) {
            if (temp[x[i]][y[i]] == 1) {
                nx.push_back(x[i]);
                ny.push_back(y[i]);
            }
            else {
                temp[x[i]][y[i]] = 0;
            }
        }

        x = nx;
        y = ny;
        m = x.size();
        t--;
    }

    cout << m;
}

int main() {
    // 여기에 코드를 작성해주세요.
    Input();
    Result();
    return 0;
}
