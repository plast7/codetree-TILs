import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int K = sc.nextInt();

        List<Pair> S = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            S.add(new Pair(x, y));
        }
        Collections.sort(S);

        TreeSet<Pair> st = new TreeSet<>();
        List<Pair> res = new ArrayList<>();
        
        for (int i = 0, j = 0; i < S.size() && res.size() < 2; i++) {
            while (S.get(j).x + K <= S.get(i).x) {
                st.remove(new Pair(S.get(j).y, j));
                j++;
            }

            Pair ita = st.floor(new Pair(S.get(i).y, i));
            Pair itb = st.ceiling(new Pair(S.get(i).y, i));

            st.add(new Pair(S.get(i).y, i));

            if (ita != null && ita.y != i && S.get(i).y < ita.x + K) {
                res.add(new Pair(i, ita.y));
            }
            if (itb != null && itb.y != i && itb.x < S.get(i).y + K) {
                res.add(new Pair(i, itb.y));
            }
        }

        long result = 0;
        if (res.size() > 1) {
            result = -1;
        } else if (res.size() == 1) {
            int dx = S.get(res.get(0).x).x - S.get(res.get(0).y).x;
            int dy = S.get(res.get(0).x).y - S.get(res.get(0).y).y;
            if (dx < 0) dx = -dx;
            if (dy < 0) dy = -dy;
            result = 1L * (K - dx) * (K - dy);
        }
        System.out.println(result);
    }

    static class Pair implements Comparable<Pair> {
        int x, y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pair other) {
            if (this.x != other.x) {
                return this.x - other.x;
            } else {
                return this.y - other.y;
            }
        }
    }
}