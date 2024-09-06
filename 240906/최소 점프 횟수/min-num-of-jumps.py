n = int(input())

arr= list(map(int,input().split()))

#0에서 시작
dest = 0
cnt0 =0

#답 있다고 가정
flg = True
import sys 

ans = sys.maxsize 

way = []
def jump(m):
    global ans
    global cnt0
    global dest
    global flg

    if arr[0]==0:
        flg = False
        return


    if sum(way) >= n-1:
        # print(way)
        # print(len(way))
        ans = min(ans, len(way))
        
        return  

    if m>n+1 and sum(way)<n:
        return

    for i in range(n-1):
        #print('i:',i)
        if arr[i]>=1:
            for j in range(1,arr[i]+1):   
                #print(j,arr[i],way)
                way.append(j)
                #dest += j
                jump(m+1)
                way.pop()
                #dest-=j
        
    return

jump(1)
if (flg):
    print(ans)
else:
    print(-1)