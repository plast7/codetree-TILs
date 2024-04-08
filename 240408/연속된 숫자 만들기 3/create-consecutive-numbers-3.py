a, b, c = list(map(int, input().split()))

f_dist = abs(a-b)
s_dist = abs(b-c)

# 1, 1 이 되면 끝
# 둘 다 2 이하여도 한 번만 하고 끝
# 두 조건 다 아니면, 둘 중 사이가 먼 거리 값에서 1 뺀 값이 정답
count = 0

if f_dist == 1 and s_dist == 1:
    count = 0
elif f_dist <= 2 and s_dist <= 2:
    count = 1
else:
    count = max(f_dist, s_dist) - 1

print(count)