from collections import deque

n, m = map(int, input().split())
matrix = [list(map(int,input().split())) for _ in range(n)]
visited = [[0]*m for _ in range(n)]
h, w, startx, starty, endx, endy = map(int, input().split())
    # 동 서 남 북
dr = [0, 0, 1, -1]
dc = [1, -1, 0, 0]


def onecheck(l):
    for a in range(h):
        for b in range(w):
            if l[a][b]:
                return True
    return False


def bfs(x, y, ex, ey):
    q = deque()
    q.append([x, y])
    visited[x][y] = 1
    while q:
        sx, sy = q.popleft()
        for i in range(4):
            nx = sx + dr[i]
            ny = sy + dc[i]
            if 0 > nx or nx > n-h or 0 > ny or ny > m-w or visited[nx][ny]:
                continue
            li = [row[ny:ny + w] for row in matrix[nx:nx + h]]
            if onecheck(li):
                continue
            q.append([nx, ny])
            visited[nx][ny] = visited[sx][sy] + 1


bfs(startx-1, starty-1, endx - 1, endy - 1)
if visited[endx-1][endy-1]:
    print(visited[endx-1][endy-1] - 1)
else:
    print(-1)