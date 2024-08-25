def find_max(target, length, list_pos):

    # 이진 탐색(해당 숫자 이하인 가장 큰 숫자)
    max_value = -1

    left, right = 0, length-1
    while left <= right:
        mid = (left + right) // 2
        if list_pos[mid] <= target: 
            max_value = max(max_value, mid)
            left = mid + 1
        else:
            right = mid - 1

    # return
    return max_value

def find_min(target, length, list_pos):

    # 이진 탐색(해당 숫자 이상인 가장 작은 숫자)
    min_value = n

    left, right = 0, length-1
    while left <= right:
        mid = (left + right) // 2
        if list_pos[mid] >= target: 
            min_value = min(min_value, mid)
            right = mid - 1
        else:
            left = mid + 1

    # return
    return min_value

# 입력
import sys
input = sys.stdin.readline

n, q = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(n)]
rect = [list(map(int,input().split())) for _ in range(q)]

# 계산1: 좌표 중복 제거
# 계산1: 좌표 정렬
set_x = set()
set_y = set()
for x, y in arr:
    set_x.add(x)
    set_y.add(y)

list_x = list(set_x)
list_x.sort()
length_x = len(set_x)

list_y = list(set_y)
list_y.sort()
length_y = len(set_y)

# 출력
for x1, y1, x2, y2 in rect:
    # 1: x 좌표
    cntx = find_max(x2, length_x, list_x) - find_min(x1, length_x, list_x) + 1

    # 2: y 좌표
    cnty = find_max(y2, length_y, list_y) - find_min(y1, length_y, list_y) + 1

    # 출력
    print(min(cntx, cnty))