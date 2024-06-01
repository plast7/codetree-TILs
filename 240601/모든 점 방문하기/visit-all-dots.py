import sys
import copy

MAXN = 1005

def mini(a, b):
    return min(a, b)

# 변수 선언
N = 0
cows = [0] * MAXN
best = [[sys.maxsize] * 2 for _ in range(MAXN)]
best2 = [[sys.maxsize] * 2 for _ in range(MAXN)]

# 입력 받기
N = int(input())
for i in range(1, N + 1):
    cows[i] = int(input())

cows[N + 1] = 0
N += 1

cows = sorted(cows[1:N + 1])

for i in range(1, N + 1):
    if cows[i] == 0:
        best[i][0] = 0

for length in range(1, N):
    ccount = N - length

    best2 = [[sys.maxsize] * 2 for _ in range(MAXN)]

    for i in range(1, N - length + 1):
        best2[i - 1][0] = mini(best2[i - 1][0], best[i][0] + ccount * (cows[i] - cows[i - 1]))
        best2[i - 1][0] = mini(best2[i - 1][0], best[i][1] + ccount * (cows[i + length - 1] - cows[i - 1]))

        best2[i][1] = mini(best2[i][1], best[i][0] + ccount * (cows[i + length] - cows[i]))
        best2[i][1] = mini(best2[i][1], best[i][1] + ccount * (cows[i + length] - cows[i + length - 1]))

    best = copy.deepcopy(best2)

best[1][0] = mini(best[1][0], best[1][1])
print(best[1][0])