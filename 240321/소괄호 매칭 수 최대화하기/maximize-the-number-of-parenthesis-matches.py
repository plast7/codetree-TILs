from functools import cmp_to_key

# 변수 선언 및 입력:
n = int(input())
# (개수, )개수를 쌍으로 하여 관리합니다.
brackets = []

ans = 0


# custom comparator를 직접 정의
# b1가 앞에 있는 숫자, b2가 뒤에 있는 숫자라고 가정했을 때
# 이 순서가 우리가 원하는 순서라면 0보다 작은 값을, 
# 반대라면 0보다 큰 값을
# 둘의 우선순위가 동일하다면 0을 반환하면 됩니다.
# 보통 반환값에 1, -1, 0을 사용합니다.
def compare(b1, b2):
    open1, closed1 = b1
    open2, closed2 = b2

    # open1 * closed2 > open2 * closed1라면 
    # b1이 더 앞에 있어야 하므로
    # 현재 순서가 옳습니다.
    if open1 * closed2 > open2 * closed1:
        return -1
    # open1 * closed2 < open2 * closed1라면 
    # b2가 더 앞에 있어야 하므로
    # 현재 순서는 틀렸습니다.
    if open1 * closed2 > open2 * closed1:
        return 1
    # 우선 순위가 동일한 경우입니다.
    return 0


for _ in range(n):
    s = input()
    open_num, closed_num = 0, 0 # 열린 소괄호, 닫힌 소괄호 수를 셉니다.
    for char in s:
        if char == '(':
            open_num += 1
        else:
            closed_num += 1

            # 해당 문자열 만으로 얻게 되는 점수는
            # 미리 답에 더해줍니다.
            ans += open_num

    brackets.append((open_num, closed_num))

# (b1, b2), (b2, b1) 중
# 점수를 더 많이 얻을 수 있는 경우로 정렬합니다.
brackets.sort(key=cmp_to_key(compare))

# 정렬된 순서대로 보며
# 각 문자열을 붙였을 때
# 새롭게 얻게되는 점수를 더해줍니다.
open_sum = 0
for open_num, closed_num in brackets:
    # 답을 갱신해줍니다.
    ans += open_sum * closed_num

    # open_sum을 누적해줍니다.
    open_sum += open_num

print(ans)