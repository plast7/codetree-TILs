from collections import defaultdict

n,k,p,t = map(int,input().split())
# p : 처음 병에 걸린 개발자 번호 , t : 악수 횟수

people = [0] * (n+1)
handshake = defaultdict(int)
people[p] = 1
timing = [(input().split()) for _ in range(t)]
timing.sort(key = lambda x : int(x[0]))

for t,x,y in timing:
    t,x,y = int(t),int(x),int(y)
    if people[x] == 1 and handshake[x] < k:
        people[y] = 1
    elif people[y] == 1 and handshake[y] < k:
        people[x] = 1
    handshake[x] += 1
    handshake[y] += 1

print(''.join(str(num) for num in people[1:]))