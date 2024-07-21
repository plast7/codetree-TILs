# 변수 선언 및 입력:
n, m = tuple(map(int, input().split()))
arr = [0] + list(map(int, input().split()))

for i in range(1, n + 1):
    assert 1 <= arr[i] <= 10**9
querries = list(map(int, input().split()))

# target보다 같거나 큰 최초의 위치를 반환합니다.
def lower_bound(target):
    left, right = 1, n
    min_idx = n + 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] >= target:
            right = mid - 1
            min_idx = min(min_idx, mid)
        else:
            left = mid + 1

    return min_idx

for querry in querries:
    # 이진탐색을 진행합니다.
    # querry보다 크거나 같은 최소의 값의 위치를 구하고
    # 그 값이 querry와 같으면 위치를,
    # 다르면 -1을 출력합니다.
    lo = lower_bound(querry)
    if lo <= n and arr[lo] == querry:
        print(lo)
    else:
        print(-1)