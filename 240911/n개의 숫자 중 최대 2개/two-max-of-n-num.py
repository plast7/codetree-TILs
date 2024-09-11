n = int(input())
f = list(map(int, input().split()))

f_max = f[0]
for i in f:
    if i > f_max:
        f_max = i

f.remove(f_max)

f2_max = f[0]
for j in f:
    if j > f2_max:
        f2_max = j

print(f_max, f2_max)