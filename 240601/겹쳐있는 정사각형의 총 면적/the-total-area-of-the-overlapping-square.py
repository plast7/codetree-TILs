import sys
input = sys.stdin.read

def main():
    data = input().split()
    
    N = int(data[0])
    K = int(data[1])
    S = [(int(data[2 + 2 * i]), int(data[3 + 2 * i])) for i in range(N)]
    
    S.sort()
    
    st = set()
    res = []
    
    i = j = 0
    
    while i < len(S) and len(res) < 2:
        while j < len(S) and S[j][0] + K <= S[i][0]:
            st.discard((S[j][1], j))
            j += 1
        
        ita = itb = st.add((S[i][1], i))
        
        if ita is not None and ita != min(st):
            ita = sorted(st).index((S[i][1], i)) - 1
            if S[i][1] < list(st)[ita][0] + K:
                res.append((i, list(st)[ita][1]))
        
        if itb is not None and itb != max(st):
            itb = sorted(st).index((S[i][1], i)) + 1
            if itb < len(st) and list(st)[itb][0] < S[i][1] + K:
                res.append((i, list(st)[itb][1]))
        
        i += 1
    
    result = 0
    if len(res) > 1:
        result = -1
    elif len(res) == 1:
        dx = abs(S[res[0][0]][0] - S[res[0][1]][0])
        dy = abs(S[res[0][0]][1] - S[res[0][1]][1])
        result = (K - dx) * (K - dy)
    
    print(result)

if __name__ == "__main__":
    main()