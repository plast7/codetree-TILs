import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int K = sc.nextInt();

        List<int[]> S = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            S.add(new int[]{x, y});
        }
        S.sort((a, b) -> Integer.compare(a[0], b[0]));

        Set<int[]> st = new TreeSet<>(Comparator.comparingInt(a -> a[0]));
        List<int[]> res = new ArrayList<>();
        Iterator<int[]> ita, itb;
        for (int i = 0, j = 0; i < S.size() && res.size() < 2; i++) {
            while (S.get(j)[0] + K <= S.get(i)[0]) {
                st.remove(new int[]{S.get(j)[1], j});
                j++;
            }

            int[] pair = new int[]{S.get(i)[1], i};
            st.add(pair);
            ita = st.tailSet(pair, false).iterator();
            if (ita.hasNext()) {
                int[] prev = ita.next();
                if (S.get(i)[1] < prev[0] + K) {
                    res.add(new int[]{i, prev[1]});
                }
            }
            itb = st.tailSet(pair, true).iterator();
            itb.next();
            if (itb.hasNext()) {
                int[] next = itb.next();
                if (next[0] < S.get(i)[1] + K) {
                    res.add(new int[]{i, next[1]});
                }
            }
        }

        long result = 0;
        if (res.size() > 1) {
            result = -1;
        } else if (res.size() == 1) {
            int dx = S.get(res.get(0)[0])[0] - S.get(res.get(0)[1])[0];
            int dy = S.get(res.get(0)[0])[1] - S.get(res.get(0)[1])[1];
            if (dx < 0) dx = -dx;
            if (dy < 0) dy = -dy;
            result = 1L * (K - dx) * (K - dy);
        }
        System.out.println(result);
    }
}