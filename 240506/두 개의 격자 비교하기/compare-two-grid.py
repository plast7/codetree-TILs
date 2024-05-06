inp = input()
arr = inp.split()
n = int(arr[0])
m = int(arr[1])

arr_con = [[1 for _ in range(n)] for k in range(m)]

arr_1 = [list(map(int, input().split())) for k in range(m)]
arr_2 = [list(map(int, input().split())) for k in range(m)]

for i in range(n):
    for j in range(m):
        if arr_1[i][j] == arr_2[i][j]:
            arr_con[i][j] = 0

for h in range(n):
    for v in range(m):
        print(arr_con[h][v],end=" ")
    print()