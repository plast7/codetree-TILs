n = input().split()
start = int(n[0])
end = int(n[1])
cnt = 0
sum_val = 0

# start부터 end까지의 값을 i에 넣기
for i in range(start, end+1):
    for j in range(2, i+1):
        # i가 j로 나누어 떨어지는 경우에 val에 몫 저장 
        if i % j == 0:
            val = i // j
            # 진약수들의 합 구하기
            sum_val += val
    if sum_val == i:
        cnt += 1

print(cnt)