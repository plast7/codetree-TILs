# 문자열 a와 b를 입력받아 정규 표현식 패턴에 맞는지 확인하는 프로그램입니다.
a = input()
b = input()

n = len(a)
m = len(b)
is_pos = [[False for _ in range(m + 1)] for _ in range(n + 2)]  # 매칭 가능 여부를 저장하는 배열을 초기화합니다.

# 문자열 a와 b를 비교하여 정규 표현식 패턴에 맞는지 확인합니다.
a = " " + a  # 인덱스 접근을 편리하게 하기 위해 문자열 앞에 공백을 추가합니다.
b = " " + b

is_pos[0][0] = True  # 초기 상태를 참으로 설정합니다.

# is_pos[i][j] :: 문자열 a의 i번째와 표현식 b의 j번째까지가 서로 일치하면 true, 아니면 false
for j in range(m):
    for i in range(n + 1):
        if not is_pos[i][j]:
            continue

        if j != m - 1 and b[j + 2] == '*':
            is_pos[i][j + 2] = True

            for curi in range(i + 1, n + 1):
                if b[j + 1] != '.' and a[curi] != b[j + 1]:
                    break
                is_pos[curi][j + 2] = True
        elif b[j + 1] == '.':
            is_pos[i + 1][j + 1] = True
        else:
            if i != n and a[i + 1] == b[j + 1]:
                is_pos[i + 1][j + 1] = True

# 최종적으로 문자열 'a'와 'b'가 정규 표현식 패턴에 따라 일치하는지 결과를 출력합니다.
print("true" if is_pos[n][m] else "false")