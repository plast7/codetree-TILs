from collections import defaultdict

L, Q = list(map(int, input().split()))
sushi = defaultdict(lambda :defaultdict(int)) #
customers = {} #name, seat, time, lect
# sushi["a"][0] =1
# print(sushi)
check_list = set()
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

        if name not in check_list:
            check_list.add(name)
            if n>0:
                customers[name] = ((x-t)%L, t, n) # seat, time, left
            customer_num += 1
    else:
        t = int(order[1])
        # print("customers",customers)
        # print("sushi total",sushi_total)
        if customer_num == 0 or sushi_total == 0:
            print(customer_num, sushi_total)
        else:
            out_customer = []
            for name in customers:
                c_seat, time, left = customers[name]
                if left == 0:
                    continue
                # 스시 리스트 돌아보자
                out_sushi = []
                for s_seat in sushi[name]:
                    if left == 0:
                        break
                    # diff = (s_seat-c_seat)%L
                    diff = (c_seat-s_seat)%L
                    if diff <= t-time and sushi[name][s_seat]>0:
                        can_eat = sushi[name][s_seat]
                        if left >= can_eat:
                            left -= can_eat
                            sushi_total -= can_eat
                            out_sushi.append(s_seat)
                        else:
                            will_eat = can_eat-left
                            left = 0
                            sushi_total -= will_eat

                for s in out_sushi:
                    sushi[name].pop(s)
                # 다 돌았는데 0이면 떠난다
                if left == 0:
                    customer_num -= 1
                    out_customer.append(name)
                else:
                    customers[name] = ((c_seat-(t-time))%L, t, left)
                    # print("??",customers[name])
            for n in out_customer:
                customers.pop(n)
                sushi.pop(n)
            print(customer_num, sushi_total)
    # print("sushi:",sushi)