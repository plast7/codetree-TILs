#include <iostream>
#include <cstdio>

using namespace std;

int player[1001][2];
int dp[1001][16][16];
int N;

int dfs(int idx, int white, int black) {
	if (white == 15 && black == 15) return 0;
	if (idx == N + 1) return 0;
	if (dp[idx][white][black]) return dp[idx][white][black];
	int ans = 0;
	if (white < 15) {
		ans = dfs(idx+1, white + 1, black) + player[idx][0];
	}
	if (black < 15) {
		ans = max(ans, dfs(idx + 1, white, black+1) + player[idx][1]);
	}
	return dp[idx][white][black] = max(ans, dfs(idx + 1, white, black));
}

int main() {
	int w, b;
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> w >> b;
		player[i][0] = w;
		player[i][1] = b;
	}
	cout << dfs(0,0,0) << "\n";

	return 0;
}