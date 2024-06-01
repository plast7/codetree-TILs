import sys
import copy

MAXN = 1005

def mini(a, b):
    return min(a, b)

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    cows = [0] * (MAXN)
    best = [[sys.maxsize] * 2 for _ in range(MAXN)]
    best2 = [[sys.maxsize] * 2 for _ in range(MAXN)]
    
    for i in range(1, N + 1):
        cows[i] = int(data[i])
    
    N += 1
    cows[N] = 0
    
    cows = sorted(cows[:N + 1])
    
    for i in range(1, N + 1):
        if cows[i] == 0:
            best[i][0] = 0
    
    for len in range(1, N):
        ccount = N - len
        
        best2 = [[sys.maxsize] * 2 for _ in range(MAXN)]
        
        for i in range(1, N - len + 1):
            best2[i - 1][0] = mini(best2[i - 1][0], best[i][0] + ccount * (cows[i] - cows[i - 1]))
            best2[i - 1][0] = mini(best2[i - 1][0], best[i][1] + ccount * (cows[i + len - 1] - cows[i - 1]))
            
            best2[i][1] = mini(best2[i][1], best[i][0] + ccount * (cows[i + len] - cows[i]))
            best2[i][1] = mini(best2[i][1], best[i][1] + ccount * (cows[i + len] - cows[i + len - 1]))
        
        best = copy.deepcopy(best2)
    
    best[1][0] = mini(best[1][0], best[1][1])
    print(best[1][0])

if __name__ == "__main__":
    main()