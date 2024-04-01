import sys
from collections import deque

def drawloc(): ## 사람좌표랑 출구 표시하는거
    for x,y in persons:
        maze[x][y] = '*'
    
    maze[exitx][exity] = '+'


def moveloc():
    global mvcnt
    # print("으뱌뱝")
    # print(persons)
    perlen = len(persons)
    for i in range(perlen): ## 참가자 수 별로 이동 해야함
        x,y = persons.popleft() ## 각 참가자 좌표 추출
        exitflag = False ##탈출Flag

        difflst = [] ## 네 방향 별 거리 저장 리스트, 제일 최대값 넣어놓기
        curdiff = abs(x - exitx) + abs(y - exity) ## 현재 머물고 있는 칸과 출구까지의 거리

        for j in range(4): ## 상하 좌우 비교
            cx = x + dx[j]
            cy = y + dy[j]

            if 0<=cx<n and 0<=cy<n:
                if cx == exitx and cy == exity: ## 다음 방향에 탈출구 있을때,
                    maze[x][y] = 0 ## 현재 참가자가 있던 곳 0으로 바꿔주기
                    exitflag = True
                    mvcnt += 1
                    continue ## 밑에 다 패스
                if (maze[cx][cy] == 0):
                    diff = abs(cx - exitx) + abs(cy - exity) ## 거리계산
                    if diff < curdiff: ## 이동하는 칸이 현재 머물러 있는 칸보다 출구와의 거리가 가까운 경우
                        difflst.append((cx, cy, j, diff)) ## 이동된 방향, 현재 기준 이동했던 방향, 거리 넣어주기
        
        if exitflag:
            continue ## 현재 좌표 기준으로 탈출했다면, 밑에꺼 안함

        # if x == 1 and y == 4:
        #     print("hi")
        #     print(difflst)

        ## 최소값 뽑아주기
        if len(difflst) == 0 : ## 갈곳이 없는 것
            persons.append((x,y)) ## 그냥 현재 값 그대로 넣어주기, 위치 유지
        elif len(difflst) == 1 : ## 갈곳이 하나인 경우
            persons.append((difflst[0][0], difflst[0][1]))
            maze[x][y] = 0 ##현재값은 빈값으로
            maze[difflst[0][0]][difflst[0][1]] = '*' ## 움직이는 값은 표시
            mvcnt += 1
            # print(persons)
        else: ## 갈수 있는 칸이 여러개 인 경우, 그 중에 최소값을 가지는 칸으로 이동
            # print(difflst, x,y)
            mindiff = min(difflst, key=lambda x: x[3])[3]
            # print(mindiff)
            minlst = []
            for xm in range(len(difflst)):
                if mindiff == difflst[xm][3]: 
                    minlst.append(difflst[xm])

            if len(minlst) == 1: ##최소값이 하나라면
                persons.append((minlst[0][0], minlst[0][1]))
                maze[x][y] = 0 ##현재값은 빈값으로
                maze[minlst[0][0]][minlst[0][1]] = '*' ## 움직이는 값은 표시
                mvcnt += 1
            else: ## 두개 이상이라면 상하를 우선시 해야함
                ## 세번째 요소 i (이동하는 방향 값을) 오름차순으로 정렬해서 무조건 맨 첫번째 요소가 가지는 방향으로 이동
                # print(';pubao')
                # print(minlst)
                minlst = sorted(minlst, key=lambda x: x[2])
                persons.append((minlst[0][0], minlst[0][1])) ## 
                maze[x][y] = 0 ##현재값은 빈값으로
                maze[minlst[0][0]][minlst[0][1]] = '*' ## 움직이는 값은 표시
                mvcnt += 1


def findSquare():

    squares = []

    for x,y in persons:
        ## 출구와의 거리 구하기
        diffx, diffy = abs(x - exitx), abs(y - exity)
        maxdist = 0
        if diffx == diffy: ## 둘의 거리가 같다면
            maxdist = diffx
        else: ##다르다면,
            maxdist = max(diffx, diffy)  ## 더 큰걸로 잡아야함 

        # print(maxdist, exitx, exity)
        
        if x <= exitx: ## 현재 참가자의 x가 출구의 x보다 작을때, 현재 좌표가 왼족에 있을대
            leftx = exitx - maxdist
            rightx = exitx

            if leftx < 0:
                rightx = exitx + abs(leftx)
                leftx = 0

        if x > exitx:
            rightx = exitx + maxdist
            leftx = exitx

            if rightx > x:
                leftx = exitx - abs(maxdist - rightx)
                rightx = x

        if y <= exity: ## 현재 참가자의 y 좣표 또한 출구보다 왼쪽에 있을때,
            ## 출구 기준으로 ㄱ일단 먼저 좌측으로 옮기기
            lefty = exity - maxdist
            righty = exity
            
            if lefty < 0:
                righty = exity + abs(lefty)
                lefty = 0

        if y > exity: #y > exity: ##  이럴 때는 rightx의 마지노선이 y 값임

            righty = exity + maxdist
            lefty = exity

            if righty > y:
                lefty = exity - abs(maxdist - righty)
                righty = y

        #maze[x][y] = "*" ## 사람 표시
        squares.append([(leftx, lefty), (leftx, righty), (rightx, lefty), (rightx, righty), maxdist])

    squares = sorted(squares, key=lambda x: (x[4], x[0]))
    # print(squares)
    return squares[0] ## 맨 앞에 꺼를 갖고오기

def chksquare(squareloc):

    leftx = squareloc[0][0]
    rightx = squareloc[2][0]
    lefty = squareloc[0][1]
    righty = squareloc[3][1]

    boxloc = []

    for i in range(leftx, rightx+1):
        for j in range(lefty, righty+1):
            boxloc.append((i,j))

    # print(boxloc)

    return boxloc
                    
def rotateSquare(squareloc, squarechk):
    global exitx, exity

    boxwidth = squareloc[4] + 1
    boxary = [[0 for _ in range(boxwidth)] for _ in range(boxwidth)]

    ## squareloc의 맨 첫번째 좌표 값만큼 빼줘야, boxary 좌표에 접근할 수 있음
    mx, my = squareloc[0][0], squareloc[0][1]
    # print("whhlkeh;wlkfh;kl")
    # print(persons)

    for i in range(len(squarechk)):
        cx, cy = squarechk[i][0], squarechk[i][1]

        tmpx, tmpy = cx-mx, cy-my

        boxary[tmpx][tmpy] = maze[cx][cy]
        ## 일단 박스에 원래 값 넣어주기
    # print(mx, my)
    yvalue = my + squareloc[4] ## 얘를 boxary 한 행 씩 돌 때마다 하나씩 빼줘서 y값으로 넣어주면 됨
    ## 박스값 확인
    # for i in range(boxwidth):
    #     print(*boxary[i])

    for i in range(boxwidth):
        for j in range(boxwidth):
            # print(mx, j, yvalue, i, j, boxary[i][j])
            
            if type(boxary[i][j]) == str:
                # print("hellpo")
                # print(persons)
                if boxary[i][j] == '*': ## 원래 참가자의 위치고, 이동할 방향의 값이 0이라면 이동 가능
                    # print(i,j)
                    persons.remove((i+mx,j+my)) ## 원래 위치에 있던 참가자 삭제
                    persons.append((mx+j, yvalue)) ## 바뀐값으로 넣어주기
                if boxary[i][j] == '+': ## 출구였다면?
                    exitx, exity = mx + j, yvalue ## 출구값 변경
                # print(maze[mx + j][yvalue])
                maze[mx + j][yvalue] = boxary[i][j]
                # print(maze[mx + j][yvalue])

            else: ## INT 일 때
                if boxary[i][j] > 0:
                    maze[mx + j][yvalue] = boxary[i][j] - 1
                else: ## 0이라면 그냥 대입
                    maze[mx + j][yvalue] = boxary[i][j]



            boxary[i][j] = 0 ## 박스 초기화

        yvalue -= 1
        # print("변환후")
        # for i in range(n):
        #     print(*maze[i])

    # print(persons)
    # print(exitx, exity)




if __name__ == "__main__":

    n,m,k = map(int, sys.stdin.readline().split())
    ## n : 미로의 크기, m : 참가자수,  k : 게임시간

    maze = [] ## 미로 저장 맵
    mvcnt = 0 ## 이동 횟수

    for _ in range(n):
        maze.append(list(map(int, sys.stdin.readline().split())))

    ## 참가자의 좌표
    persons = deque() ## 참가자 저장하는 큐

    for _ in range(m):
        x,y = map(int, sys.stdin.readline().split())
        persons.append((x-1,y-1))
        ## 문제 기준 좌상단 좌표가 1,1 이라해서 나는 0,0이 편해서 -1 해주는 거임

    ## 출구 좌표 입력
    exitx, exity = map(int, sys.stdin.readline().split())
    exitx -= 1
    exity -= 1
    ## 얘도 마찬가지로.


    dx = [-1, 1, 0, 0] ## 맨앞에 두개가 상하인듯
    dy = [0, 0, -1, 1] 

    # print(persons)
    
    drawloc() ## 처음에만 한번 그려주기..

    for idx in range(k): ## k초 동안 반복

        # print(str(idx+1) + "번쨰======================")
    
        moveloc() ## 참가자가 이동하는 함수


        # print(persons)

        # for i in range(n):
        #     print(*maze[i])

        squareloc = findSquare() ## 정사각형 찾는것

        # print(squareloc)

        ## 위에는 각 꼭짓점을 찾는 함수 였다면, 얘는 사각형에 들어간 좌표를 모두 다 구하는 것
        squarechk = chksquare(squareloc)
        # print(squarechk) 

        ##사각형 90도로 회전
        rotateSquare(squareloc, squarechk)
        # print("=============회전후 마지막결과아==================")
        # for i in range(n):
        #     print(*maze[i])

        
    print(mvcnt)
    print(exitx+1, exity+1) ## 나는 계속 0,0~ N-1, N-1 이렇게 알고리즘 짰으니깐 마지막 출력할 떄는 각각  +1을 해줘야함 ! 문제에서는 1,1~ N,N 으로 하기 떄문