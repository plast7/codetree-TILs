from copy import deepcopy
from collections import deque

def is_range(x, y):
    return x >= 0 and y >= 0 and x < 5 and y < 5

def rotate(cnt, tx, ty):    
    target_grid = []
    for i in range (tx - 1, tx + 2):
        temp_line = []
        for j in range (ty - 1, ty + 2):
            temp_line.append(grid[i][j])
        target_grid.append(temp_line)

    for _ in range (cnt):
        target_grid = list(zip(*target_grid[::-1]))

    test_grid = deepcopy(grid)
    
    new_i = 0
    for i in range (tx - 1, tx + 2):
        new_j = 0
        for j in range (ty - 1, ty + 2):
            test_grid[i][j] = target_grid[new_i][new_j]
            new_j += 1
        new_i += 1
    
    return test_grid

def find(board):
    vis = [[False for _ in range (5)] for _ in range (5)]
    current_value = 0

    for i in range (5):
        for j in range (5):
            if vis[i][j]:
                continue

            que = deque()
            
            que.append([i, j, board[i][j]])
            vis[i][j] = True
            count = 1
            
            while que:
                x, y, value = que.popleft()
                
                for dx, dy in zip(dxs, dys):
                    nx, ny = x + dx, y + dy
                    
                    if is_range(nx, ny) and not vis[nx][ny] and board[nx][ny] == value:
                        count += 1
                        que.append([nx, ny, board[nx][ny]])
                        vis[nx][ny] = True
            
            if count >= 3:
                current_value += count
            
    return current_value if current_value >= 3 else 0

def delete(board):
    vis = [[False for _ in range (5)] for _ in range (5)]
    
    for i in range (5):
        for j in range (5):
            if vis[i][j]:
                continue
            que = deque()
            
            que.append([i, j, board[i][j]])
            vis[i][j] = True
            
            same = []
            while que:
                x, y, value = que.popleft()
                
                for dx, dy in zip(dxs, dys):
                    nx, ny = x + dx, y + dy
                    
                    if is_range(nx, ny) and not vis[nx][ny] and board[nx][ny] == value:
                        que.append([nx, ny, board[nx][ny]])
                        vis[nx][ny] = True
                        same.append((x, y))
                        same.append((nx, ny))
            
            same = list(set(same))
            if len(same) >= 3:
                for x, y in same:
                    board[x][y] = -1
    return board


# main
k, number_of_etc = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range (5)]
etc = list(map(int, input().split()))
dxs, dys = [-1, 1, 0, 0], [0, 0, -1, 1] # 상 하 좌 우
next_index = 0
ans = []

for _ in range (k):
    candidate = []
    for i in range (1, 4):
        for j in range (1, 4):
            # 가설
            # 선택된 격자는 항상 회전을 진행해야 함.
            # 아래의 반복문은 r을 회전 각도(90, 180, 270)의 값으로 설정한 뒤 사용자 정의 함수로 2차원 배열을 회전시키는 역할인데,
            # r의 반복문을 (1, 4)로 했을 때와 (0, 4)로 했을 때 모두 정답으로 처리됨
            for r in range (1, 4):
                rotated_grid = rotate(r, i, j)
                value = find(rotated_grid)
                
                if value:    
                    candidate.append((-value, r, j, i))
    if len(candidate) <= 0:
        break
    v, rr, jj, ii = sorted(candidate)[0]

    new_g = rotate(rr, ii, jj)
    deleted_grid = delete(new_g)
    
    for j in range (5):
        for i in range (4, -1, -1):
            if deleted_grid[i][j] == -1:
                deleted_grid[i][j] = etc[next_index]
                next_index += 1

    grid = deepcopy(deleted_grid)
    
    while find(grid) >= 3:
        v -= find(grid)
        deleted_grid = delete(grid)
        
        for j in range (5):
            for i in range (4, -1, -1):
                if deleted_grid[i][j] == -1:
                    deleted_grid[i][j] = etc[next_index]
                    next_index += 1
        
        grid = deepcopy(deleted_grid)

    ans.append(v)

for a in ans:
    print(-a, end=" ")