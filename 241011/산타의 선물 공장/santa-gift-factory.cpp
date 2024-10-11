#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init_factory(int n, int m, int ID[], int W[]);
extern int unload_boxes(int w_max);
extern int remove_box(int r_id);
extern int check_box(int f_id);
extern int break_belt(int b_num);

#define CMD_INIT_FACTORY    100
#define CMD_UNLOAD_BOXES    200
#define CMD_REMOVE_BOX      300
#define CMD_CHECK_BOX       400
#define CMD_BREAK_BELT      500

static bool run() {
    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; ++i) {
        int cmd;
        scanf("%d", &cmd);

        switch (cmd) {
        case CMD_INIT_FACTORY: {
            int n, m;
            scanf("%d %d", &n, &m);
            int* ID = new int[n];
            int* W = new int[n];
            for (int i = 0; i < n; ++i) {
                scanf("%d", &ID[i]);
            }
            for (int i = 0; i < n; ++i) {
                scanf("%d", &W[i]);
            }
            init_factory(n, m, ID, W);
            delete[] ID;
            delete[] W;
            break;
        }
        case CMD_UNLOAD_BOXES: {
            int w_max;
            scanf("%d", &w_max);
            int result = unload_boxes(w_max);
            printf("%d\n", result);
            break;
        }
        case CMD_REMOVE_BOX: {
            int r_id;
            scanf("%d", &r_id);
            int result = remove_box(r_id);
            printf("%d\n", result);
            break;
        }
        case CMD_CHECK_BOX: {
            int f_id;
            scanf("%d", &f_id);
            int result = check_box(f_id);
            printf("%d\n", result);
            break;
        }
        case CMD_BREAK_BELT: {
            int b_num;
            scanf("%d", &b_num);
            int result = break_belt(b_num);
            printf("%d\n", result);
            break;
        }
        default:
            return false;
        }
    }

    return true;
}

int main() {
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);

    run();
    return 0;
}

#define MAX_N 100005
#define MAX_M 11
#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>
using namespace std;

unordered_map<int, int> box_id_idx_mapping; // 물건 ID-idx mapping
int w[MAX_N];           // 물건
bool in_belt[MAX_N];
int box_belt[MAX_N];    // box_belt[box_idx] = 박스가 있는 벨트 넘버
list<int>::iterator iter[MAX_N];
int root_belt[MAX_M];
list<int> belt[MAX_M];
int belt_num;   // 벨트 갯수(벨트 마지막 번호)

void init_factory(int n, int m, int ID[], int W[]) {
    belt_num = m;

    for(int i=0; i<n; i++) {
        box_id_idx_mapping[ID[i]] = i;
        w[i] = W[i];
        in_belt[i] = true;
        box_belt[i] = i/(n/m) + 1;
        belt[box_belt[i]].push_back(i);
        iter[i] = (--belt[box_belt[i]].end());
    }
    
    // root belt initialize
    for(int i=1; i<=m; i++) {
        root_belt[i] = i;
    }
}

int unload_boxes(int w_max) {
    int total_box_w = 0;
    for(int i=1; i<= belt_num; i++) {
        if(root_belt[i] != i) continue; // 만약 망가진 벨트라면 건너뛰기
        if(belt[i].empty()) continue;   // 빈 벨트라면 건너뛰기
        int box_idx = *belt[i].begin();
        if(w[box_idx] <= w_max) {  // w_max 이하라면
            total_box_w += w[box_idx];
            in_belt[box_idx] = false;
            belt[i].pop_front();
        }
        else {  // w_max 이상이라면
            belt[i].splice(belt[i].end(), belt[i], belt[i].begin());
        }
    }
    return total_box_w;
}

int remove_box(int r_id) {
    if(!box_id_idx_mapping.count(r_id)) return -1; // 없는 아이디라면
    int box_idx = box_id_idx_mapping[r_id];
    if(!in_belt[box_idx]) return -1;    // 만약 상자가 없다면

    int box_belt_num = root_belt[box_belt[box_idx]];
    belt[box_belt_num].erase(iter[box_idx]);   // 있다면 해당 박스 지움
    in_belt[box_idx] = false;
    return r_id;
}

int check_box(int f_id) {
    if(!box_id_idx_mapping.count(f_id)) return -1; // 없는 아이디라면
    int box_idx = box_id_idx_mapping[f_id];
    if(!in_belt[box_idx]) return -1;    // 만약 상자가 없다면

    int box_belt_num = root_belt[box_belt[box_idx]];   // 만약 상자가 있다면
    belt[box_belt_num].splice(belt[box_belt_num].begin(), belt[box_belt_num], iter[box_idx], belt[box_belt_num].end());
    return box_belt_num;
}

int break_belt(int b_num) {    
    if(root_belt[b_num] != b_num) return -1;    // 이미 망가져 있다면

    int target_belt = 0;    // 옮길 벨트 번호
    for(int i=b_num+1; i<=belt_num; i++) {    // 오른쪽으로 이동하면서 옮길 벨트 찾기
        if(root_belt[i] == i) {
            target_belt = i; break;
        }
    }
    if(!target_belt) {  // 못찾았다면 1부터 다시 찾음
        for(int i=1; i<b_num; i++) {
            if(root_belt[i] == i) {
                target_belt = i; break;
            }
        }
    }

    root_belt[b_num] = target_belt;
    belt[target_belt].splice(belt[target_belt].end(), belt[b_num]);
    return b_num;
}