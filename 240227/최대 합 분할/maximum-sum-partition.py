#로직을 다르게 잡음!
n = int(input())
arr = list(map(int, input().split()))
m = sum(arr)

# 가능한 합의 경우를 다 구한다
# 해당 합의 1/2도 존재하는지 알아본다 
# 존재한다면, 그 max 값이 정답.

dp = [[0]*(m+1) for _ in range(n+1)]
dp[0][0] = 1

for i in range(1, n+1):
    for j in range(m+1): #좌측기준이지만 i-1이 기준이기에 역방향으로 하지 않아도 중복발생하지 않음!
        if j-arr[i]>=0 and dp[i-1][j-arr[i]]>0: #현재 elem이 추가되어 가능한 경우!
            dp[i][j] += 1
        if dp[i-1][j]>0: #이전에 가능한 경우!
            dp[i][j] += 1
    # print(arr[i], dp[i])

#마지막 값이 C그룹에 가는 경우에 반례가 존재 ㅠ
#따라서 이전 상태들도 봐서 가능한한 큰 경우를 선택!
result = 0
for i in range(n,-1,-1):
    for j in range(m, -1, -1):
        if j%2==0 and dp[i][j]>0 and dp[i][j//2]>1: #짝수이며 해당 값이 가능하고 반인 값이 2번 이상 가능!
            result = max(result, j//2)
            # print(i, i//2)
            break

print(result)