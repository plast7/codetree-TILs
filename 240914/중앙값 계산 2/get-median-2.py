n=int(input())
if n!=0:
    listNum=list(map(int,input().split(" ")))
    for i in range(1,n+1):
        if i%2!=0:
            listSum=listNum[0:i]
            listSum.sort()
            print(listSum[i//2],end=" ")
else:
    print("0")