// 코드트리 빵
#include <iostream>
#include <queue>
#include <vector>

#define MAX 15
using namespace std;

struct People {
    int arr_y;
    int arr_x;
    int y = -1;
    int x = -1;
    bool start = false;
    bool arrival = false;

    void ToString() {
        printf("cur_position: (%d, %d), arrival_position: (%d, %d) \n", y, x, arr_y, arr_x);
    }
};

int N, M;
int map[MAX][MAX];
vector<People> people;
pair<int, int> movdir[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
string tt[] = {"Z", "A", "B", "C", "D", "E", "F", "G"};

void AllPrint() {
    string temp[MAX][MAX];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = to_string(map[i][j]);
        }
    }

    for (int i = 1; i <= M; i++) {
        if (people[i].start == false)
            continue;
        temp[people[i].y][people[i].x] = tt[i];
    }

    cout << "\n----------------------------";
    for (int i = 0; i < N; i++) {
        cout << "\n";
        for (int j = 0; j < N; j++) {
            cout << temp[i][j] << " ";
        }
    }
    cout << "\n";
    return;
}

void Input() {
    people.push_back(People());
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= M; i++) {
        int y, x;
        cin >> y >> x;
        people.push_back({y - 1, x - 1});
    }
}

void SearchBaseCamp(int idx) {
    queue<pair<int, int>> q;
    int visit[MAX][MAX] = {0};

    q.push({people[idx].arr_y, people[idx].arr_x});
    visit[people[idx].arr_y][people[idx].arr_x] = 1;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ny = y + movdir[d].first;
            int nx = x + movdir[d].second;

            if (ny < 0 || N <= ny || nx < 0 || N <= nx || visit[ny][nx] == 1)
                continue;
            if (map[ny][nx] == 2)
                continue;

            if (map[ny][nx] == 1) {
                people[idx].y = ny;
                people[idx].x = nx;
                map[ny][nx] = 2;
                return;
            }

            visit[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
}

int SearchShotDist(int idx, int sy, int sx) {
    queue<pair<int, int>> q;
    int visit[MAX][MAX] = {0};

    q.push({sy, sx});
    visit[people[idx].y][people[idx].x] = 1;
    visit[sy][sx] = 1;
    int cnt = 0;

    while (!q.empty()) {
        int size = q.size();
        cnt += 1;

        for (int cur = 0; cur < size; cur++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if (y == people[idx].arr_y && x == people[idx].arr_x) {
                return cnt;
            }

            for (int d = 0; d < 4; d++) {
                int ny = y + movdir[d].first;
                int nx = x + movdir[d].second;

                if (ny < 0 || N <= ny || nx < 0 || N <= nx)
                    continue;
                if (visit[ny][nx] == 1 || map[ny][nx] == 2)
                    continue;

                visit[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }

    return 987654321;
}

bool checkArrival() {
    for (int i = 1; i <= M; i++) {
        if (people[i].arrival == false && people[i].y == people[i].arr_y && people[i].x == people[i].arr_x) {
            people[i].arrival = true;
            map[people[i].arr_y][people[i].arr_x] = 2;
        }

        if (people[i].start == false || people[i].arrival == false)
            return false;
    }
    return true;
}

void Solution() {
    int ans = 1;
    while (true) {
        // 이동
        for (int i = 1; i <= M; i++) {
            if (people[i].start == false || people[i].arrival == true)
                continue;

            // 편의점 쪽으로 이동 로직
            //   현재 위치에서 상, 우, 좌, 하 순서로 최단 거리 계산
            //   제일 가까운 거리로 이동 : people.y, .x 갱신
            int nd = -1;
            int dist = 987654321;
            for (int d = 0; d < 4; d++) {
                int ny = people[i].y + movdir[d].first;
                int nx = people[i].x + movdir[d].second;
                if (ny < 0 || N <= ny || nx < 0 || N <= nx || map[ny][nx] == 2)
                    continue;

                int retDist = SearchShotDist(i, ny, nx);
                if (dist > retDist) {
                    dist = retDist;
                    nd = d;
                }
            }

            people[i].y += movdir[nd].first;
            people[i].x += movdir[nd].second;
        }

        // 도착 확인
        if (checkArrival()) {
            break;
        }

        // 격자 추가
        if (ans < people.size()) {
            people[ans].start = true;

            // 베이스캠프 이동
            SearchBaseCamp(ans);
        }

        ans += 1;
    }
    cout << ans;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    Input();
    Solution();
    return 0;
}