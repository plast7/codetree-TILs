n, b = map(int, input().split())
student = [list(map(int, input().split())) for _ in range(n)]
maxstudent = 0

for i in range(n):
    ans = 0
    total = 0
    test = [student[j] for j in range(n)]
    test[i][0] = test[i][0] / 2
    testresult = [sum(l) for l in test]
    testresult.sort()

    for k in range(n):
        total += testresult[k]
        if total <= b:
            ans += 1
    
    maxstudent = max(ans, maxstudent)

print(maxstudent)