#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

vector<int> v1;
vector<int> v2;
vector<priority_queue<long long, vector<long long>, greater<long long>>> res;

int n, m, k;

int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        v1.push_back(num);
    }

    for (int i = 0; i < m; ++i)
    {
        int num;
        cin >> num;
        v2.push_back(num);
    }

    for (int i = 0; i < n; ++i)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int j = 0; j < m; ++j)
        {
            pq.push(v1[i] + v2[j]);
        }
        res.push_back(pq);
    }

    while (1)
    {
        int smallValue = INT_MAX;
        int smallIdx = 0;

        for (int i = 0; i < res.size(); ++i)
        {
            auto pqi = res[i];
            int temp = pqi.top();

            if (smallValue > temp)
            {
                smallValue = temp;
                smallIdx = i;
            }
        }

        if (k == 1)
        {
            cout << res[smallIdx].top();
            break;
        }

        res[smallIdx].pop();
        k--;
    }

    return 0;
}
