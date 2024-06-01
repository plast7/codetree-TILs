import sys
input = sys.stdin.read

def main():
    data = input().split()
    N = int(data[0])
    K = int(data[1])
    S = []

    index = 2
    for i in range(N):
        x = int(data[index])
        y = int(data[index + 1])
        S.append((x, y))
        index += 2

    S.sort()

    st = set()
    res = []
    j = 0
    for i in range(len(S)):
        if len(res) >= 2:
            break
        while S[j][0] + K <= S[i][0]:
            st.discard((S[j][1], j))
            j += 1

        ita = itb = st.add((S[i][1], i))
        ita = itb = (S[i][1], i)
        st_sorted = sorted(st)
        ita_index = st_sorted.index(ita)

        if ita_index > 0 and S[i][1] < st_sorted[ita_index - 1][0] + K:
            res.append((i, st_sorted[ita_index - 1][1]))

        if ita_index + 1 < len(st) and st_sorted[ita_index + 1][0] < S[i][1] + K:
            res.append((i, st_sorted[ita_index + 1][1]))

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