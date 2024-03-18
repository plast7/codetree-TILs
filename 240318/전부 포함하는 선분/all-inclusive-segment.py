# 입력
n = int(input())
x1, x2 = [], []
for _ in range(n):
    x1_val, x2_val = map(int, input().split())
    x1.append(x1_val)
    x2.append(x2_val)

ans = float('inf')  # INT_MAX에 해당하는 Python 표현

# 모든 선분을 하나씩 지워보며 답을 찾습니다.
for skip in range(n):
    max_x2 = 0
    min_x1 = float('inf')
    for i in range(n):
        if i == skip:
            continue
        # 시작점 중 가장 앞에 있는 좌표와 끝점 중 가장 뒤에 있는 점의 좌표를 확인합니다.
        max_x2 = max(max_x2, x2[i])
        min_x1 = min(min_x1, x1[i])
    # 조건을 만족하는 선분의 길이는 max_x2 - min_x1입니다.
    # 정답보다 이 선분의 길이가 작으면 업데이트합니다.
    ans = min(ans, max_x2 - min_x1)

print(ans)