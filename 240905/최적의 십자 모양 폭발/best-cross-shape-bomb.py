dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]
def find(temp):
    ans = 0
    for row in range(n):
        r = 0
        while r < n:
            count = 1
            while r + count < n and temp[r][row] != 0 and temp[r+count][row] != 0 and temp[r + count][row] == temp[r][row]:
                count += 1
            if count == 2:
                ans +=1
            r += 1

    temp2 = [row[:]for row in temp]
    for r in range(n):
        for c in range(n):
            temp[c][n-1-r] = temp2[r][c]

    for row in range(n):
        r = 0
        while r < n:
            count = 1
            while r + count < n and temp[r][row] != 0 and temp[r+count][row] != 0 and  temp[r + count][row] == temp[r][row]:
                count += 1
            if count == 2:
                ans += 1
            r += 1
    return ans
def move(v):
    temp = [[0]*n for _ in range(n)]
    for i in range(n):
        next = n - 1
        for j in range(n-1, -1, -1):
            if v[j][i]!=0:
                temp[next][i]=v[j][i]
                next-=1
    return find(temp)

def bfs(si, sj, level):
    v = [row[:] for row in arr]
    v[si][sj]=0
    for i in range(4):
        x, y = si, sj
        for _ in range(1, level):
            nx = x+dx[i]
            ny = y+dy[i]
            if 0<=nx<n and 0<=ny<n:
                v[nx][ny] = 0
                x, y = nx, ny
            else:
                break
    return move(v)


n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
ans = 0
max_sum = 0
for i in range(n):
    for j in range(n):
        if arr[i][j]!=0:
            si, sj = i, j
            level = arr[i][j]
            max_sum = bfs(si, sj, level)
            if ans < max_sum:
                ans = max_sum
print(ans)