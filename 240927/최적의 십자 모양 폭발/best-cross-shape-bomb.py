n = int(input())
grid = [
    list(map(int,input().split()))
    for _ in range(n)
]

next_grid = [
    [0 for _ in range(n)]
    for _ in range(n)
]

dxs, dys = [-1,1,0,0],[0,0,-1,1]

def explode(x,y):
    scale = temp_grid[x][y] - 1
    temp_grid[x][y] = 0
    nx,ny = x,y
    for dx,dy in zip(dxs,dys):
        for i in range(scale):
            nx,ny = nx + dx, ny + dy
            if nx < 0 or nx > n - 1 or ny < 0 or ny > n - 1:
                continue

            temp_grid[nx][ny] = 0
        
        nx,ny = x,y

def down():
    for i in range(n):
        index = n - 1
        for j in range(n-1, -1, -1):
            if temp_grid[i][j]:
                next_grid[index][i] = temp_grid[j][i]
                index -= 1
        
    for i in range(n):
        for j in range(n):
            temp_grid[i][j] = next_grid[i][j]
    
    for i in range(n):
        for j in range(n):
            next_grid[i][j] = 0

def countAdjacency():
    cnt = 0
    for i in range(n):
        for j in range(n-1):
            if temp_grid[j][i] == temp_grid[j+1][i] and temp_grid[j][i] != 0:
                cnt += 1

        for j in range(n-1):
            if temp_grid[i][j] == temp_grid[i][j+1] and temp_grid[i][j] != 0:
                cnt += 1
    
    return cnt

ans = 0

for i in range(n):
    for j in range(n):
        temp_grid = [[0 for _ in range(n)] for _ in range(n)]
        for x in range(n):
            for y in range(n):
                temp_grid[x][y] = grid[x][y]
        
        explode(i,j)
        down()
        ans = max(ans, countAdjacency())

print(ans)