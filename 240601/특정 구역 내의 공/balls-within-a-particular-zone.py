import sys
import itertools

inf = 1 << 30

x = [0] * 3010
y = [0] * 3010

t = [0] * 3010

def compress(a, z):
    global t
    t[:z] = a[:z]
    t[:z] = sorted(t[:z])
    nz = len(list(itertools.groupby(t[:z])))
    a[:z] = [(t.index(a[i]) * 2) for i in range(z)]
    return nz * 2

xz, yz = 0, 0
arr = [['.'] * 6010 for _ in range(6010)]

gz = 0
mx = [-1, 0, 1, 0]
my = [0, -1, 0, 1]

sx = []
sy = []

def put(x, y):
    global gz
    if x < 0 or x >= xz or y < 0 or y >= yz:
        return
    if arr[x][y] == 'X':
        return
    gz += (arr[x][y] == 'C')
    arr[x][y] = 'X'
    sx.append(x)
    sy.append(y)

def dfs(startx, starty):
    put(startx, starty)
    while sx:
        x = sx.pop()
        y = sy.pop()
        for i in range(4):
            nx = x + mx[i]
            ny = y + my[i]
            put(nx, ny)

def main():
    input = sys.stdin.read
    data = input().split()
    idx = 0

    n = int(data[idx])
    idx += 1
    m = int(data[idx])
    idx += 1

    z = 0
    x[z] = y[z] = -inf
    z += 1
    x[z] = y[z] = inf
    z += 1

    for i in range(2 * n):
        x[z] = int(data[idx])
        idx += 1
        y[z] = int(data[idx])
        idx += 1
        z += 1

    for i in range(m):
        x[z] = int(data[idx])
        idx += 1
        y[z] = int(data[idx])
        idx += 1
        z += 1

    global xz, yz
    xz = compress(x, z)
    yz = compress(y, z)

    for i in range(n):
        a = i * 2 + 2
        b = i * 2 + 3
        x1, y1 = x[a], y[a]
        x2, y2 = x[b], y[b]
        if x1 == x2:
            if y1 > y2:
                y1, y2 = y2, y1
            while y1 <= y2:
                arr[x1][y1] = 'X'
                y1 += 1
        else:
            if x1 > x2:
                x1, x2 = x2, x1
            while x1 <= x2:
                arr[x1][y1] = 'X'
                x1 += 1

    for i in range(m):
        a = i + 2 * n + 2
        arr[x[a]][y[a]] = 'C'

    ans = 0
    for i in range(m):
        a = i + 2 * n + 2
        global gz
        gz = 0
        dfs(x[a], y[a])
        ans = max(ans, gz)

    print(ans)

if __name__ == "__main__":
    main()