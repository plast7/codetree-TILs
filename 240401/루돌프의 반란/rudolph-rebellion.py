import sys

input = sys.stdin.readline


#산타가 해당 위치에 존재하는지 확인
def isSanta(i, x, y):
    for j in santa:
        if j == i:
            continue
        if santa[j] == (x, y):
            return True
    return False

#산타의 위치가 범위를 벗어나는지 확인
def isalive(x, y):
    return 1 <= x < N + 1 and 1 <= y < N + 1

#거리 계산
def distanceIs(r1, c1, r2, c2):
    return ((r1 - r2) ** 2) + ((c1 - c2) ** 2)

#어떤 방향에서 왔는지 결정
def directionDecision(i, direction):
    dx, dy = 0, 0
    if direction == 0:  # 상
        dx, dy = -1, 0
    elif direction == 1:  # 우
        dx, dy = 0, 1
    elif direction == 2:  # 하
        dx, dy = 1, 0
    elif direction == 3:  # 좌
        dx, dy = 0, -1
    new_x = santa[i][0] + D * -dx
    new_y = santa[i][1] + D * -dy

    return new_x, new_y, -dx, -dy

#상호작용
def interaction(i, x, y, dx, dy):
    for key, value in list(santa.items()):
        if key == i:
            continue
        if value == (x, y):
            newx = x + dx
            newy = y + dy

            if not isalive(newx, newy):
                del santa[key]  # 안전한 삭제를 위해 사전의 사본을 반복
                faint[key] = 0
            else:
                santa[key] = (newx, newy)
                if isSanta(key, newx, newy):
                    interaction(key, newx, newy, dx, dy)



def santaCrush(i, direction):
    global rudolphLocation
    santax, santay, dx, dy = directionDecision(i, direction)

    return santax, santay, dx, dy

#산타가 움직여서 충돌
def santaCollision(i, direction):
    global rudolphLocation
    if (rudolphLocation[0], rudolphLocation[1]) == (santa[i][0], santa[i][1]):
        faint[i] += 2
        santaScore[i] += D
        santax, santay, dx, dy = santaCrush(i, direction)
        if isalive(santax, santay):
            santa[i] = (santax, santay)
            if isSanta(i, santax, santay):
                interaction(i, santax, santay, dx, dy)
        else:
            graph[santa[i][0]][santa[i][1]] = 0
            faint[i] = 0
            del santa[i]

#루돌프가 움직여서 충돌
def rudolphCollision(direction):
    global rudolphLocation
    dx, dy = 0, 0

    # 루돌프의 이동 방향에 따라 반대 방향의 dx, dy 결정
    if direction == 0:  # 상
        dx, dy = 1, 0
    elif direction == 1:  # 우상
        dx, dy = 1, -1
    elif direction == 2:  # 우
        dx, dy = 0, -1
    elif direction == 3:  # 우하
        dx, dy = -1, -1
    elif direction == 4:  # 하
        dx, dy = -1, 0
    elif direction == 5:  # 좌하
        dx, dy = -1, 1
    elif direction == 6:  # 좌
        dx, dy = 0, 1
    elif direction == 7:  # 좌상
        dx, dy = 1, 1

    to_delete = []
    for i in santa.keys():
        if (rudolphLocation[0], rudolphLocation[1]) == (santa[i][0], santa[i][1]):
            santaScore[i] += C
            faint[i] += 2
            santax, santay = santa[i][0] + C * dx, santa[i][1] + C * dy
            if isalive(santax, santay):
                santa[i] = (santax, santay)
                if isSanta(i, santax, santay):
                    interaction(i, santax, santay, dx, dy)
            else:
                graph[santa[i][0]][santa[i][1]] = 0
                to_delete.append(i)

    for i in to_delete:
        del santa[i]

#가까운 산타 찾기
def findsanta():
    global rudolphLocation
    x, y = None,None
    mindist = 100000
    for i in santa:
        if not isalive(santa[i][0],santa[i][1]):
            continue
        if distanceIs(santa[i][0], santa[i][1], rudolphLocation[0], rudolphLocation[1]) < mindist:
            mindist = distanceIs(santa[i][0], santa[i][1], rudolphLocation[0], rudolphLocation[1])
            x, y = santa[i][0], santa[i][1]
        elif distanceIs(santa[i][0], santa[i][1], rudolphLocation[0], rudolphLocation[1]) == mindist:
            if santa[i][0] > x:
                x, y = santa[i][0], santa[i][1]
            elif santa[i][0] == x:
                if santa[i][1] > y:
                    x, y = santa[i][0], santa[i][1]
    return x, y

#루돌프 움직이기
def rudolphMove():
    global rudolphLocation
    x, y = findsanta()
    if x is None or y is None:
        return
    currdistance = distanceIs((rudolphLocation[0]), rudolphLocation[1], x, y)
    bestMove = (x, y)
    rudolphdirection = -1
    for j in range(8):
        nx = mx[j] + rudolphLocation[0]
        ny = my[j] + rudolphLocation[1]
        # if isalive(nx,ny):
        if currdistance > distanceIs(nx, ny, x, y):
            currdistance = distanceIs(nx, ny, x, y)
            bestMove = (nx, ny)
            rudolphdirection = j

    graph[rudolphLocation[0]][rudolphLocation[1]] = 0
    (rudolphLocation[0], rudolphLocation[1]) = bestMove
    graph[rudolphLocation[0]][rudolphLocation[1]] = -1
    rudolphCollision(rudolphdirection)

#산타 움직이기
def santaMove():
    global rudolphLocation
    global santadirection

    for i in range(1, P + 1):
        if faint[i] > 0:
            faint[i] -= 1
            continue
        if i not in santa:
            continue
        (x, y) = santa[i]

        currdistance = distanceIs(rudolphLocation[0], rudolphLocation[1], santa[i][0], santa[i][1])
        bestMove = (x, y)
        directions = -1
        for j in range(4):
            nx = sx[j] + x
            ny = sy[j] + y

            if isalive(nx, ny):
                newDistance = distanceIs(rudolphLocation[0], rudolphLocation[1], nx, ny)
                if currdistance > newDistance:
                    if not isSanta(i, nx, ny):
                        currdistance = newDistance
                        bestMove = (nx, ny)
                        directions = j
        santa[i] = bestMove

        santadirection[i] = directions
        santaCollision(i, santadirection[i])


#게임시작
def gameset():
    global rudolphLocation
    for i in range(1, M + 1):
        if len(santa) == 0:
            break
        rudolphMove()
        santaMove()
        for key, values in santa.items():
            santaScore[key] += 1


sx, sy = [-1, 0, 1, 0], [0, 1, 0, -1]
mx, my = [1, 1, 0, -1, -1, -1, 0, 1], [0, -1, -1, -1, 0, 1, 1, 1]
# mx,my =[-1,0,1,0,-1,-1,1,1],[0,1,0,-1,-1,1,-1,1]

N, M, P, C, D = map(int, input().split())
rudolphLocation = list(map(int, input().split()))
santadirection = dict()
santa = dict()
faint = [0] * (P + 1)
santaScore = [0] * (P + 1)
graph = [[0] * (N + 1) for _ in range(N + 1)]
graph[rudolphLocation[0]][rudolphLocation[1]] = -1

for i in range(1, P + 1):
    Pn, Sr, Sc = map(int, input().split())
    santa[Pn] = (Sr, Sc)
    graph[Sr][Sc] = 1

gameset()
for i in range(1, P + 1):
    print(santaScore[i], end=' ')