a=input()
b=input()
arr=list(a)

while True:
    idx=''.join(arr).index(b) # b 가 a 에 포함된 최초의 위치 
    arr=arr[:idx]+arr[idx+len(b):] # slicing 
    if b not in ''.join(arr): #있을 떄까지 반복 
        print(''.join(arr))
        break
    else:
        continue