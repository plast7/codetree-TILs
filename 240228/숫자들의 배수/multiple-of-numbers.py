n = int(input())
i = 1
count = 0

arr = []

while True:
    arr.append(n * i)
    print(n * i)
    i += 1
    if (n * i) % 5 == 0:
        count += 1
        if count == 2:
            break

for elem in arr:
    print(elem, end=' ')