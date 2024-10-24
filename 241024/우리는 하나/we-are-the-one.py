# 주어진 도시 중 시작점이 될 k개의 도시를 선택
# 시작점을 모두 queue에 집어 넣음 -> 시작점이 여러개일 때의 bfs
from collections import deque

n, k, u, d = map(int, input().split())
res = 0

cities = [list(map(int, input().split())) for _ in range(n)]
visited = [[0] * n for _ in range(n)]

pos = [(i, j)
for i in range(n)
for j in range(n)]
s_pos = []

q = deque()

def in_range(x, y):
    return x>=0 and x<n and y>=0 and y<n


def can_go(x, y, before):
    if not in_range(x,y) or visited[x][y]:
        return False

    return abs(cities[x][y] - before) >= u and abs(cities[x][y] - before) <= d


def bfs():    
    while q:
        x, y = q.popleft()

        dxs = [0, 0, 1, -1]
        dys = [1, -1, 0, 0]
        for dx, dy in zip(dxs, dys):
            nx = x + dx
            ny = y + dy
            if can_go(nx, ny, cities[x][y]):
                q.append((nx, ny))
                visited[nx][ny] = 1

def calc():
    global visited

    visited = [[0] * n for _ in range(n)]

    for x, y in s_pos:
        q.append((x,y))
        visited[x][y] = 1

    bfs()

    # print(visited)
    cnt = 0
    for i in range(n):
        for j in range(n):
            if visited[i][j]:
                cnt += 1

    return cnt

def find_max(idx, cnt):
    global res

    if cnt > k:
        return
    
    if idx == n*n:
        if cnt == k:
            res = max(res, calc())
        return
            
    s_pos.append(pos[idx])
    find_max(idx+1, cnt+1)
    s_pos.pop()
    find_max(idx+1, cnt)


find_max(0, 0)
print(res)