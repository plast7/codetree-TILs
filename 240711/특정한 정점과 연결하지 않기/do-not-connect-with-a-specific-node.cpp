#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int a, b, k;
int parent[100005];
int s[100005];
bool visit[100005];
priority_queue<int>pq;

int Find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	int X = Find(x);
	int Y = Find(y);
	if (X != Y) {
		parent[X] = Y;
		s[Y] += s[X];
	}
}
int main(void) {
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		parent[i] = i;
		s[i] = 1;
	}
	for (int i = 1;i <= m;i++) {
		int x, y;
		cin >> x >> y;
		Union(x, y);
	}
	cin >> a >> b >> k;
	int A = Find(a);
	int B = Find(b);

	for (int i = 1;i <= n;i++) {
		int I = Find(i);
		if (I == A || I == B) {
			continue;
		}
		if (visit[I]) {
			continue;
		}
		visit[I] = true;
		pq.push(s[I]);
	}

	int ans = s[A];

	for (int i = 0;i < k;i++) {
		if(pq.empty()) break;
        ans += pq.top();
		pq.pop();
	}
	cout << ans;
	return 0;
}