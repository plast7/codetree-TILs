# 변수 선언
n, m = map(int, input().split())
points = [0] * (n + 1)

# dp[i][j][k][l] : 둘 다 시작점에서 출발하여 서로 겹치지 않게 카드를 순서대로 선택하면서
#                  마지막으로 i번 카드까지 확인했고,
#                  첫번째 사람은 마지막으로 j번 카드를 골랐고,
#                  두번째 사람은 마지막으로 k번 카드를 골랐을 때
#                  지금까지 l개의 카드를 스킵했을 때
#                  지금까지 온 거리의 합 중 가능한 최솟값
dp = [[[[2e9 for _ in range(m + 1)] for _ in range(n + 1)] for _ in range(n + 1)] for _ in range(n + 1)]

for i in range(1, n+1):
    points[i] = int(input())

# 두 카드의 거리를 계산합니다.
# 원래는 |points[x] - points[y]|가 되지만,
# x = 0의 초기값일 때에는 0을 반환해야 합니다.
def Dist(x, y):
    if x == 0: return 0
    return abs(points[x] - points[y])

# 최소를 구하는 문제이므로 
# 처음에 dp값을 큰 값으로 설정합니다.
# 초기조건을 설정합니다.
# Bitonic Cycle 유형에서
# 둘 다 카드를 아무것도 고르지 않은 순간입니다.
dp[0][0][0][0] = 0

# 뿌려주는 dp를 진행합니다.
# 이는 이미 값이 구해져 있다는 가정 하에서
# 그 다음 값을 갱신하는 형태입니다.
for i in range(n + 1):
    for j in range(n + 1):
        for k in range(n + 1):
            for l in range(m + 1):
                # 지금까지 i번 카드까지 확인했고,
                # 첫 번째 사람은 가장 마지막에 j번 카드를 골랐고,
                # 두 번째 사람은 가장 마지막에 k번 카드를 고르고,
                # 총 l개의 카드를 스킵한 상황에서
                # 그 다음 점으로의 이동을 고민해야 합니다.

                # dp[i][j][k][l] 값이 구해져있다는 가정 하에서
                # 그 다음 상황에 해당하는 값을 갱신해야합니다.

                # Bitonic Cycle 유형의 특성상
                # i번 카드까지는 이미 전부 해결했기에
                # i + 1번 카드를 고려해야 하는 순간입니다.
                next = i + 1

                # 이미 next가 n + 1이면 더 이상 진행하지 않습니다.
                if next == n + 1:
                    continue

                # 첫번째 사람이 next카드를 뽑는 경우입니다.
                # 이 경우에는 j번 카드와 next번 카드간의 숫자 차이만큼 더 더해줘야 합니다.
                # 이 경우를 기존 값과 비교하여 최솟값을 적어줍니다.
                dp[next][next][k][l] = min(dp[next][next][k][l], dp[i][j][k][l] + Dist(j, next))

                # 두번째 사람이 next카드를 뽑는 경우입니다.
                # 이 경우에는 k번 카드와 next번 카드간의 숫자 차이만큼 더 더해줘야 합니다.
                # 이 경우를 기존 값과 비교하여 최솟값을 적어줍니다.
                dp[next][j][next][l] = min(dp[next][j][next][l], dp[i][j][k][l] + Dist(k, next))

                # 또는 카드를 스킵할 수 있습니다.
                if l != m:
                    dp[next][j][k][l + 1] = min(dp[next][j][k][l + 1], dp[i][j][k][l])

# n에 도달한 경우에 대해서 최솟값을 구해줍니다.
ans = 2e9
for j in range(n + 1):
    for k in range(n + 1):
        ans = min(ans, dp[n][j][k][m])

print(ans)