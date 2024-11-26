n, t = map(int,input().split())
grid = [list(map(int,input().split())) for _ in range(3)]
flat_list = sum(grid,[])
shifted = flat_list[-t:] + flat_list[:-t]
nested_list = [shifted[i:i+n] for i in range(0,len(shifted),n)]
for row in nested_list:
    print(" ".join(map(str,row)))
