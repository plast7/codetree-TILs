n = int(input())
i = 1
count = 0

arr = []

while True:
    arr.append(n * i)
    print(n * i)
    if (n * i) % 5 == 0:
        count += 1
        print(i, count)
        if count == 2:
            arr.append(n * i)
            break
    i += 1

for elem in arr:
    print(elem, end=' ')