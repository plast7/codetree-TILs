from collections import defaultdict,deque
import sys
sys.setrecursionlimit(50000)

n,m = map(int,input().split())
edges = defaultdict(list)
for _ in range(m):
    x,y= map(int,input().split())
    edges[x].append(y)

visited = [0]*(n+1)
cnt = 0

def dfs(node):
    global visited
    flag = True
    deq = deque([])
    deq.append(node)
    visited[node] = 1
    while deq:
        n = deq.popleft()
        for next in edges[n]:
            if visited[next] == 0:
                visited[next] = 1
                deq.append(next)
            else:
                flag = False
    return flag


for i in range(1,n+1):
    if visited[i] == 0:
        if dfs(i):
            cnt+=1
for i in range(1,n+1):
    if visited[i] == 0:
        cnt+=1
print(cnt)