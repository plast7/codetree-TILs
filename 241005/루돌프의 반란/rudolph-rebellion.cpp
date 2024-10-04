#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int n, m, num_of_santa, r_pow, s_pow;
pair<int, int> rudolf;
struct santa_info {
	int r, c, sleep;
	bool out;
};
santa_info santa[35];
int santa_score[35];
int map[55][55];

bool oob(int i, int j) { return(i < 0 || i >= n || j < 0 || j >= n); }

bool check() {
	int cnt = 0;
	for (int i = 1; i <= num_of_santa; i++) {
		if (santa[i].out)
			cnt++;
	}
	if (cnt == num_of_santa)
		return false;
	return true;
}

void crash(int santa_num, int dr, int dc, int pow) {
	int ii = santa[santa_num].r + pow * dr, jj = santa[santa_num].c + pow * dc; //산타의 이동한 위치
	map[santa[santa_num].r][santa[santa_num].c] = 0; //일단 원래자리 비우기
	santa[santa_num].sleep = 2; //기절
	santa_score[santa_num] += pow; //점수 추가
	if (oob(ii, jj))  //oob면
		santa[santa_num].out = true; //탈락
	else if (map[ii][jj] == 0) { //빈자리면
		santa[santa_num].r = ii, santa[santa_num].c = jj; //산타 정보 변경
		map[ii][jj] = santa_num; //맵 채워넣기
	}
	else { //연쇄적 밀림작용
		int target_santa = map[ii][jj], org = santa_num; //밀릴 산타, 밀 산타
		while (1) {
			santa[org].r = ii, santa[org].c = jj; //산타 정보 변경
			map[ii][jj] = org; //채워넣기
			int next_i = ii + dr, next_j = jj + dc; //밀릴 산타가 갈 위치
			if (oob(next_i, next_j)) {
				santa[target_santa].out = true; //밀릴 산타 탈락
				break;
			}
			else if (map[next_i][next_j] == 0) {
				santa[target_santa].r = next_i, santa[target_santa].c = next_j;
				map[next_i][next_j] = target_santa;
				break;
			}
			else {
				org = target_santa;
				target_santa = map[next_i][next_j];
				ii = next_i, jj = next_j; //다음 반복문을 위해 위치와 타겟 산타 변경
			}
		}
	}
}

void move_rudolf() { //루돌프 이동
	pair<int, pair<int, int> > prior_santa = { -0x7f, { -1, -1 } }; //거리, 행, 열 
	for (int i = 1; i <= num_of_santa; i++) { //모든 산타 돌면서
		if (santa[i].out)
			continue;
		int dis = pow((rudolf.first - santa[i].r), 2) + pow((rudolf.second - santa[i].c), 2); //해당 산타까지의 거리 계산
		prior_santa = max({ -dis, {santa[i].r, santa[i].c} }, prior_santa);
	}
	int dr = 0, dc = 0; //루돌프의 이동 방향 기록용 변수
	if (prior_santa.second.first < rudolf.first)
		dr--;
	else if (prior_santa.second.first > rudolf.first)
		dr++;
	if (prior_santa.second.second < rudolf.second)
		dc--;
	else if (prior_santa.second.second > rudolf.second)
		dc++;
	rudolf.first += dr, rudolf.second += dc;
	if (rudolf == prior_santa.second)  //충돌했다면
		crash(map[rudolf.first][rudolf.second], dr, dc, r_pow); //루돌프의 방향 그대로 후처리
}

void move_santa() {
	for (int i = 1; i <= num_of_santa; i++) { //모든 산타 돌면서
		if (santa[i].out || santa[i].sleep != 0)
			continue;
		int dr_s[4] = { -1, 0, 1, 0 }, dc_s[4] = { 0, 1, 0, -1 };
		pair<int, int> prior_dir = { 0x7f, 0 };
		int cur_dis = pow((rudolf.first - santa[i].r), 2) + pow((rudolf.second - santa[i].c), 2); //루돌프까지의 거리 계산
		for (int dir = 0; dir < 4; dir++) {
			int ii = santa[i].r + dr_s[dir], jj = santa[i].c + dc_s[dir];
			int dis = pow((rudolf.first - ii), 2) + pow((rudolf.second - jj), 2); //이동하였을 경우의 거리 계산
			if (!oob(ii, jj) && dis < cur_dis && map[ii][jj] == 0) //이동한 경우가 obb / 가까워질 수 없을 경우 / 다른 산타가 있는 경우는 불가
				prior_dir = min(prior_dir, { dis, dir });
		}
		if (prior_dir.first == 0x7f) //이동할 수 있는 칸이 없다면 움직이지 않음
			continue;
		map[santa[i].r][santa[i].c] = 0; //원래 맵 비우고
		santa[i].r += dr_s[prior_dir.second], santa[i].c += dc_s[prior_dir.second]; //산타 정보 바꾸고
		map[santa[i].r][santa[i].c] = i; //이동한 곳에 산타 채우기
		if (santa[i].r == rudolf.first && santa[i].c == rudolf.second) //충돌시
			crash(i, -dr_s[prior_dir.second], -dc_s[prior_dir.second], s_pow); //산타의 이동방향 반대로 후처리
	}
}

void solve() {
	for (int i = 0; i < m; i++) { //모든 턴 돌면서
		move_rudolf(); //루돌프 이동
		move_santa(); //산타 전체 이동
		if (!check()) //모든 산타가 탈락했다면
			break;
		for (int j = 1; j <= num_of_santa; j++) {
			if (santa[j].sleep == 0)
				continue;
			santa[j].sleep--;
		}
		for (int j = 1; j <= num_of_santa; j++) {
			if (santa[j].out)
				continue;
			santa_score[j]++;
		}
	}
	for (int i = 1; i <= num_of_santa; i++)
		cout << santa_score[i] << " ";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> num_of_santa >> r_pow >> s_pow;
	cin >> rudolf.first >> rudolf.second;
	rudolf.first--;
	rudolf.second--;
	for (int i = 1; i <= num_of_santa; i++) {
		int cur_santa;
		cin >> cur_santa;
		cin >> santa[cur_santa].r >> santa[cur_santa].c;	
		santa[cur_santa].r--;
		santa[cur_santa].c--;
		map[santa[cur_santa].r][santa[cur_santa].c] = cur_santa;
	}
	solve();
	return 0;
}