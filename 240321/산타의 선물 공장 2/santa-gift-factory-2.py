class Node:
    def __init__(self, id):
        self.id = id
        self.prev = None
        self.next = None

n, m = -1, -1
MAX_N = 100001
MAX_M = 100001

# 벨트의 앞, 뒤 관리
heads = [0] * MAX_N
tails = [0] * MAX_N
box_cnt = [0] * MAX_N

nodes = [None] * MAX_M # arr로 id번호 가진 Node에 접근 (해시)

def connect(s, e):
    if s is not None :
        s.next = e
    if e is not None :
        e.prev = s

def push_back(b_num, singleton):
    # b_num번 벨트에 new_node를 삽입합니다.
    if heads[b_num] == 0 : # 비어있다면
        # 헤드, 테일 업데이트
        heads[b_num] = tails[b_num] = singleton.id
        box_cnt[b_num] = 1

    else : # 이미 선물 존재 시
        # 이미 존재하면, 앞 뒤 정보 업데이트
        connect(nodes[tails[b_num]], singleton)
        tails[b_num] = singleton.id
        box_cnt[b_num] += 1

def install(param):
    global n, m
    # 공장 설립 : n개 벨트 설치, 총 m개의 선물 준비
    n, m = param[:2]

    # m개의 선물을 초기화
    for id in range(1, m+1):
        nodes[id] = Node(id)

    for id, b_num in enumerate(param[2:], start=1): # m개의 선물 - 주어진 벨트에 올린다.
        # b_num인 벨트에 id번 선물을 배치 합니다.
        push_back(b_num, nodes[id])

    # 출력할 것은 없음.

def move_all(m_src, m_dst):
    if box_cnt[m_src] :
        # m_src의 선물들을 '모두' m_dst로 앞에 위치.
        # m_dst의 head와 m_src의 tail을 이어줘야 함.
        s = nodes[tails[m_src]]
        e = nodes[heads[m_dst]]
        connect(s, e)

        # m_dst.head는 m_src.head로 갱신
        heads[m_dst] = heads[m_src]
        # 옮긴 후 m_src 벨트는 초기화
        heads[m_src] = tails[m_src] = 0
        box_cnt[m_dst] += box_cnt[m_src]
        box_cnt[m_src] = 0

    else :
        return


def get_total(m_dst):
    # m_dst번 벨트의 선물들의 수를 출력합니다.
    print(box_cnt[m_dst])

def replace_front(m_src, m_dst):
    # 둘 중 하나의 벨트에 존재하지 않으면
    if heads[m_src] == 0 and heads[m_dst] == 0 :
        return
    elif heads[m_src] and heads[m_dst] : # 둘다 존재하면
        # m_src의 head를 m_dst의 head와 '교체'를 위해 저장
        src_head = nodes[heads[m_src]]
        dst_head = nodes[heads[m_dst]]

        src_target = dst_head.next
        dst_target = src_head.next

        # 각각 next로 부터 끊어내고, 연결 해야함
        connect(src_head, src_target)
        connect(dst_head, dst_target)

        heads[m_src] = dst_head.id
        heads[m_dst] = src_head.id

    elif heads[m_src] : # m_src에 존재하면 (m_dst는 없음)
        # m_src의 head를 m_dst로 옮김
        node = nodes[heads[m_src]]
        heads[m_dst] = tails[m_dst] = node.id

        # m_src의 heads를 갱신
        if node.next is not None :
            heads[m_src] = node.next.id
            node.next = None
        box_cnt[m_src] -= 1
        box_cnt[m_dst] += 1

    elif heads[m_dst] :
        # m_src로 옮김
        # print(heads[m_dst])
        node = nodes[heads[m_dst]]
        heads[m_src] = tails[m_src] = node.id

        # m_dst의 heads 갱신
        # 1개만 있을 때에는 none이 될텐데
        if node.next is not None :
            heads[m_dst] = node.next.id
            node.next = None
        box_cnt[m_dst] -= 1
        box_cnt[m_src] += 1



def divide(m_src, m_dst):
    if box_cnt[m_src] > 1 :
        # m_src의 벨트의 선물 개수 n일 떄, n//2까지 있는 선물은 m_dst 앞으로 옮김
        target = box_cnt[m_src]//2
        # print("target", target)

        # m_src벨트의 '가장 앞에서 n//2 번쨰까지의' 선물들
        cnt = 0
        cur = nodes[heads[m_src]]
        dst_start = nodes[heads[m_src]].id
        while cnt < target-1 and cur.next :
            cnt += 1
            cur = cur.next

        # loop를 돌고 나면, n//2 다음(포함되지 않음)의 위치로 이동

        # m_dst의 벨트 앞으로 옮김
        # print("cnt", cnt)
        s = cur.prev # n//2번쨰 노드
        e = nodes[heads[m_dst]]

        connect(s, e)
        # m_src의 head 갱신
        heads[m_src] = cur.id
        box_cnt[m_src] -= cnt

        # m_dst 정보 갱신
        heads[m_dst] = dst_start
        box_cnt[m_dst] += cnt

    else : # 1개인 경우, 옮기지 않음.
        return


def get_gift_info(p_num):
    # p_num의 앞번호 a, 뒷번호 b
    a = nodes[p_num].prev.id if nodes[p_num].prev else -1
    b = nodes[p_num].next.id if nodes[p_num].next else -1
    print(a + 2*b)


def get_belt_info(b_num):
    # b_num의 벨트의 맨 앞 번호 a, 맨 뒤 번호 b, 개수 c
    if box_cnt[b_num] : # 0이 아니면
        a = heads[b_num]
        b = tails[b_num]
        c = box_cnt[b_num]
    else :
        a, b, c = -1, -1, 0

    print(a + 2*b + 3*c)


# Query 진행
q = int(input())


def print_belt():
    # for Test
    for i in range(1, n + 1):
        cur = nodes[heads[i]]
        if heads[i] != 0:
            while cur:
                print(cur.id, end=" ")
                cur = cur.next
            print()
        else:
            print("Empty")
    print("----")


for _ in range(q):
    cmd, *param = map(int, input().split())

    if cmd == 100 :
        install(param)
    if cmd == 200 :
        m_src, m_dst = param
        move_all(m_src, m_dst)
        get_total(m_dst)
    if cmd == 300 :
        m_src, m_dst = param
        replace_front(m_src, m_dst)
        get_total(m_dst)
    if cmd == 400 :
        m_src, m_dst = param
        divide(m_src, m_dst)
        get_total(m_dst)
    if cmd == 500 :
        p_num = param[0]
        get_gift_info(p_num)
    if cmd == 600 :
        b_num = param[0]
        get_belt_info(b_num)

    # print("box_cnt", box_cnt[12466])
    # print_belt()