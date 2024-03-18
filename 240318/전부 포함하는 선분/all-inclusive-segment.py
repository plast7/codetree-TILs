# 입력
n = int(input())
x1, x2 = [], []
for _ in range(n):
    a, b = map(int, input().split())
    x1.append(a)
    x2.append(b)

ans = float('inf')

# 가장 시작점이 작은 선분을 지우거나, 가장 끝점이 큰 선분을 지울 때에만
# 전부 포함하는 선분이 줄어들 가능성이 있습니다.
# 가장 시작점이 작은 선분을 찾습니다.
skip = 0
for i in range(n):
    if x1[skip] > x1[i]: skip = i

max_x2 = 0
min_x1 = float('inf')
for i in range(n):
    if i == skip: continue

    # 시작점 중 가장 앞에 있는 좌표와 끝점 중 가장 뒤에 있는 점의 좌표를 확인합니다.
    max_x2 = max(max_x2, x2[i])
    min_x1 = min(min_x1, x1[i])

# 조건을 만족하는 선분의 길이는 max_x2 - min_x1입니다.
# 정답보다 이 선분의 길이가 작으면 업데이트합니다.
ans = min(ans, max_x2 - min_x1)

# 가장 끝점이 큰 선분을 찾습니다.
skip = 0
for i in range(n):
    if x2[skip] < x2[i]: skip = i

max_x2 = 0
min_x1 = float('inf')
for i in range(n):
    if i == skip: continue

    # 시작점 중 가장 앞에 있는 좌표와 끝점 중 가장 뒤에 있는 점의 좌표를 확인합니다.
    max_x2 = max(max_x2, x2[i])
    min_x1 = min(min_x1, x1[i])

# 조건을 만족하는 선분의 길이는 max_x2 - min_x1입니다.
# 정답보다 이 선분의 길이가 작으면 업데이트합니다.
ans = min(ans, max_x2 - min_x1)

print(ans)