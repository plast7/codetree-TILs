count_arr = [0] * len(arr_to)

for i in range(len(arr_to)):
    if arr_to[i] == 0:
        break
    count_arr.append(arr_to[i]//10)

for elem in count_arr:
    count_arr[elem] += 1

for i in range(1, 10):
    cnt = count_arr[i]
    print(f"{i} - {cnt}")