# 배열을 구현하여 주어진 수를 입력받습니다.
arr = list(map(int, input().split()))
sum_val = 0

# 입력받은 수들을  sum에 더합니다.
for elem in arr:
	sum_val += elem
	
# sum을 출력합니다.
print(sum_val + 1)