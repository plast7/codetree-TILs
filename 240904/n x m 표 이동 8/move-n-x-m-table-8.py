from collections import deque

k = int(input())
n, m = map(int, input().split())
MAP = [list(map(int, input().split())) for _ in range(n)]
visit = [[0]*m for _ in range(n)]



def bfs(x, y):

    q = deque()
    q.append([x, y, 0])
    visit[x][y] = 1
    while q:
        sx, sy, trial= q.popleft()
        if trial < k:
            for dx, dy in [[-2, 1], [-1, 2], [1, 2], [2, 1], [2, -1], [1, -2], [-1, -2], [-2, -1]]:
                nx = sx + dx
                ny = sy + dy
                if nx < 0 or nx >= n or ny < 0 or ny >= m:
                    continue
                if MAP[nx][ny] or visit[nx][ny]:
                    continue
                visit[nx][ny] = visit[sx][sy] + 1
                q.append([nx, ny, trial + 1])
        for rx, ry in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
            nx = sx + rx
            ny = sy + ry
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if MAP[nx][ny] or visit[nx][ny]:
                continue
            visit[nx][ny] = visit[sx][sy] + 1
            q.append([nx, ny, trial])




bfs(0, 0)
print(visit[n-1][m-1]-1)