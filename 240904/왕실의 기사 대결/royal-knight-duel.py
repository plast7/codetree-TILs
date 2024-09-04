import copy
#체스판 규격, 기사 수, 명령 수
L, N, Q = map(int, input().split())
#0-빈칸, 1-함정, 2-벽, 체스판 밖도 벽으로 간주
arr = [[2]*(L+2)]+[[2]+list(map(int, input().split()))+[2] for _ in range(L)] +[[2]*(L+2)]
#벽
w_set = set()
for i in range(L+2):
    for j in range(L+2):
        if arr[i][j]==2:
            w_set.add((i,j))
#함정
h_set = set()
for i in range(L+2):
    for j in range(L+2):
        if arr[i][j]==1:
            h_set.add((i,j))

k_dict = {}
# (r,c,h,w,k, 누적 받은 데미지, 해당 좌표, 사라짐 여부)
for n in range(1,N+1):
    k_dict[n]= list(map(int, input().split()))+[0]+[set()]+[0]
    for i in range(k_dict[n][2]):
        for j in range(k_dict[n][3]):
            k_dict[n][6].add((k_dict[n][0]+i,k_dict[n][1]+j))

k_dict_c = copy.deepcopy(k_dict)
# (i번 기사, 방향 d로 1칸 이동), 사라진 기사 번호 주어질 수 있음, d - 상 우 하 좌 0 1 2 3
q_arr = [list(map(int, input().split())) for _ in range(Q)]
#ans: Q번의 대결이 끝난 후 '생존한' 기사들이 총 받은 데미지의 합
di = [-1,0,1,0]
dj = [0,1,0,-1]
#기사 인덱스와 방향을 인풋으로 받고 아웃풋으로 이동하는 기사 인덱스를 뱉음
def move(idx, d):

    idx_list.add(idx)

    nr, nc = k_dict[idx][0]+di[d], k_dict[idx][1]+dj[d]
    c_k = set()
    for i in range(k_dict[idx][2]):
        for j in range(k_dict[idx][3]):
            c_k.add((nr+i,nc+j))
    # 벽 판단
    #벽 0, flag=True면 벽, 이동 X
    if len(c_k & w_set) > 0:
        #move_flag=True
        idx_list.clear()
        return
    #벽 X
        # 움직이는 좌표에 다른 기사가 있는지, 있다면 누군지 파악
    else:
        otherk_flag=False
        overlap_idx = set()
        for idx2 in k_dict:
            if k_dict[idx2][7] == 0 and idx2 != idx:
                if idx2 not in idx_list:
                    if len(c_k & k_dict[idx2][6])>0:
                        otherk_flag=True
                        overlap_idx.add(idx2)
        # 다른 기사 X -> 이동
        if otherk_flag==False:
            #idx_list.add(idx)
            return
        #다른 기사 O
        else:
            for i in overlap_idx:
                #breakpoint()
                #idx_list.add(i)
                move(i, d)
    #return

for q in range(Q):
    #기사, 이동방향 확인
    nm,dr = q_arr[q][0], q_arr[q][1]
    idx_list=set()
    #flag=False
    # 기사 이동 - 기사와, 밀려나는 기사 좌표 업데이트, 사라진 기사에게 명령 내리면 반응 없음
    if k_dict[nm][7] == 0:

        move(nm,dr)
    else:
        continue

    #이동 좌표, 영역 좌표 업데이트
    if len(idx_list)>0:
        for idx in idx_list:
            if k_dict[idx][7] == 0:
                k_dict[idx][0], k_dict[idx][1] =  k_dict[idx][0] + di[dr], k_dict[idx][1] + dj[dr]
                k_dict[idx][6] = set()
                for i in range(k_dict[idx][2]):
                    for j in range(k_dict[idx][3]):
                        k_dict[idx][6].add((k_dict[idx][0] + i, k_dict[idx][1] + j))
    #nr, nc = k_dict[i][0]+di[d], k_dict[i][1]+dj[d]

    # 대결 - 밀려나는 기사 피해 계산. 밀려난 곳에서 범위 안에 놓여 있는 함정의 수만큼 피해 입음, 체력이 0이 되면 체스판에서 사라짐
    if len(idx_list) > 0:

        for idx in idx_list:
            if idx!=nm and k_dict[idx][7] == 0:
                n_h = len(h_set & k_dict[idx][6])
                if n_h!=0:
                    #받은 데미지 갱신
                    k_dict[idx][5]+=n_h
                    #남은 체력 갱신
                    k_dict[idx][4] -= n_h
                    #사라짐 처리
                    if k_dict[idx][4]<=0:
                        k_dict[idx][7]=1
    # if q==84:
    #    breakpoint()
    ans1 = 0
    for n in range(1, N + 1):
        if k_dict[n][7] == 0:
            ans1 += k_dict[n][5]
    # print(q, ans1)
#breakpoint()
ans=0
for n in range(1,N+1):
    if k_dict[n][7]==0:
        ans+=k_dict[n][5]

print(ans)