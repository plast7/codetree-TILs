from collections import deque

def print_board(board):
    for line in board:
        print(line)


def is_board(x, y):
    return 0 <= x < N and 0 <= y < N


def cal_distance(x1, y1, x2, y2):
    return pow(x1 - x2, 2) + pow(y1 - y2, 2)


def select_direction(santa, rudolf):
    # 방향이 위쪽
    if santa[0] - rudolf[0] < 0:
        if santa[1] == rudolf[1]:
            return 0  # 상
        elif santa[1] < rudolf[1]:
            return 6  # 상좌
        else:
            return 4  # 상우
    # 방향이 아래쪽
    elif santa[0] - rudolf[0] > 0:
        if santa[1] == rudolf[1]:
            return 2  # 하
        elif santa[1] < rudolf[1]:
            return 7  # 하좌
        else:
            return 5  # 하우
    # 방향이 좌/우
    else:
        if santa[1] < rudolf[1]:
            return 3  # 좌
        else:
            return 1  # 우

def crash(who, dir, santa_id, x, y):
    global board
    score = D if who == "santa" else C
    santa_info[santa_id][1] += score    # 충돌 점수 획득
    santa_info[santa_id][2] = 2      # 산타 기절

    # 산타가 이동한 반대 방향으로 이동
    if who == "santa":
        # print("산타충돌!!")
        if dir %2 == 0: # 상 하
            dir = dir_ver[abs(dir_ver.index(dir)-1)]

        else:   # 좌 우
            dir = dir_hori[abs(dir_hori.index(dir)-1)]

    q = deque()
    q.append([santa_id, x, y, dir, score])
    while q:
        moving, x, y, dir, score = q.popleft()
        nx = x + dx[dir]*score
        ny = y + dy[dir]*score

        # 산타가 탈락한 경우
        if not is_board(nx, ny):
            santa_info[moving][3] = True    # 탈락 상태 on
            remove_santa.append(moving)        # 탈락 산타 리스트 추가
            break
        # 상호작용이 시작
        if board[nx][ny] >0 and board[nx][ny] != moving:
            q.append([board[nx][ny], nx, ny, dir, 1])
            santa_info[moving][0] = [nx, ny]

        # 상호작용이 필요 없는 경우
        else:
            santa_info[moving][0] = [nx, ny]
            break

    board = [[0] * N for _ in range(N)]
    for key, value in santa_info.items():
        if not value[3]:
            x, y = value[0][0], value[0][1]
            board[x][y] = key

    board[r_x][r_y] = -1

    return

def santa_move(info, key):
    x, y = info[0], info[1]
    cur_dis = cal_distance(x, y, r_x, r_y)
    candi = []
    # 산타 움직일 방향(우선순위: 상-우-하-좌)
    for d in range(4):
        nx = x + dx[d]
        ny = y + dy[d]
        # 이동한 경우 게임 밖 / 다른 산타가 존재: 이동 x
        if not is_board(nx, ny) or board[nx][ny] > 0:
            continue
        next_dis = cal_distance(nx, ny, r_x, r_y)
        # 루돌프와의 거리가 줄어듦
        if cur_dis > next_dis:
            cur_dis = next_dis
            candi.append([nx, ny, d])
    # 이동할 수 없음
    if len(candi) == 0: return
    nx, ny, dir = candi.pop()

    # 2.1 산타 이동으로 인한 충돌
    if [r_x, r_y] == [nx, ny]:
        crash("santa", dir, key, nx, ny)

    else:
        santa_info[key][0] = [nx, ny]
        board[x][y] = 0
        board[nx][ny] = key




#  상:0, 우:1, 하:2, 좌:3, 상우:4, 하우:5, 상좌:6, 하좌:7
dx = [-1, 0, 1, 0, -1, 1, -1, 1]
dy = [0, 1, 0, -1, 1, 1, -1, -1]

dir_santa = [[0,2], [3,1]]
dir_ver = [0, 2]    # 상, 하, 짝수
dir_hori = [3, 1]   # 좌, 우, 홀수

N, M, P, C, D = map(int, input().split())
r_x, r_y = map(int, input().split())

init_santas = [list(map(int, input().split())) for _ in range(P)]
board = [[0] * N for _ in range(N)]

# 빈칸 : 0, 루돌프: -1, 산타: 1~P
board[r_x - 1][r_y - 1] = -1
r_x = r_x - 1
r_y = r_y - 1
# 산타의 상태를 저장하는 해시 : {산타 번호 : [산타 위치, 점수, 기절 상태, 탈락 여부]}
santa_info = {i: [0, 0, 0, False] for i in range(1, P + 1)}

for idx, x, y in init_santas:
    board[x - 1][y - 1] = idx
    santa_info[idx][0] = [x - 1, y - 1]

remove_santa = []  # 탈락한 산타를 저장


# M번 동안 턴 명령
for asdf in range(M):
    # P명의 산타가 탈락한 경우
    if len(remove_santa) == P:
        break
    # 기절 상태 산타 확인
    for key, value in santa_info.items():
        if value[2] > 0 and not value[3]:
            santa_info[key][2] -= 1

    # 1. 루돌프 이동
    temp = []
    max_distance = 0

    # 1.1 가장 가까운 산타 선택
    for idx in range(1, P + 1):
        # 탈락한 산타는 제외
        if santa_info[idx][3]:
            temp.append(1000)
            continue
        x, y = santa_info[idx][0][0], santa_info[idx][0][1]
        temp.append(cal_distance(x, y, r_x, r_y))

    min_distance = min(temp)

    # 가까운 위치에 있는 산타 후보
    candi_santa = [idx + 1 for idx, i in enumerate(temp) if i == min_distance]
    candi_santa = [[santa_info[i][0], i] for i in candi_santa]
    candi_santa.sort(reverse=True)  # r,c가 큰 순으로 우선순위 정리

    select_santa = candi_santa[0][-1]  # 선택된 산타

    # 1.2 산타로 향하는 방향 계산
    rudolf_d = select_direction(santa_info[select_santa][0], [r_x, r_y])

    # 1.3 방향으로 루돌프 이동
    board[r_x][r_y] = 0
    r_x = r_x + dx[rudolf_d]
    r_y = r_y + dy[rudolf_d]

    # 1.4 루돌프 이동으로 인한 충돌
    if board[r_x][r_y] > 0:
        crash("rudolf", rudolf_d, board[r_x][r_y], r_x, r_y)
        board[r_x][r_y] = -1
    # 충돌 없이 이동
    else:
        board[r_x][r_y] = -1

    # 2. 산타 이동
    for key, value in santa_info.items():
        # 움직일 수 없는 산타(기절 했거나, 탈락한 경우) : continue
        # 아무리 움직여도 루돌프와 가까워 지지 않는 경우: continue
        if santa_info[key][3] or santa_info[key][2] > 0: continue
        santa_move(santa_info[key][0], key)

    # 탈락하지 않은 산타 +1점
    for idx in range(1, P+1):
        if not santa_info[idx][3]:
            santa_info[idx][1] += 1


score = [str(value[1]) for value in santa_info.values()]
print(' '.join(score))