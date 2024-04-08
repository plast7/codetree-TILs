from collections import deque
import copy

L, N, Q = map(int, input().split())
lst = [[2 for i in range(L + 2)]]

for i in range(L):
    temp = [2] + list(map(int, input().split())) + [2]
    lst.append(temp)

lst.append([2 for i in range(L + 2)])
knights = [[0 for i in range(L + 2)] for i in range(L + 2)]
health = [0 for i in range(N + 1)]
is_moved = [False for i in range(N + 1)]
command = []

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

for i in range(1, N + 1):
    r, c, h, w, p = map(int, input().split())
    for x in range(r, r + h):
        for y in range(c, c + w):
            knights[x][y] = i
    health[i] = p
original_health = copy.deepcopy(health)
for _ in range(Q):
    i, d = map(int, input().split())
    command.append((i, d))

def possible(i, dir):
    global knights, is_moved

    temp = [arr[:] for arr in knights]
    deq = deque()
    visited = [False for i in range(N + 1)]
    visited[i] = True
    is_moved[i] = True

    for x in range(1, L + 1):
        for y in range(1, L + 1):
            if temp[x][y] == i:
                temp[x][y] = 0
                deq.append((x, y, i))

    while deq:
        x, y, idx = deq.popleft()

        nx = x + dx[dir]
        ny = y + dy[dir]

        if temp[nx][ny] > 0 and visited[temp[nx][ny]] == False:
            visited[temp[nx][ny]] = True
            is_moved[temp[nx][ny]] = True
            value = temp[nx][ny]
            for i in range(1, L + 1):
                for j in range(1, L + 1):
                    if temp[i][j] == value:
                        deq.append((i, j, temp[i][j]))
                        temp[i][j] = 0

        if (nx <= 0 or ny <= 0 or nx > L or ny > L) or lst[nx][ny] == 2:
            return False
        temp[nx][ny] = idx
    knights = temp

    return True

def check_damage(EXCEPT):
    global health

    for i in range(1, L + 1):
        for j in range(1, L + 1):
            if lst[i][j] == 1 and knights[i][j] > 0 and knights[i][j] != EXCEPT and is_moved[knights[i][j]] and health[knights[i][j] > 0]:
                health[knights[i][j]] -= 1

for i, dir in command:
    _ = possible(i, dir)
    if _:
        check_damage(i)
    for k in range(1, N + 1):
        is_moved[k] = False

ans = 0
for i in range(1, N + 1):
    if health[i] > 0:
        ans += original_health[i] - health[i]


print(ans)