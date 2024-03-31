#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int n, m, k;
int nBoard[22][22];

int point[32];
int x[32];
int y[32];
int d[32];
int s[32];

int gun[32];

priority_queue<int> pq[22][22]; // 맥스 힙

int dr[4] = {-1, 0, 1, 0};
int du[4] = {0, 1, 0, -1};

void printBoard()
{
	cout << "=====================\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << nBoard[i][j] << ' ';
		cout << '\n';
	}
	cout << "=====================\n";
	for (int i = 1; i <= m; i++)
	{
		cout << i << ' ' << d[i] << ' ' << gun[i] << " : " << point[i] << '\n';
	}
}

bool isInRange(int x, int y)
{
	return (x <= n && x > 0 && y <= n && y > 0);
}

int getDir(int d)
{
	int nd = (d + 2) % 4;
	return nd;
}

int battle(int att, int def)
{
	int att_dam = s[att] + gun[att];
	int def_dam = s[def] + gun[def];

	//cout << "BATTLE " << att << ' ' << att_dam << " vs " << def << ' ' << def_dam << '\n';
	if (att_dam > def_dam)
	{
		return att;
	}
	else if (att_dam == def_dam)
	{
		if (s[att] > s[def]) return att;
		else return def;
	}
	else
	{
		return def;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int g;
			cin >> g;
			if (g != 0)
			{
				pq[i][j].push(g);
			}
		}
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> x[i] >> y[i] >> d[i] >> s[i];
		nBoard[x[i]][y[i]] = i;
	}

	//printBoard();
	for (int round = 1; round <= k; round++)
	{
		//cout << "ROUND " << round << '\n';
		// 1-1
		for (int i = 1; i <= m; i++)
		{
			//cout << "PLAYER " << i << " START FROM " << x[i] << ' ' << y[i] << ' ' << d[i] << '\n';
			int nx = x[i] + dr[d[i]];
			int ny = y[i] + du[d[i]];
			int nd = d[i];

			// 1-1 격자를 벗어나는 경우
			if (false == isInRange(nx, ny))
			{
				nd = getDir(d[i]); // 방향 바꾸기 (0->2) (1->3), (2->0) (3->1)
				//cout << d[i] << ' ' << nd << '\n';
				d[i] = nd; // 방향 바꾼거 저장
				nx = x[i] + dr[nd];
				ny = y[i] + du[nd];
			}

			nBoard[x[i]][y[i]] = 0;
			//cout << "MOVE TO " << nx << ' ' << ny << '\n';

			// 2-2 플레이어가 있는 경우
			if (nBoard[nx][ny] > 0)
			{
				//cout << "CASE 2-2 \n";
				// 2-2-1. 배틀
				int winner = battle(i, nBoard[nx][ny]); // 이긴 플레이어 계산

				// 2-2-2. 
				int defeated = i;
				if (defeated == winner)
				{
					defeated = nBoard[nx][ny];
				}

				// 초기 공격력 + 총의 합의 차이 만큼 포인트 획득
				point[winner] += ((s[winner] + gun[winner]) - (s[defeated] + gun[defeated])); // 포인트 획득
				//cout << "WINNER " << winner << ' ' << " LOSER " << defeated << '\n';

				/* 이긴 사람 옮기기 */
				nBoard[nx][ny] = winner;
				x[winner] = nx;
				y[winner] = ny;

				/* 진 사람 총 내려놓기 */
				if (gun[defeated] != 0)
				{
					pq[nx][ny].push(gun[defeated]);
					gun[defeated] = 0;
				}

				// 이긴사람은 해당 위치에 총이 있으면
				if (pq[nx][ny].size() > 0)
				{
					//cout << "GET \n";
					// 놓여있는 총 중 가장 쎈 총
					int lev_gun = pq[nx][ny].top();

					if (gun[winner] < lev_gun)
					{
						// 총 바꾸기
						pq[nx][ny].pop();
						if (gun[winner] != 0)
						{
							pq[nx][ny].push(gun[winner]);
						}
						gun[winner] = lev_gun;
					}

				//	cout << gun[winner] << ' ' << lev_gun << '\n';
				}

				/* 패배한 플레이어 움직이기 */
				int dir = d[defeated];
				for (int di = 0; di < 4; di++)
				{
					// 현재 방향부터 우측으로 90도씩 보면서 빈칸 찾기
					dir += di;
					if (dir > 3) dir %= 4;

					int nnx = nx + dr[dir];
					int nny = ny + du[dir];
				
					// 격자밖이면 다른 곳
					if (false == isInRange(nnx, nny)) continue;
					// 플레이어 있으면 다른 곳
					else if (nBoard[nnx][nny] > 0) continue;

					// 총이 있으면
					if (pq[nnx][nny].size() > 0)
					{
						// 총 뺏겼으니 놓아둘 총은 없다
						gun[defeated] = pq[nnx][nny].top(); // 다시 총 들기
						pq[nnx][nny].pop();
					}

					/* 진사람 옮기기 */
					nBoard[nnx][nny] = defeated;
					x[defeated] = nnx;
					y[defeated] = nny;
					d[defeated] = dir; // 방향 저장
					break;
				}
			}
			// 2-1 총이 있는지 확인
			else if (pq[nx][ny].size() > 0)
			{
				//cout << "CASE 2-1 \n";
				// 놓여있는 총 중 가장 쎈 총
				int lev_gun = pq[nx][ny].top();

				if (gun[i] < lev_gun)
				{
					// 총 바꾸기
					pq[nx][ny].pop();
					if (gun[i] != 0) // 총을 가지고 있었을 경우
					{
						// 총 내려놓기
						pq[nx][ny].push(gun[i]);
					}
					// 더 쎈 총 들기
					gun[i] = lev_gun;
				}

				//cout << gun[i] << ' ' << lev_gun << '\n';
				x[i] = nx; // 해당 위치로 이동
				y[i] = ny;
				nBoard[nx][ny] = i; // 옮겼다는 것 명시
			}
			else
			{	// 2-3 빈 칸이면
				//cout << "CASE 2-3 \n";

				x[i] = nx; // 해당 위치로 이동
				y[i] = ny;
				nBoard[nx][ny] = i; // 옮겼다는 것 명시
			}
		}
		//printBoard();
	}

	for (int i = 1; i <= m; i++)
	{
		cout << point[i] << ' ';
	}
	return 0;
}