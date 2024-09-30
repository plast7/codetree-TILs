#include <iostream>

using namespace std;

#define MAX_N 300

int map[MAX_N][MAX_N];
int n, m, r;

// 배열을 r번 회전시키는 함수입니다.
void rotate(){
    // 각 레이어마다 회전을 진행합니다.
    int check = min(n, m) / 2; // 돌려야 할 사각형 개수 계산입니다.
    
    for(int cnt = 0; cnt < check; cnt++) {
        int n_max = n - cnt - 1;
        int m_max = m - cnt - 1;

        // 레이어의 왼쪽 상단 값을 임시 저장합니다.
        int tmp = map[cnt][cnt];

        // 위쪽 변을 왼쪽으로 이동시킵니다.
        for(int i = cnt; i < m_max; i++) {
            map[cnt][i] = map[cnt][i + 1];
        }

        // 오른쪽 변을 위쪽으로 이동시킵니다.
        for(int i = cnt; i < n_max; i++) {
            map[i][m_max] = map[i + 1][m_max];
        }

        // 아래쪽 변을 오른쪽으로 이동시킵니다.
        for(int i = m_max; i > cnt; i--) {
            map[n_max][i] = map[n_max][i - 1];
        }

        // 왼쪽 변을 아래쪽으로 이동시킵니다.
        for(int i = n_max; i > cnt; i--) {
            map[i][cnt] = map[i - 1][cnt];
        }

        // 임시 저장한 값을 오른쪽 상단에 넣습니다.
        map[cnt + 1][cnt] = tmp;
    }
}

int main() {    
    // 행렬의 크기와 회전 횟수를 입력받습니다.
    cin >> n >> m >> r;
    
    // 행렬의 원소를 입력받습니다.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    
    // 지정된 횟수만큼 행렬을 회전시킵니다.
    for(int i = 0; i < r; i++) rotate();
    
    // 최종 결과 행렬을 출력합니다.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}