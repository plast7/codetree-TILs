from collections import defaultdict

answer = 0
L, N, Q = [int(x) for x in input().strip().split()]


BOARD = [
    # 0 : 빈칸
    # 1 : 함정
    # 2 : 벽
    [int(x) for x in input().strip().split()] for _ in range(L)
]


GISA = [
    # (r, c, h, w, k)
    # 처음 위치 (r, c)를 상단 꼭지점으로 하여, 세로 길이 h, 가로 길이 w인 직사각형 & 초기 체력 k
    [int(x) for x in input().strip().split()] for _ in range(N)
]

for i in range(N):
    GISA[i][0] -= 1
    GISA[i][1] -= 1

GISA_FULL_COORDINATE = dict()
GISA_STAMINA = dict()

# 기사의 위치를 BOARD 위에다 표기
GISA_INFO_BOARD = None

KING_ORDER = [
    [int(x) for x in input().strip().split()] for _ in range(Q)
]

MOVEMENT = {
    0: [-1, 0],  # 위
    1: [0, 1],   # 오른
    2: [1, 0],  # 아래
    3: [0, -1] # 왼 
}

GISA_BEING_ALIVE = list(range(1, Q+1))
DAMAGE_DICT = defaultdict(int)



#%% 


def initialize():

    global GISA_FULL_COORDINATE, GISA_STAMINA

    # 아래 변수들의 값을 채움
    # GISA_FULL_COORDINATE
    # GISA_STAMINA

    for idx, gisa in enumerate(GISA):
        coord_list = []
        start_r, start_c = gisa[0], gisa[1]
        
        x_len, y_len = gisa[2], gisa[3]
        if x_len == 1:
            x_candidates = [start_r]
        else:
            x_candidates = list(range(start_r, start_r + x_len))

        if y_len == 1:
            y_candidates = [start_c]
        else:
            y_candidates = list(range(start_c, start_c + y_len))

        for x in x_candidates:
            for y in y_candidates:
                coord_list.append([x, y])

        GISA_FULL_COORDINATE[idx+1] = coord_list
        GISA_STAMINA[idx+1] = gisa[-1]


def in_range(x, y):
    return 0 <= x < L and 0 <= y < L


def make_gisa_board():
    
    global GISA_INFO_BOARD

    GISA_INFO_BOARD = [
        [0] * L for _ in range(L)
    ]

    for idx, coordinates in GISA_FULL_COORDINATE.items():
        for coord_x, coord_y in coordinates:
            GISA_INFO_BOARD[coord_x][coord_y] = idx


# 기사가 움직인다면 움직이는 방향에 다른 기사가 있는지 
def neighbor_detecting(gisa_idx, direction):
   
    detecting_idx = [gisa_idx]

    gisa_move_idx = set([])
    dx, dy = MOVEMENT[direction]

    while detecting_idx:

        gisa_subidx = detecting_idx.pop(0)

        GISA_INDICES = GISA_FULL_COORDINATE[gisa_subidx]
        
        for gisa_x, gisa_y in GISA_INDICES:
            next_x, next_y = gisa_x + dx, gisa_y + dy

            # 기사가 움직이는데 이미 벽에 막혀 있다면 -> 아예 움직일 수 없는 것으로 판단하고 미리 return 
            if not in_range(next_x, next_y) or BOARD[next_x][next_y] == 2:
                # return gisa_move_idx if len(gisa_move_idx) != 0 else 'pass'
                return 'pass'

            # 어차피 내 위치와 겹치는 부분으로 이동하는 애들은 체크해줄 필요가 없기 때문 
            if [next_x, next_y] in GISA_INDICES:    
                continue
            
            # 내 번호가 아니면 다른 기사 번호. ( 직접 연결되지 않은 기사의 번호까지 연쇄적으로 연결 )
            gisa_board = GISA_INFO_BOARD[next_x][next_y]
            if gisa_board not in [0, gisa_subidx]:
                gisa_move_idx.add(gisa_board)

                if gisa_board not in detecting_idx:
                    detecting_idx.append(gisa_board)

    return gisa_move_idx


def judge_movable(gisa_idx, direction):

    GISA_INDICES = GISA_FULL_COORDINATE[gisa_idx]
    dx, dy = MOVEMENT[direction]

    for gisa_x, gisa_y in GISA_INDICES:
        next_x, next_y = gisa_x + dx, gisa_y + dy
        if not in_range(next_x, next_y):
            return False
        elif BOARD[next_x][next_y] == 2:
            return False
            
    return True
 

def start_actual_move(movable_idx_list, direction):

    global GISA_INFO_BOARD, GISA_FULL_COORDINATE, DAMAGE_DICT

    GISA_INFO_BOARD_CP = [
        [0] * L for _ in range(L)
    ]

    dx, dy = MOVEMENT[direction]
    stamina_minus = defaultdict(int)

    for mvi in movable_idx_list:
        coord_list = GISA_FULL_COORDINATE[mvi]
        for coord_x, coord_y in coord_list:
            next_x, next_y = coord_x + dx, coord_y + dy
            value = BOARD[next_x][next_y]
            GISA_INFO_BOARD_CP[next_x][next_y] = GISA_INFO_BOARD[coord_x][coord_y]
            if value == 1 and [next_x, next_y] not in coord_list:
                stamina_minus[mvi] += value

    GISA_INFO_BOARD = GISA_INFO_BOARD_CP

    for key, value in stamina_minus.items():
        if key != movable_idx_list[0]:
            GISA_STAMINA[key] -= value
            if GISA_STAMINA[key] <= 0:
                GISA_BEING_ALIVE.remove(key)
                del GISA_STAMINA[key]
                del GISA_FULL_COORDINATE[key]
            DAMAGE_DICT[key] += value
        try:   # 삭제되지 않은 기사에 대해서만 이동 
            GISA_FULL_COORDINATE[key] = list(map(lambda v: [v[0] + dx, v[1] + dy], GISA_FULL_COORDINATE[key]))    
        except:
            continue



#%%


initialize()

for order in KING_ORDER:
    
    make_gisa_board()

    movable_idx_list = []

    if order[0] not in GISA_BEING_ALIVE:
        continue

    gisa_idx = neighbor_detecting(*order)

    if gisa_idx == 'pass':
        continue

    movable = True
    movable_idx_list = [order[0]]

    # 주변에 기사가 있다면?
    if gisa_idx:  
        movable_dict = dict()

        for gi in gisa_idx:
            movable &= judge_movable(gi, order[-1])
            if not movable:
                break
        
        if movable:
            movable_idx_list += list(gisa_idx) 

    # 움직일 수 있다면 실제로 움직이기 시작
    if movable:
        start_actual_move(movable_idx_list, order[-1])

answer = 0
for gba in GISA_BEING_ALIVE:
    answer += DAMAGE_DICT[gba]

print(answer)