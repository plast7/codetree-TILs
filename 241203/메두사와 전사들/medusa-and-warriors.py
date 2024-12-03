from collections import deque

direction_4 = ((-1, 0), (1, 0), (0, -1), (0, 1))  # 상하좌우
direction_8 = ((-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1))  # 0상 1하 2좌 3우 4상좌 5상우 6하좌 7하우


def oob(y, x):
    return y < 0 or N <= y or x < 0 or N <= x


def find_m_route():
    visited = [[0] * N for _ in range(N)]
    visited[my][mx] = 1
    queue = deque()
    queue.append((my, mx, []))
    while queue:
        y, x, route = queue.popleft()
        for dy, dx in direction_4:
            ny, nx = y + dy, x + dx
            if oob(ny, nx) or visited[ny][nx] or area[ny][nx]:
                continue
            if (ny, nx) == (ey, ex):
                return route
            visited[ny][nx] = 1
            queue.append((ny, nx, route + [(ny, nx)]))
    return None


def get_shadow_indexes(init_y, init_x, middle_d, start_d, end_d):  # 0상 1하 2좌 3우 4상좌 5상우 6하좌 7하우
    indexes = set()

    dy, dx = direction_8[middle_d]
    sdy, sdx = direction_8[start_d]
    edy, edx = direction_8[end_d]
    y, x = init_y + dy, init_x + dx
    sy, sx = init_y + sdy, init_x + sdx
    ey, ex = init_y + edy, init_x + edx
    while not oob(y, x):
        if dx == 0:
            for xx in range(max(0, sx), min(N, ex + 1)):
                indexes.add((y, xx))
        else:
            for yy in range(max(0, sy), min(N, ey + 1)):
                indexes.add((yy, x))

        y, x = y + dy, x + dx
        sy, sx = sy + sdy, sx + sdx
        ey, ex = ey + edy, ex + edx
    return indexes


def get_m_sight():
    global rock_cnt

    candidates = []
    for middle_d, start_d, end_d in ((0, 4, 5), (1, 6, 7), (2, 4, 6), (3, 5, 7)):  # 0상 1하 2좌 3우 4상좌 5상우 6하좌 7하우
        sight = set()
        stun_cnt = 0
        stun_indexes = []
        shadow = set()

        dy, dx = direction_8[middle_d]
        sdy, sdx = direction_8[start_d]
        edy, edx = direction_8[end_d]
        y, x = my + dy, mx + dx
        sy, sx = my + sdy, mx + sdx
        ey, ex = my + edy, mx + edx
        while not oob(y, x):
            if dx == 0:
                for xx in range(max(0, sx), min(N, ex + 1)):
                    if (y, xx) in shadow:
                        continue
                    sight.add((y, xx))
                    if warriors_area[y][xx]:
                        stun_cnt += warriors_area[y][xx]
                        stun_indexes.append((y, xx))
                        if xx == x:
                            shadow_indexes = get_shadow_indexes(y, xx, middle_d, middle_d, middle_d)
                        elif xx < x:
                            shadow_indexes = get_shadow_indexes(y, xx, middle_d, start_d, middle_d)
                        else:
                            shadow_indexes = get_shadow_indexes(y, xx, middle_d, middle_d, end_d)
                        shadow.update(shadow_indexes)
            else:
                for yy in range(max(0, sy), min(N, ey + 1)):
                    if (yy, x) in shadow:
                        continue
                    sight.add((yy, x))
                    if warriors_area[yy][x]:
                        stun_cnt += warriors_area[yy][x]
                        stun_indexes.append((yy, x))
                        if yy == y:
                            shadow_indexes = get_shadow_indexes(yy, x, middle_d, middle_d, middle_d)
                        elif yy < y:
                            shadow_indexes = get_shadow_indexes(yy, x, middle_d, start_d, middle_d)
                        else:
                            shadow_indexes = get_shadow_indexes(yy, x, middle_d, middle_d, end_d)
                        shadow.update(shadow_indexes)
            y, x = y + dy, x + dx
            sy, sx = sy + sdy, sx + sdx
            ey, ex = ey + edy, ex + edx

        candidates.append((-stun_cnt, middle_d, sight, stun_indexes))

    minus_stun_cnt, _, sights, stun_indexes = min(candidates)
    rock_cnt -= minus_stun_cnt
    return sights, stun_indexes


def warriors_move_and_attack():
    global warriors_area, total_move_cnt, attack_cnt

    next_warriors_area = [[0] * N for _ in range(N)]
    for sy in range(N):
        for sx in range(N):
            if warriors_area[sy][sx]:
                if (sy, sx) in stunned_warriors:
                    next_warriors_area[sy][sx] += warriors_area[sy][sx]
                    continue

                first_candidates = []
                for d_idx, (dy, dx) in enumerate(direction_4):
                    ny, nx = sy + dy, sx + dx
                    if oob(ny, nx) or (ny, nx) in m_sight or abs(my - sy) + abs(mx - sx) <= abs(my - ny) + abs(mx - nx):
                        continue
                    first_candidates.append((d_idx, ny, nx))
                if not first_candidates:
                    next_warriors_area[sy][sx] += warriors_area[sy][sx]
                    continue
                _, fy, fx = min(first_candidates)
                total_move_cnt += warriors_area[sy][sx]
                if (fy, fx) == (my, mx):
                    attack_cnt += warriors_area[sy][sx]
                    continue

                second_candidates = []
                for d_idx, (dy, dx) in enumerate(direction_4):
                    ny, nx = fy + dy, fx + dx
                    if oob(ny, nx) or (ny, nx) in m_sight or abs(my - fy) + abs(mx - fx) <= abs(my - ny) + abs(mx - nx):
                        continue
                    if d_idx <= 1:
                        second_candidates.append((d_idx + 4, ny, nx))
                    else:
                        second_candidates.append((d_idx, ny, nx))
                if not second_candidates:
                    next_warriors_area[fy][fx] += warriors_area[sy][sx]
                    continue
                _, ly, lx = min(second_candidates)
                total_move_cnt += warriors_area[sy][sx]
                if (ly, lx) == (my, mx):
                    attack_cnt += warriors_area[sy][sx]
                    continue
                next_warriors_area[ly][lx] += warriors_area[sy][sx]

    warriors_area = next_warriors_area


N, M = map(int, input().split())
my, mx, ey, ex = map(int, input().split())
warriors_input = list(map(int, input().split()))
warriors_area = [[0 for _ in range(N)] for _ in range(N)]
for i in range(M):
    wi, wj = warriors_input[i * 2: i * 2 + 2]
    warriors_area[wi][wj] += 1
area = [list(map(int, input().split())) for _ in range(N)]

m_route = find_m_route()
if not m_route:
    print(-1)
else:
    for my, mx in m_route:
        total_move_cnt, rock_cnt, attack_cnt = 0, 0, 0
        warriors_area[my][mx] = 0
        m_sight, stunned_warriors = get_m_sight()
        warriors_move_and_attack()
        print(total_move_cnt, rock_cnt, attack_cnt)
    print(0)
