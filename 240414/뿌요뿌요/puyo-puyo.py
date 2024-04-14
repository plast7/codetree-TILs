n = int(input())

grid = [list(map(int, input().split())) for _ in range(n)]


visited = [[False for _ in range(n)] for _ in range(n)]


def in_range(x, y):
    return 0<=x<n and 0<=y<n

def can_go(x, y, value):
    
    if visited[x][y] or grid[x][y] != value:
        return False
    return True


def dfs(x, y):
    global cnt
    dxs, dys = [-1, 0, 1, 0], [0, -1, 0, 1]
    for dx, dy in zip(dxs, dys):
        nextx, nexty = x + dx, y + dy
        if in_range(nextx, nexty):
            if can_go(nextx, nexty, grid[x][y]):
                visited[nextx][nexty] = True
                dfs(nextx, nexty)
                cnt += 1

cnt_list = []
for i in range(n):
    for j in range(n):
        if visited[i][j] == False:
            visited[i][j] = True
            cnt = 1
            dfs(i, j)
            if cnt >= 4:
                cnt_list.append(cnt)


print(len(cnt_list), max(cnt_list))