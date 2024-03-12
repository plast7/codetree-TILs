n = int(input())
a = list(map(int, input().split()))
b = []
for i in a:
    if sum(b) <= 200:
        b.append(i)
    else:
        break
print(sum(b))
print("%.1f"%(sum(b) / len(b)))