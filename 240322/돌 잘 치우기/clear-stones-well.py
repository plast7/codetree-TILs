import sys
from collections import deque

si = sys.stdin.readline

# 백트래킹으로 m 개의 돌을 선택해서 치우고 k번 만큼 BFS 를 수행한 다음에
# 둘 중 최솟값을 산출하여 최솟값의 최댓값을 갱신

# 1. 백트래킹을 이용하여 m개의 돌을 선택
# -> k개 중에 M개 고르기
def choose(curr_num, cnt):
    global answer
    if cnt > m:
        return

    if curr_num == num:
        if cnt == m:
            # 2. 선택한 칸의 돌 제거 후, k번 만큼 bfs를 수행
            for elem in combination:
                grid[elem[0]][elem[1]] = 0

            for elem in start:
                bfs(elem[0] - 1, elem[1] - 1)
                # 3. 최댓값을 갱신
                answer = max(answer, count_block())
                initialize()
        return

    combination.append(stone[curr_num])
    choose(curr_num + 1, cnt + 1)
    combination.pop()

    choose(curr_num + 1, cnt)

def in_range(x, y):
    return 0 <= x < n and 0 <= y < n

def bfs(start_x, start_y):
    q = deque()

    q.append((start_x, start_y))
    visited[start_x][start_y] = True

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if in_range(nx, ny) and grid[nx][ny] == 0 and not visited[nx][ny]:
                visited[nx][ny] = True
                q.append((nx, ny))


def count_block():
    cnt = 0
    global n
    for i in range(n):
        for j in range(n):
            if visited[i][j]:
                cnt += 1
    return cnt


def initialize():
    for elem in combination:
        grid[elem[0]][elem[1]] = 1

    for i in range(n):
        for j in range(n):
            visited[i][j] = False

n, k, m = map(int, si().split())
grid = [
    list(map(int, si().split()))
    for _ in range(n)
]
visited  = [
    [False for _ in range(n)]
    for _ in range(n)
]
start = []
stone = []
combination = []
dx, dy = [-1, 0, 1, 0], [0, -1, 0, 1]
answer = -sys.maxsize

num = 0
for i in range(k):
    start_x, start_y = map(int, si().split())
    start.append((start_x, start_y))

for i in range(n):
    for j in range(n):
        if grid[i][j] == 1:
            stone.append((i, j))
            num += 1

choose(0, 0)

print(answer)