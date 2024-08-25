from collections import deque
import copy
# 보드사이즈, 출발지점 개수, 제거해야할 돌멩이 수

N,K,M = tuple(map(int,input().split()))
stone_pos = []
board = []
for i in range(N):
    board.append(list(map(int,input().split())))
    for j in range(N):
        if board[i][j] == 1:
            stone_pos.append([i,j])

start_pos = []
q = deque()
for _ in range(K):
    r,c = tuple(map(int,input().split()))
    start_pos.append((r-1,c-1))
    q.append((r-1,c-1))
visited = [[0] * N for _ in range(N)]
def gen_combi(arr,n):
    res = []
    if n == 0:
        return [[]]

    for i in range(0,len(arr)):
        elem = arr[i]
        for C in gen_combi(arr[i+1:], n-1):
            res.append([elem] + C)
    return res
# 구체적인 아웃풋의 형태에 대해서는 나중에...
stone_select = gen_combi(stone_pos,M)
def initialize_visit():
    for i in range(N):
        for j in range(N):
            if (i,j) not in start_pos:
                visited[i][j] = 0

def in_range(r,c):
    return 0<=r<N and 0<=c<N

def can_move(r,c):
    global new_board
    return in_range(r,c) and not visited[r][c] and new_board[r][c] == 0

def bfs():
    drs,dcs = [1,0,-1,0],[0,1,0,-1]
    while q:
        r,c = q.popleft()
        for dr,dc in zip(drs,dcs):
            nr,nc = r + dr, c + dc
            if can_move(nr,nc):
                visited[nr][nc] = 1
                q.append((nr,nc))
def calc_visit():
    return sum(visited[i][j] for i in range(N) for j in range(N))
def renew_board():
    global new_board
    for sr,sc in choose_stone:
        for r in range(N):
            for c in range(N):
                new_board[sr][sc] = 0

max_ans = -1
for i in range(len(stone_select)):
    choose_stone = stone_select[i]
    new_board = copy.deepcopy(board)
    # 보드 갱신
    renew_board()
    # visit 갱신
    initialize_visit()
    # bfs()
    bfs()
    # 값 계산
    mid = calc_visit()
    # 값 비교
    if max_ans < mid:
        max_ans = mid

print(max_ans)