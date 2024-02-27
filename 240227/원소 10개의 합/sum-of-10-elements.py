# 배열을 구현하여 주어진 수를 입력받습니다.
arr = list(map(int, input().split()))
n = int(input())
sum_val = 0

# 입력받은 수들을  sum에 더합니다.
for i in range(n):
	sum_val += arr[i]
	
# sum을 출력합니다.
print(sum_val)