n, m = map(int, input().split())
lst1 = [list(map(int, input().split())) for _ in range(n)]
lst2 = [list(map(int, input().split())) for _ in range(n)]
lst3 = [[0 for _ in range(m)] for _ in range(n)]

for x in range(n):
    for y in range(n):
        if lst1[x][y] == lst2[x][y]:
            lst3[x][y] = 0
        else:
            lst3[x][y] = 1

for lst in lst3:
    for elem in lst:
        print(elem, end=' ')
    print()