#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <cstring>

using namespace std;

int q;
int n, m;

int start = 0;

typedef pair<int, int> edge;

int mlist[2004][2004];
int mdistance[2004];
bool visited[2004];

// greater 해야 최소값 힙, 오름차순 정렬
priority_queue <edge, vector<edge>, greater<edge>> d_q;

void dijkstra(int hajime)
{
    memset(mdistance, 0x3f, sizeof(mdistance));
    memset(visited, false, sizeof(visited));

    d_q.push(make_pair(0, hajime));
    mdistance[hajime] = 0;

    while (!d_q.empty())
    {
        edge current = d_q.top();
        d_q.pop();
        int c_v = current.second;

        if (visited[c_v])
            continue;
        visited[c_v] = true;

        for(int i = 0; i < n; i++) {
            if (mlist[c_v][i] != 200 and (i != c_v)) {
                if (mdistance[i] > mdistance[c_v] + mlist[c_v][i]) {
                    mdistance[i] = mdistance[c_v] + mlist[c_v][i];
                    d_q.push(make_pair(mdistance[i], i));
                }
            }
        }
    }

}

struct info {
    int id;
    int revenue;
    int dest;
    int cost;
};

bool dead[30002];
bool made[30002];

bool operator < (const info& a, const info& b)
{
    if ((a.revenue - a.cost) == (b.revenue - b.cost))
        return a.id > b.id;
    return (a.revenue - a.cost) < (b.revenue - b.cost);
}

priority_queue<info> pq;

int sellPackage() {
    while (!pq.empty()) {
        info tmp = pq.top();
        // 최적이라고 생각한 여행 상품이 판매 불가능 하다면 while문을 빠져나가 -1을 반환합니다.
        if ((tmp.revenue - tmp.cost) < 0)
            break;
        pq.pop();
        if (!dead[tmp.id])
            return tmp.id; // 해당 여행 상품이 취소되지 않았다면 정상 판매되므로 id를 반환합니다
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> q;
    while (q--) {
        int query;
        cin >> query;
        if (query == 100) {
            cin >> n >> m;
            int u, v, w;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                {
                    mlist[i][j] = 200;
                }
                mlist[i][i] = 0;
            }
                

            for (int i = 0; i < m; i++) {
                cin >> u >> v >> w;
                // 양방향
                mlist[u][v] = min(mlist[u][v], w);
                mlist[v][u] = min(mlist[v][u], w);
            }
            // 다익스트라
            dijkstra(start); 
        }
        else if (query == 200) {
            int id, rev, fin;
            cin >> id >> rev >> fin;
            made[id] = true;
            pq.push({ id, rev, fin, mdistance[fin] });
        }
        else if (query == 300) {
            int c_id;
            cin >> c_id;
            if(made[c_id])
                dead[c_id] = true;
        }
        else if (query == 400) {
            cout << sellPackage() << endl;
        }
        else if (query == 500) {
            int s;
            cin >> s;
            start = s;
            dijkstra(start);

            vector<info> remake;
            while (!pq.empty())
            {
                info tmp = pq.top();
                tmp.cost = mdistance[tmp.dest];
                pq.pop();
                remake.push_back(tmp);
            }

            for (info p : remake)
                pq.push(p);
        }
    }
    return 0;
}