def gravity(arr, y, x, dir):
    ny = y
    while True:
        ny += dir
        if ny < 0 or ny >= len(arr):
            return -1
        if arr[ny][x] == 1:
            return ny - dir
        if arr[ny][x] == 3:
            return ny
        
def bfs(arr, y, x):
    queue = []
    visited = []
    gravity_list = []
    gravity_dir = 1
    gravity_cnt = 0
    
    y = gravity(arr, y, x, gravity_dir)
    if y == -1:
        return -1
    
    queue.append((y, x))
    gravity_list.append((gravity_dir, gravity_cnt))
    visited.append((y, x))
    while queue:
        y, x = queue.pop(0)
        gravity_dir, gravity_cnt = gravity_list.pop(0)
        for dy, dx in [[0, 1], [0, -1], [0, 0]]:
            ny = y + dy
            nx = x + dx
            gravity_change = gravity_cnt
            if dy == 0 and dx == 0:
                gravity_dir *= -1
                gravity_change = gravity_cnt + 1
                
            elif nx < 0 or nx >= len(arr[0]):
                continue
            
            if arr[ny][nx] == 1:
                continue
            
            ny = gravity(arr, ny, nx, gravity_dir)            
            if ny == -1:
                continue
            if (ny, nx) in visited:
                continue
            
            if arr[ny][nx] == 3:
                return gravity_change
            
            queue.append((ny, nx))
            gravity_list.append((gravity_dir, gravity_change))
            visited.append((ny, nx))
            
    return -1

def main():
    n, m = map(int, input().split())
    arr = []
    for _ in range(n):
        temp = list(input())
        for i in range(len(temp)):
            if temp[i] == '#':
                temp[i] = 1
            elif temp[i] == '.':
                temp[i] = 0
            elif temp[i] == 'C':
                temp[i] = 2
            else:
                temp[i] = 3
        arr.append(temp)
    
    # print(gravity(arr, 1, 1, -1))
    
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            if arr[i][j] == 2:
                print(bfs(arr, i, j))
    
    # for a in arr:
    #     print(a)
        
if __name__ == "__main__":
    main()