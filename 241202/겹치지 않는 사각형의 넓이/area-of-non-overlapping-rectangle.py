point = set()

# A와 B 직사각형 처리
for i in range(2):
    a, b, c, d = map(int, input().split())
    for x in range(a, c):
        for y in range(b, d):
            point.add((x, y))

# M 직사각형 처리
e, f, g, h = map(int, input().split())
for j in range(e, g):
    for k in range(f, h):
        point.discard((j, k))
        
print(len(point))
