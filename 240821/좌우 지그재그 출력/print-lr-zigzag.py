cnt=1

n=int(input())

for i in range(1,n+1):

    if i % 2 !=0:
        for _ in range(n):
            print(cnt,end=' ')
            cnt+=1
    else:
        for j in range(n):
            print(cnt+n-1-2*j,end=' ')
            cnt+=1
    print()