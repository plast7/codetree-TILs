#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iomanip>
using namespace std;

#define MAX_N 20
#define MAX_M 5
#define DIR_NUM 4

int dx[DIR_NUM] = {-1,0,1,0};
int dy[DIR_NUM] = {0,1,0,-1};

// 격자의 크기 n, 폭탄의 종류 수 m
int n, m;
// 폭탄이 터져서 얻는 점수
int score = 0;

struct Bundle {
	int cnt;
	int red_cnt;
	int x, y;
};

// 폭탄 묶음 리스트
vector<Bundle> bomb_bundle;

// 폭탄 관리 배열
int grid[MAX_N][MAX_N];
int next_grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool cmp(Bundle a, Bundle b) {
	if(a.cnt != b.cnt) return a.cnt > b.cnt;
	if(a.red_cnt != b.red_cnt) return a.red_cnt < b.red_cnt;
	if(a.x != b.x) return a.x > b.x;
	return a.y < b.y;
}

void ChooseBFS(int x, int y) {
	int red_cnt = 0;
	int mx = x, my = y;

	int color = grid[x][y];
	queue<pair<int, int>> q;
	q.push({x, y});
	visited[x][y] = true;

	int cnt = 1;
	while (!q.empty()) {
		int cx, cy;
		tie(cx, cy) = q.front();
		q.pop();

		for (int dir = 0; dir < DIR_NUM; dir++) {
			int nx = cx + dx[dir], ny = cy + dy[dir];
			if (InRange(nx, ny) && !visited[nx][ny] && (grid[nx][ny] == color || grid[nx][ny] == 0)) {
				if (grid[nx][ny] == 0) red_cnt++;
				else {
					if (mx < nx || (mx == nx && my > ny)) {
						mx = nx;
						my = ny;
					}
				}
				cnt++;
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}

	if (cnt >= 2) {
		Bundle bundle;
		bundle.cnt = cnt;
		bundle.red_cnt = red_cnt;
		bundle.x = mx;
		bundle.y = my;
		bomb_bundle.push_back(bundle);
	}
}

void RemoveBFS(int x, int y) {
	int color = grid[x][y];
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	int cnt = 1;
	while (!q.empty()) {
		int cx, cy;
		tie(cx, cy) = q.front();
		grid[cx][cy] = -2;
		q.pop();

		for (int dir = 0; dir < DIR_NUM; dir++) {
			int nx = cx + dx[dir], ny = cy + dy[dir];
			if (InRange(nx, ny) && !visited[nx][ny] && (grid[nx][ny] == color || grid[nx][ny] == 0)) {
				cnt++;
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}

	score += (cnt * cnt);
}

void InitVisited() {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			visited[x][y] = false;
		}
	}
}

bool Explode(){
	InitVisited();
	bomb_bundle.clear();
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (grid[x][y] >= 1 && !visited[x][y]) ChooseBFS(x, y);
		}
	}

	if ((int)bomb_bundle.size() == 0) return false;

	sort(bomb_bundle.begin(), bomb_bundle.end(), cmp);
	InitVisited();
	RemoveBFS(bomb_bundle[0].x, bomb_bundle[0].y);
	return true;
}

void Drop() {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			next_grid[x][y] = -2;
		}
	}

	for (int y = 0; y < n; y++) {
		int idx = n - 1;
		for (int x = n - 1; x >= 0; x--) {
			if (grid[x][y] == -1) {
				idx = x - 1;
				next_grid[x][y] = -1;
			}
			else if (grid[x][y] == -2) continue;
			else{
				next_grid[idx][y] = grid[x][y];
				idx--;
			}
		}
	}
	
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			grid[x][y] = next_grid[x][y];
		}
	}
}

void Rotate() {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			next_grid[x][y] = -2;
		}
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			next_grid[x][y] = grid[y][n - x - 1];
		}
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			grid[x][y] = next_grid[x][y];
		}
	}
}

int width = 3;

void Print() {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cout << right << setw(width) << grid[x][y] << " ";
		}
		cout << "\n";
	}
	cout << "Score : " << score << '\n';
	cout << "-------------------------\n";
}

bool Simulate() {
	if(!Explode()) return false;
	// Print();

	Drop();
	// Print();

	Rotate();
	// Print();

	Drop();
	// Print();
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> grid[x][y];
		}
	}

	while (true) {
		if(!Simulate()) break;
	}

	cout << score << '\n';
	return 0;
}