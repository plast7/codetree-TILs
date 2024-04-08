import sys

# 변수 선언 및 입력
a = list(map(int, input().split()))

a.sort()

# Case 1. 3개의 숫자가 전부 연속한 경우
# 이 경우에는 이동할 필요가 없으므로
# 최대 이동 횟수는 0이 됩니다.
if a[0] + 1 == a[1] and a[1] + 1 == a[2]:
    print(0)
    sys.exit()

max_move = 0
# 그렇지 않은 경우 왼쪽 끝 사람이 이동하는 경우와
# 오른쪽 끝 사람이 이동하는 경우로 나뉘게 됩니다.
# 각각 거리를 한칸씩 좁혀가면서 이동하는 방식이 최대 이동횟수를 만들기 때문에
# Case 2. 왼쪽 끝 사람이 가장 먼저 이동하는 경우
# 최대 이동 횟수는 (오른쪽 끝 사람과 가운데 사람의 거리) - 1 회가 됩니다.
move = a[2] - a[1] - 1
max_move = max(max_move, move)

# Case 3. 오른쪽 끝 사람이 가장 먼저 이동하는 경우
# 최대 이동 횟수는 (왼쪽 끝 사람과 가운데 사람의 거리) - 1 회가 됩니다.
move = a[1] - a[0] - 1
max_move = max(max_move, move)

print(max_move)