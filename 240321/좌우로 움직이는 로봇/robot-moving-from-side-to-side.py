n,m = map(int,input().split())
A = [
    (input().split())
    for _ in range(n)
]

B = [
    (input().split())
    for _ in range(m)
]

MAX_D = 50000

pos_a, pos_b = [0] * (MAX_D+1), [0] * (MAX_D+1)
time_a, time_b = 1,1

for i in range(n):
    d,order = A[i]
    for _ in range(int(d)):
        pos_a[time_a] = pos_a[time_a-1] + (1 if order == 'R' else -1)
        time_a += 1

for i in range(m):
    d,order = B[i]
    for _ in range(int(d)):
        pos_b[time_b] = pos_b[time_b-1] + (1 if order == 'R' else -1)
        time_b += 1

ans = 0
for t in range(1,MAX_D+1):
    if pos_a[t] == pos_b[t] and pos_a[t-1] != pos_b[t-1]:
        # print(t)
        ans += 1
print(ans)