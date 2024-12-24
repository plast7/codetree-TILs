#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#define MAXN 1001
using namespace std;

vector<int> graph[MAXN];
unordered_map<int, int> idx;
int dp[MAXN];
int N;

int dfs(int node) {
    int& ans = dp[node];

    if (ans != -1) return ans;
    ans = 0;
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (dp[next] == -1) {
            ans = max(ans, dfs(next) + 1);
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        if (idx.find(n1) == idx.end()) {
            dp[n1] = -1;
            idx[n1]++;
        }
        if (idx.find(n2) == idx.end()) {
            idx[n2]++;
            dp[n2] = -1;
        }
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    int ans = 0;

    for (auto it : idx) {
        if (dp[it.first] == -1) ans += dfs(it.first);
    }
    
    //for (auto it : idx) {
    //    cout << "dp[" << it.first << "] : " << dp[it.first] << "\n";
    //}
    
    cout << ans;
    return 0;
}
