class presents:
    def __init__(self, price, tax):
        self.price = price
        self.tax = tax

def half_price(arr):
    max_price = 0
    for i in range(len(arr)):
        temp_max = arr[i]
        max_price = max(max_price, temp_max)
    
    return sum(arr)-max_price//2

n, b = map(int, input().split())
price_list = []

for _ in range(n):
    price, tax = map(int, input().split())
    price_list.append(presents(price, tax))

price_list.sort(key=lambda x: (x.price + x.tax, x.price, x.tax))

ans = 0

for i in range(n):
    for j in range(n):
        if i==j:continue

        temp_price = []
        temp_tax = []
        for k in range(i, j+1):
            temp_price.append(price_list[k].price)
            temp_tax.append(price_list[k].tax)
        total_price = half_price(temp_price)
        total_tax = sum(temp_tax)

        if total_price+total_tax <= b:
            cnt = len(temp_price)
        else:
            cnt = ans
        ans = max(ans, cnt)

print(ans)