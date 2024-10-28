# 각 줄의 문자들을 저장하는 배열입니다.
a = ['' for _ in range(5)]

# 4개의 문자열을 입력받습니다.
for i in range(4):
    a[i] = input()

# 각 열에 대해 수행합니다.
for j in range(15):
    # 각 행의 문자를 순서대로 출력합니다.
    for i in range(4):
        # 해당 위치에 문자가 있다면 출력합니다.
        if j < len(a[i]):
            print(a[i][j], end='')