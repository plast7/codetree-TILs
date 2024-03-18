import sys

INT_MAX = sys.maxsize

n, m = tuple(map(int, input().split()))
points = [0] + list(map(int, input().split()))

# dp[i][j][k] : 둘 다 시작점에서 출발하여 서로 겹치지 않게 카드를 순서대로 선택하면서
#               첫번째 사람은 마지막으로 i번 카드를 골랐고,
#               두번째 사람은 마지막으로 j번 카드를 골랐을 떄
#               지금까지 k개의 카드를 스킵했을 때
#               지금까지 온 거리의 합 중 가능한 최솟값
dp = [
    [[0] * (n + 1) for _ in range(n + 1)]
    for _ in range(n + 1)
]

# 두 카드의 거리를 계산합니다.
# 원래는 |points[x] - points[y]|가 되지만,
# x = 0의 초기값일 때에는 0을 반환해야 합니다.
def dist(x, y):
    if x == 0: return 0
    return abs(points[x] - points[y])

   
# 최소를 구하는 문제이므로 
# 처음에 dp값을 큰 값으로 설정합니다.
for i in range(n + 1):
    for j in range(n + 1):
        for k in range(m + 1):
            dp[i][j][k] = INT_MAX

# 초기조건을 설정합니다.
# Bitonic Cycle 유형에서
# 둘 다 카드를 아무것도 고르지 않은 순간입니다.
dp[0][0][0] = 0

# 뿌려주는 dp를 진행합니다.
# 이는 이미 값이 구해져 있다는 가정 하에서
# 그 다음 값을 갱신하는 형태입니다.
for i in range(n + 1):
    for j in range(n + 1):
        for k in range(m + 1):
            # 첫 번째 사람은 가장 마지막에 i번 카드를 골랐고,
            # 두 번째 사람은 가장 마지막에 j번 카드를 고르고,
            # 총 k개의 카드를 스킵한 상황에서
            # 그 다음 점으로의 이동을 고민해야 합니다.

            # dp[i][j] 값이 구해져있다는 가정 하에서
            # 그 다음 상황에 해당하는 값을 갱신해야합니다.

            # Bitonic Cycle 유형의 특성상
            # max(i, j)까지는 이미 전부 해결했기에
            # max(i, j) + 1번 점을 고려해야 하는 순간입니다.
            nex = max(i, j) + 1

            # 이미 nex가 n + 1이면 더 이상 진행하지 않습니다.
            if nex == n + 1:
                continue
            
            # 첫번째 사람이 nex카드를 뽑는 경우입니다.
            # 이 경우에는 i번 카드와 nex번 카드간의 숫자 차이만큼 더 더해줘야 합니다.
            # 이 경우를 기존 값과 비교하여 최솟값을 적어줍니다.
            dp[nex][j][k] = min(dp[nex][j][k], dp[i][j][k] + dist(i, nex))
            # 또는 카드를 스킵할 수 있습니다.
            if k != m:
                dp[nex][j][k + 1] = min(dp[nex][j][k + 1], dp[i][j][k])

            # 두번째 사람이 nex카드를 뽑는 경우입니다.
            # 이 경우에는 j번 카드와 nex번 카드간의 숫자 차이만큼 더 더해줘야 합니다.
            # 이 경우를 기존 값과 비교하여 최솟값을 적어줍니다.
            dp[i][nex][k] = min(dp[i][nex][k], dp[i][j][k] + dist(j, nex))
            # 또는 카드를 스킵할 수 있습니다.
            if k != m:
                dp[i][nex][k + 1] = min(dp[i][nex][k + 1], dp[i][j][k])

# 한 쪽이 n인 경우에 대해서 최솟값을 구해줍니다.
# 문제 특성상 dp[i][j]는 dp[j][i]와 값이 같을 것이므로
# 답 계산시 한쪽만 고려해도 됩니다.
ans = INT_MAX
for i in range(0, n):
    ans = min(ans, dp[i][n][m])

print(ans)