n = int(input())

for i in range(n + 1):
    for _ in range(2 * n + 1):
        print('*', end=' ')
    print()

    if i < n:
        for _ in range(n + 1):
            print('*  ', end=' ')
        print()