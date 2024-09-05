#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
int n,command,m_id,p_id,color,max_depth,score;
vector<int> mp[100002];
int p_ids[100002],colors[100002],max_depths[100002],colorbit[100002];
vector<int> heads;
void addnode(int m_id, int p_id, int color, int max_depth) {
    if (p_id == -1) {
        heads.push_back(m_id);
        p_ids[m_id] = -1;
    }
    else {
        p_ids[m_id] = p_id;
        mp[p_id].push_back(m_id);
        int d = 2;
        for (int p=p_id; p!=-1; p=p_ids[p],d++) {
            if (max_depths[p] < d) {
                p_ids[m_id] = 0;
                mp[p_id].pop_back();
                return;
            }
        }
    }
    colors[m_id] = color;
    max_depths[m_id] = max_depth;
}
void changecolor(int m_id, int color) {
    colors[m_id] = color;
    for (int i : mp[m_id]) {
        changecolor(i, color);
    }
}
void setvalue(int m_id) {
    colorbit[m_id] |= (1 << (colors[m_id]-1));
    for (int i : mp[m_id]) {
        setvalue(i);
        colorbit[m_id] |= colorbit[i];
    }
    int temp = 0;
    for (int i = 0; i < 5; i++) {
        if (colorbit[m_id] & (1 << i)) {
            temp++;
        }
    }
    score += temp*temp;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n--) {
        cin >> command;
        if (command == 100) {
            cin >> m_id >> p_id >> color >> max_depth;
            addnode(m_id, p_id, color, max_depth);
        }
        else if (command == 200) {
            cin >> m_id >> color;
            changecolor(m_id, color);
        }
        else if (command == 300) {
            cin >> m_id;
            cout << colors[m_id] << '\n';
        }
        else {
            score = 0;
            memset(colorbit, 0, sizeof(colorbit));
            for (int i : heads) setvalue(i);
            cout << score << '\n';
        }
    }
    return 0;
}