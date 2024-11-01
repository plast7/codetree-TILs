a = list(map(int, input().split()))
b = list(map(int, input().split()))
m = list(map(int, input().split()))

offset = 1000
max_r = 2000
box = [[0 for col in range(max_r+1)] for row in range(max_r+1)]

def make_box(b):
    x1, y1, x2, y2 = b[0]+offset, b[1]+offset, b[2]+offset, b[3]+offset
    for x in range(x1, x2):
        for y in range(y1, y2):
            box[x][y] = 1

def del_box(m):
    x1, y1, x2, y2 = m[0]+offset, m[1]+offset, m[2]+offset, m[3]+offset
    for x in range(x1, x2):
        for y in range(y1, y2):
            box[x][y] -= 1

make_box(a)
make_box(b)
del_box(m)

ans = 0
for x in range(max_r+1):
    for y in range(max_r+1):
        if box[x][y] == 1:
            ans += 1
print(ans)