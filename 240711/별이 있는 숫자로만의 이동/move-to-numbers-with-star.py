# 변수 선언 및 입력
n, k = tuple(map(int, input().split()))
arr = [
    [0 for _ in range(n + 1)]
    for _ in range(n + 1)
]

# 부분합 계산을 원할히 하기 위해 배열을 인덱스 1부터 입력받습니다.
for i in range(n):
    board = list(map(int, input().split()))
    for j in range(n):
        arr[i + 1][j + 1] = board[j]

arr2 = [
    [0 for _ in range(2 * n + 1)]
    for _ in range(2 * n + 1)
]

s = [
    [0 for _ in range(2 * n + 1)]
    for _ in range(2 * n + 1)
]

ans = 0

def is_valid(i, j):
    if not (n + 1 <= i + j <= 3 * n - 1):
        return False
    if not (1 - n <= i - j <= n - 1):
        return False
    if (i + j) % 2 == (n + 1) % 2:
        return True
    return False

# 2차원 배열을 45도 회전시킵니다.
# 배열을 회전시키면 정사각형 부분합을 구하는 문제로
# 바뀌기 때문에 훨씬 접근하기 쉬워집니다.
for i in range(1, n + 1):
    for j in range(1, n + 1):
        arr2[i + j - 1][n - i + j] = arr[i][j]

# 2차원 배열의 누적합을 구합니다.
for i in range(1, 2 * n + 1):
    for j in range(1, 2 * n + 1):
        s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + arr2[i][j];
    
# 한 변의 길이가 k2인 정사각형 중 부분합이 최대인 사각형을 찾습니다.
k2 = min(2 * k + 1, 2 * n - 1);
for i in range(1, 2 * n + 1):
    for j in range(1, 2 * n + 1):
        if is_valid(i, j):
            ri = min(2 * n, i + k2 // 2)
            li = max(0, i - k2 // 2 - 1)
            rj = min(2 * n, j + k2 // 2)
            lj = max(0, j - k2 // 2 - 1)
            ans = max(ans, s[ri][rj] - s[ri][lj] - s[li][rj] + s[li][lj])

# 정답을 출력합니다.
print(ans)