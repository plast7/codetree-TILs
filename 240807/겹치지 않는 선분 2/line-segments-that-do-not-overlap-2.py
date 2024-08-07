#x1은 본인이 작은데, x2가 다른 선분이 작다면 -> 무조건 겹침.
n = int(input())
points = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

sorted_points = sorted(points)
cnt = 0

for i in range(n):
    x1, x2 = sorted_points[i]
    duplicate= False
    for j in range(n):
        if i == j:
            continue
        xx1, xx2 = sorted_points[j]

        if (x1 < xx1 and xx1 < xx2 and xx2 < x2) or (xx1 < x1 and x1 < x2 and x2 < xx2) or (x2 < xx2 and xx2 < xx1 and xx1 < x1) or (xx2 < x2 and x2 < x1 and x1 < xx1):
            duplicate = True
        if (x2 < xx1 and xx1 < x1 and x1 < xx2) or (x1 < xx2 and xx2 < x2 and x2 < xx1) or (xx1 < x2 and x2 < xx2 and xx2 < x1) or (x2 < xx1 and xx1 < xx2 and xx2 < x1):
            duplicate = True

    if duplicate:
        cnt += 1

print(n - cnt)