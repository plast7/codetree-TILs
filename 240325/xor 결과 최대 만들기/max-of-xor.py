max_ret = 0

def digitToNum(digit) :
    k = 1
    ret = 0
    for i in digit[::-1] :
        ret += k * int(i)
        k = k * 2
    return ret 



def calculateXOR(nums) :
    #최대 길이 찾기
    maxLength = 0
    for num in nums :
        if len(num) > maxLength :
            maxLength = len(num)
    
    #0으로 채우기
    for i in range(len(nums)) : 
        zeroCount = maxLength - len(nums[i])
        front = zeroCount * '0'
        nums[i] = front + nums[i]
    
    #xor 연산시작
    visited = ['0'] * maxLength
    newNums = []
    tmp = ""

    for i in range(len(nums[0])) :
        if nums[0][i] != nums[1][i] :
            tmp += '1'
        else :
            tmp += '0'
    newNums.append(tmp)
    nums[1] = tmp

    if len(nums) <= 2 :
        return digitToNum(nums[1])

    for i in range(2,len(nums)) :
        tmp = ""
        for j in range(len(nums[i])) :
            if nums[i-1][j] != nums[i][j] :
                tmp += '1'
            else :
                tmp += '0'
        newNums.append(tmp)
        nums[i] = tmp
        
    return digitToNum(newNums[-1])

def transformDigit(num) :
    ret = []
    while num > 0 :
        num, mod = divmod(num,2)
        ret.append(mod)
    reverseRet = ret[::-1]
    return "".join(map(str,reverseRet))

n,m = map(int,input().split())

arr = list(map(int,input().split()))
digit = []

for i in range(n) :
    digit.append(transformDigit(arr[i]))

def combi(data,cnt,idx) :
    global max_ret
    if cnt == m :
        max_ret = max(max_ret, calculateXOR(data))
        return 
    for i in range(idx,n) :
        data.append(digit[i])
        combi(data,cnt+1,idx+1)
        data.pop()

k = []

if m== 1 :
    print(max(arr))
else : 
    combi(k,0,0)
    print(max_ret)