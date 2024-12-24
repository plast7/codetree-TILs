'''
2차원 배열의 시계방향 회전공식
행 -> SIZE-행-1
열 -> 행

상태 관리를 위해 2차원 배열 별개로 사용

<사이클>
1. 폭탄 터뜨리기 - 중력
폭탄이 터진 이후에 같은 열에 터질 폭탄이 존재한다면 터져야할 폭탄이 존재하지 않을 때까지 반복
2. 배열 회전
3. 중력 적용

배열은 n x n, 일치해야하는 블록의 개수는 m개
'''
BLANK = 0
n,m,k = map(int,input().split())

grid = [list(map(int,input().split())) for _ in range(n)]

next_grid = [[0]*n for _ in range(n)]

# 배열 회전
def rotate_array():
    for i in range(n):
        for j in range(n):
            grid[j][n-1-i] = next_grid[i][j]

# 중력 적용
def gravity():
    for i in range(n):
        for j in range(n):
            next_grid[i][j] = BLANK
    
    for j in range(n):
        idx = n-1
        for i in range(n-1,-1,-1):
            if grid[i][j] != BLANK:
                next_grid[idx][j] = grid[i][j]
                idx -= 1

def explode_bomb():
    # 더이상 폭탄이 터지지 않을 때까지 반복
    while True:
        isExploded = False
        # 모든 열에 대해서 터질 폭탄이 존재하는지 확인
        for col in range(n):
            for row in range(n):
                number = grid[row][col]
                if number == BLANK:
                    continue
                # 어디까지 이어지는지 파악
                end_row_idx = get_end_idx(row,col,number)
                # 이어지는곳이 m개 이상이라면 모두 BLANK로 변환
                if end_row_idx - row + 1 >= m:
                    isExploded = True
                    for r in range(row,end_row_idx+1):
                        grid[r][col] = BLANK
        if not isExploded:
            break


def get_end_idx(row,col,number):
    idx = row
    for r in range(row,n):
        # 공백의 경우 무시
        if grid[r][col] == BLANK:
            continue
        if grid[r][col] == number:
            idx = r
        else: # 다른 숫자인 경우
            return idx            
    return idx

def simulation():
    explode_bomb()
    gravity()
    rotate_array()
    gravity()
    # 현재 배열 정보 복사
    for i in range(n):
        for j in range(n):
            grid[i][j] = next_grid[i][j]
    explode_bomb()

for i in range(k):
    simulation()

# 남아있는 폭탄의 개수 출력
count = 0
for i in range(n):
    for j in range(n):
        if grid[i][j] != BLANK:
            count += 1

print(count)
