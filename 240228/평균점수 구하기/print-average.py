# 배열에 주어진 수를 입력받아 저장합니다.
arr = list(map(float, input().split()))
sum_val = 0
average = 0
n = 8

# 배열에 저장된 원소들의 합을 구합니다.
for i in range(n):
    sum_val += arr[i]
    average = sum_val / i

# 평균을 구하여 출력합니다.
print(f"{average:.1f}")