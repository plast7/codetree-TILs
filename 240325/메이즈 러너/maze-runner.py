import copy


def isRange(x, y):
    if 1 <= x <= n and 1 <= y <= n:
        return True
    else:
        return False


def calculate(x1, y1, x2, y2):
    length = abs(x1 - x2) + abs(y1 - y2)
    return length


n, m, k = map(int, input().split())
MAX_N = 11
maze = [[0] * (n + 1) for _ in range(n + 1)]
participant = []

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# init
for i in range(1, n + 1):
    maze[i] = [0] + list(map(int, input().split()))
for i in range(m):
    participant.append(list(map(int, input().split())))
exit = list(map(int, input().split()))

participant_move = 0


def isParticipantHere(r, c, boxsize, participant):
    f = False
    for i in range(len(participant)):
        if r <= participant[i][0] <= r + boxsize and c <= participant[i][1] <= c + boxsize:
            f = True
    if f:
        return True
    else:
        return False


def move(maze, participant, participant_move, exit):
    participant_exit = [False] * (len(participant))

    # 만일 현재 위치가 출구라면,
    for i in range(len(participant)):
        px = participant[i][0]
        py = participant[i][1]
        if px == exit[0] and py == exit[1]:
            participant_exit[i] = True

    # 모든 참가자들 이동
    for i in range(len(participant)):
        # 현재 참가자 위치
        px = participant[i][0]
        py = participant[i][1]

        min_length = calculate(px, py, exit[0], exit[1])
        min_dir = -1
        for j in range(4):
            nx = px + dx[j]
            ny = py + dy[j]
            # 움직일 수 있는지 체크
            if isRange(nx, ny) and maze[nx][ny] == 0:
                length = calculate(nx, ny, exit[0], exit[1])
                if length < min_length:
                    min_length = length
                    min_dir = j
        if min_dir != -1:
            participant[i][0] += dx[min_dir]
            participant[i][1] += dy[min_dir]
            participant_move += 1
            if participant[i][0] == exit[0] and participant[i][1] == exit[1]:
                participant_exit[i] = True

    new_participant = []
    for i in range(len(participant)):
        if not participant_exit[i]:
            new_participant.append(participant[i])

    return new_participant, participant_move


def isGameEnd(participant):
    if len(participant) == 0:
        return True
    else:
        return False


def rotation(maze, participant, exit):
    # 가장 가까운 참가자 찾기
    min_length = 1000
    min_par = -1
    for i in range(len(participant)):
        length = calculate(participant[i][0], participant[i][1], exit[0], exit[1])
        if length < min_length:
            min_length = length
            min_par = i

        elif length == min_length:
            if participant[min_par][0] > participant[i][0]:
                min_par = i
            elif participant[min_par][0] == participant[i][0]:
                if participant[min_par][1] > participant[i][1]:
                    min_par = i

    # 가장 가까운 참가자랑 출구로 정사각형
    # 가장 작은 크기를 갖는 정사각형이 2개 이상이라면,
    # 좌상단 r 좌표가 작은 것이 우선되고, 그래도 같으면 c 좌표가 작은 것이 우선
    boxsize = max(abs(participant[min_par][0] - exit[0]), abs(participant[min_par][1] - exit[1]))

    min_box_r = 11
    min_box_c = 11
    box_r = exit[0]
    box_c = exit[1]
    for i in range(boxsize + 1):
        for j in range(boxsize + 1):
            box_r = exit[0] - i
            box_c = exit[1] - j
            if isRange(box_r, box_c):
                if isParticipantHere(box_r,box_c,boxsize,participant):
                    if min_box_r == box_r:
                        if min_box_c > box_c:
                            min_box_r = box_r
                            min_box_c = box_c
                    elif min_box_r > box_r:
                        min_box_r = box_r
                        min_box_c = box_c

    # 1. maze에 참가자 위치 채움
    for i in range(len(participant)):
        maze[participant[i][0]][participant[i][1]] = 999
    maze[exit[0]][exit[1]] = -1

    new_maze = copy.deepcopy(maze)

    # 회전

    y = min_box_c + boxsize + 1
    for i in range(min_box_r, min_box_r + boxsize + 1):
        x = min_box_r
        y -= 1
        for j in range(min_box_c, min_box_c + boxsize + 1):
            if maze[i][j] > 0 and maze[i][j] != 999:
                maze[i][j] -= 1
            new_maze[x][y] = maze[i][j]
            x += 1

    maze = copy.deepcopy(new_maze)
    participant = []

    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if maze[i][j] == 999:
                maze[i][j] = 0
                participant.append([i, j])
            if maze[i][j] == -1:
                maze[i][j] = 0
                exit = (i, j)

    return participant, maze, exit


flag = False
for _ in range(k):
    participant, participant_move = move(maze, participant, participant_move, exit)
    # 게임 끝났는지 확인
    if isGameEnd(participant):
        print(participant_move)
        for i in exit:
            print(i, end=" ")
        flag = True
        break
    else:
        participant, maze, exit = rotation(maze, participant, exit)
        # print(maze)
if flag != True:
    print(participant_move)
    for i in exit:
        print(i, end=" ")

# print(sum(participant_move), exit)