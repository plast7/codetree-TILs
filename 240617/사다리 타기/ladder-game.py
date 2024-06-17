def possible():
    
    # 1: 초기화
    num1 = [i for i in range(n)]
    num2 = [i for i in range(n)]
	
    # 2: 반영
    for _, idx in lines:
        num1[idx], num1[idx + 1] = num1[idx + 1], num1[idx]
    
    for _, idx in selected_lines:
        num2[idx], num2[idx + 1] = num2[idx + 1], num2[idx]
	
    # 3: 판단
    for i in range(n):
        if num1[i] != num2[i]:
            return False

    return True

def backTraking(cnt, idx):
    
    # 기저조건
    if idx == m:
        if possible():
            global min_res
            min_res = min(min_res, cnt)
        return
    
    # 백트래킹
    selected_lines.append(lines[idx])
    backTraking(cnt + 1, idx + 1)
    selected_lines.pop()
    backTraking(cnt, idx + 1)

# 입력
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
lines = []
for _ in range(m):
    a, b = map(int, input().split())
    lines.append((b, a - 1))

# 계산1: 정렬(사다리 위)
lines.sort()

# 계산2: 백트래킹
min_res = m

selected_lines = []
backTraking(0, 0)

# 출력
print(min_res)