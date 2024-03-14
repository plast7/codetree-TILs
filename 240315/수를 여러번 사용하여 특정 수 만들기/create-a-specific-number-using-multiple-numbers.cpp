'''
1. 서로 다른 세 정수 A B C가 주어진다.
2. num = 0에 A 혹은 B를 0회 이상 더한다.
3. 2번으로 만들 수 있는 C이하의 수 중 가장 큰 값을 구하라.

1- 내 풀이
1) for i in range(1000) C의 최대 값인 1000번을 순회하며 A를 몇 번 더할지 정한다.
2) for j in range(1000) 1번과 마찬가지로 B를 몇 번 더할지 정한다.
3) 1번 순회 중 if A*i > C인 경우 break
4) 2번 순회 중 if A*i + B*j > C: max_result 값과 A*i + B*(j-1) 값과 비교하여 최댓값 갱신 후 break
5) max_result 출력

'''

A, B, C = map(int, input().split())

max_result = 0
for i in range(1000):
    if A*i > C:
        break
    
    temp_result = A*i
    for j in range(1000):
        if A*i + B*j > C:
            max_result = max(max_result, temp_result + B*(j-1))
            break

print(max_result)