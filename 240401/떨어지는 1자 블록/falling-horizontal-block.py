n,m,k = map(int,input().split())
grid = [[0]*(n+1)] + [[0] + list(map(int,input().split())) for _ in range(n)]

cur_x, cur_y = (0, k)


def inRange(x, y):
    return x>=0 and x<=n and y>=1 and y<=n

def check(r, k):
    for i in range(m):
        if grid[r+1][k+i] == 1:
            return False
    
    return True

while True:
    if inRange(cur_x, cur_y) and check(cur_x, cur_y):
        cur_x += 1
    
    else:
        for i in range(m):
            grid[cur_x][cur_y+i] = 1

        break

for i in range(1, n+1):
    for j in range(1, n+1):
        print(grid[i][j], end=" ")
    print()