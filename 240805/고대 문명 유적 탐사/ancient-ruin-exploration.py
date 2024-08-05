from collections import deque
from copy import deepcopy

def rotate(i,j,cnt):
    i-=1
    j-=1
    sub_mat = [row[j:j+3] for row in mat[i:i+3]]   
    new_mat = deepcopy(mat) 
    for _ in range(cnt):
        sub_mat = list(map(list, zip(*sub_mat[::-1])))
    for sx in range(3):
        for sy in range(3):
            new_mat[sx+i][sy+j] = sub_mat[sx][sy] 
    return new_mat

def cal_score(mat):
    score = 0
    visit = [[False]*5 for _ in range(5)]
    dy = [-1,1,0,0]
    dx = [0,0,-1,1]
    for i in range(5):
        for j in range(5):
            if not visit[i][j]:
                q, trace = deque([(i,j)]), deque([(i,j)])
                visit[i][j] = True
                while q:
                    cur = q.popleft()
                    for d in range(4):
                        ny, nx = cur[0] + dy[d], cur[1]+dx[d]
                        if 0<=ny<5 and 0<=nx<5 and visit[ny][nx] == False and mat[ny][nx] == mat[cur[0]][cur[1]]:
                            q.append((ny,nx))
                            trace.append((ny,nx))
                            visit[ny][nx] = True
                if len(trace) >= 3:
                    score += len(trace)
                    while trace:
                        t = trace.popleft()
                        mat[t[0]][t[1]] = 0
    return score

def fill(m,n):
    for j in range(5):
        for i in range(4,-1,-1):
            if m[i][j] == 0:
                m[i][j] = n.popleft()
    return m

k, m = map(int, input().split())
mat = []
for i in range(5):
    mat.append(list(map(int,input().split())))
num = list(map(int,input().split()))
num = deque(num)

for _ in range(k):
    maxScore = 0
    maxScoreMat = None
    for cnt in range(1,4):
        for i in range(1,4):
            for j in range(1,4):
                rotated = rotate(i,j,cnt)
                score = cal_score(rotated)
                if maxScore < score:
                    maxScore = score
                    maxScoreMat = rotated
    if maxScoreMat is None:
        break
    mat = maxScoreMat
    while True:
        mat = fill(mat,num)
        newScore = cal_score(mat)
        if newScore == 0:
            break
        maxScore += newScore
    print(maxScore, end =" ")