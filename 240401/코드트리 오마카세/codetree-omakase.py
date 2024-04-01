from collections import defaultdict

L, Q = list(map(int, input().split()))
sushi = defaultdict(lambda :defaultdict(int)) #
customers = {} #name, seat, time, lect
# sushi["a"][0] =1
# print(sushi)

customer_num = 0
sushi_total = 0

for _ in range(Q):
    order = list(map(str, input().split()))
    if order[0] == "100":
        t, x, name = int(order[1]), int(order[2]), order[3]
        # sushi[(x-t%L)%L][name] += 1
        sushi[name][(x-t%L)%L] += 1
        sushi_total += 1
    elif order[0] == "200":
        t, x, name, n = int(order[1]), int(order[2]), order[3], int(order[4])
        if n == 0:
            n = -1
        customers[name] = ((x-t%L)%L, t, n) # seat, time, left
        customer_num += 1
    else:
        t = int(order[1])
        # print("customers",customers)
        # print("sushi total",sushi_total)
        if customer_num == 0:
            print(customer_num, sushi_total)
        else:
            out_customer = []
            for name in customers:
                c_seat, time, left = customers[name]
                # 스시 리스트 돌아보자
                out_sushi = []
                for s_seat in sushi[name]:
                    # diff = (s_seat-c_seat)%L
                    diff = (c_seat-s_seat)%L
                    if diff<=t-time:
                        can_eat = sushi[name][s_seat]
                        if can_eat>0:
                            left -= can_eat
                            sushi_total -= can_eat
                            # sushi[name][sushi] = 0
                            out_sushi.append(s_seat)
                for s in out_sushi:
                    sushi[name].pop(s)
                # 다 돌았는데 0이면 떠난다
                if left == 0:
                    customer_num -= 1
                    out_customer.append(name)
                else:
                    customers[name] = ((c_seat-(t-time)%L)%L, t, left)
                    # print("??",customers[name])
            for n in out_customer:
                customers.pop(n)
            print(customer_num, sushi_total)
    # print("sushi:",sushi)

    # print(sushi)