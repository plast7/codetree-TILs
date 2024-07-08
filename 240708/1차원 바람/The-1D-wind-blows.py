n, m, q = map(int, input().split())

matrix = [list(map(int, input().split())) for _ in range(n)]

lane_list = []
direction_list = []

def wind_change(w, direct):
    if direct == 0:
        temp = w[m-1]
        for i in range(m-1, 0, -1):
            w[i] = w[i-1]
        w[0] = temp
    else:
        temp = w[0]
        for i in range(m-1):
            w[i] = w[i+1]
        w[m-1] = temp
    return w

def up_checking_side(l):
    if 0 <= l < n-1:
        for i in range(m):
            if matrix[l][i] == matrix[l+1][i]:
                return True
    return False

def down_checking_side(l):
    if 0 < l <= n-1:
        for i in range(m):
            if matrix[l][i] == matrix[l-1][i]:
                return True
    return False

for _ in range(q):
    lane, direction = input().split()
    lane_list.append(int(lane))
    if direction == "R":
        direction = 0
    else:
        direction = 1
    direction_list.append(direction)

for l, direction in zip(lane_list, direction_list):
    l -= 1
    wind_change(matrix[l], direction)
    count = l - 1
    new_dir = direction +1
    while count >= 0:
        if up_checking_side(count):
            matrix[count] = wind_change(matrix[count], new_dir % 2)
            count -= 1
            new_dir += 1
        else:
            break

    count = l + 1
    new_dir = direction +1
    while count <= n - 1:
        if down_checking_side(count):
            matrix[count] = wind_change(matrix[count], new_dir % 2)
            count += 1
            new_dir +=1
        else:
            break

for p in matrix:
    print(*p)