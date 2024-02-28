# 변수 선언 및 입력:
n = int(input())


def get_sum(n):
    return get_sum(n - 1) + n


print(get_sum(n))