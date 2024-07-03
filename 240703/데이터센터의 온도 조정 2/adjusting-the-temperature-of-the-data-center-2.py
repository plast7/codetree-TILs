n, c, g, h = map(int, input().split())
standards = [tuple(map(int, input().split())) for _ in range(n)]

min_num = min(low for low, high in standards)
max_num = max(high for low, high in standards)

ans = 0
for num in range(min_num - 1, max_num + 1):
    cnt = 0
    for low, high in standards:
        if num < low:
            cnt += c
        elif low <= num < high:
            cnt += g
        else:
            cnt += h
    ans = max(ans, cnt)

print(ans)