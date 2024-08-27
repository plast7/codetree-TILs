n, k = map(int, input().split())
stabilities = list(map(int, input().split()))

# print(n, k)
# print(stabilities)

graph = [ [[0, False] for _ in range(n)] for _ in range(2)]   # [안정성, 사람 유무]
# print(graph)


for i in range(n):
    graph[0][i][0] = stabilities[i]

for i in range(n):
    graph[1][i][0] = stabilities[2*n-1-i]

# print(graph)

# 무빙워크 하차 
def should_getoff():
    if graph[0][n-1][1] == True:
        return True
    return False


# 무빙워크 이동 
def move_belt():
    temp = graph[1][0]
    
    for col in range(0, n-2+1):
        graph[1][col] = graph[1][col+1]
    

    graph[1][n-1] = graph[0][n-1]


    for col in range(n-1, 0, -1):
        graph[0][col] = graph[0][col-1]
    
    
    graph[0][0] = temp

    # 무빙워크 하차 여부 체크 
    if should_getoff() is True:
        graph[0][n-1][1] = False


def can_move(cur_col):
    next_col = cur_col + 1

    if graph[0][next_col][1] == True or graph[0][next_col][0] == 0:
        return False
    
    return True


# 사람 이동 
def move_person(cur_col):

    if can_move(cur_col) is True:
        next_col = cur_col+1
        graph[0][cur_col][1] = False
        graph[0][next_col][0] -= 1      # 안정성 감소
        graph[0][next_col][1] = True
    
    # 무빙워크 하차 여부 체크 
    if should_getoff() is True:
        graph[0][n-1][1] = False


# 승차
def board():
    graph[0][0][0] -= 1
    graph[0][0][1] = True


# 종료 조건
def is_done(k):
    cnt = 0
    for row in range(2):
        for col in range(n):
            if graph[row][col][0] == 0:
                cnt += 1
    
    if cnt >= k:
        return True
    
    return False


# 1회 실험 
def simulate():
    # 무빙 워크 이동 
    move_belt()      

    # 사람 이동                    
    for col in range(0, n):
        if graph[0][col][1] == True:
            move_person(col)

    # 사람 승차
    board()
    


ans = 0
while True:
    if is_done(k) is True:
        break
     
    
    simulate()
    ans += 1

print(ans)