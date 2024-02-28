arr=list(map(int,input().split()))
a,b=arr[0],arr[1]
result=[0]*b
for _ in range(1,100):
    a//=b
    result[a%b]+=1
    if a<=1:
        break
cnt=0
for j in result:
    cnt+=j**2
print(cnt)