# 변수 선언 및 입력:
n = int(input())

sum_val = 0

def get_sum(n):
    if n == 0: return 0
    sum_val += n
    get_sum(n - 1)


get_sum(n)
print(sum_val)