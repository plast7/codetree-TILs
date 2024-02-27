import sys

INT_MIN = -sys.maxsize
OFFSET = 100000

# 변수 선언 및 입력:
n = int(input())
arr = [0] + list(map(int, input().split()))

# 만들 수 있는 최대 합을 계산합니다.
m = sum(arr)

# dp[i][j] : i번째 수까지 고려헀을 떄
#            그룹 A 합 - 그룹 B 합을 j라 했을 때
#            만들 수 있는 최대 그룹 A의 합
dp = [
    [0] * (m + 1 + OFFSET)
    for _ in range(n + 1)
]


def initialize():
    # 최대를 구하는 문제이므로
    # 초기값을 INT_MIN으로 넣어줍니다.
    for i in range(n + 1):
        for j in range(-m, m + 1):
            dp[i][j + OFFSET] = INT_MIN

    # 초기 조건은
    # 아직 아무런 수도 고른적이 없는 경우이므로 
    # 0번째 수까지 고려하여
    # 그룹 A 합 - 그룹 B 합이 0이고 
    # 그룹 A의 합이 0인 경우에 대한 정보 입니다.
    dp[0][0 + OFFSET] = 0


def update(i, j, prev_i, prev_j, val):
    # 불가능한 경우 패스합니다.
    if prev_j < -m or prev_j > m or dp[prev_i][prev_j + OFFSET] == INT_MIN:
        return
    
    dp[i][j + OFFSET] = max(dp[i][j + OFFSET], dp[prev_i][prev_j + OFFSET] + val)


initialize()

# 점화식에 따라 값을 채워줍니다.
for i in range(1, n + 1):
    for j in range(-m, m + 1):
        # Case 1. 그룹 A에 i번째 원소를 추가하여 그룹A-그룹B가 j가 된 경우
        #         dp[i - 1][j - arr[i]] + arr[i] -> dp[i][j]
        update(i, j, i - 1, j - arr[i], arr[i])

        # Case 2. 그룹 B에 i번째 원소를 추가하여 그룹A-그룹B가 j가 된 경우
        #         dp[i - 1][j + arr[i]] -> dp[i][j]
        update(i, j, i - 1, j + arr[i], 0)

        # Case 3. 그룹 C에 i번째 원소를 추가하여 그룹A-그룹B가 j가 된 경우
        #         dp[i - 1][j] -> dp[i][j]
        update(i, j, i  - 1, j, 0)

# n개의 수를 고려하여
# 그룹A-그룹B가 0이 된 경우 중
# 가능한 그룹A 합의 최대값이 답이 됩니다.
print(dp[n][0 + OFFSET])