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
        Iterator<Pair> ita, itb;
        for (int i = 0, j = 0; i < S.size() && res.size() < 2; i++) {
            while (S.get(j).x + K <= S.get(i).x) {
                st.remove(new Pair(S.get(j).y, j));
                j++;
            }

            Pair inserted = new Pair(S.get(i).y, i);
            st.add(inserted);
            ita = st.headSet(inserted, false).descendingIterator();
            itb = st.tailSet(inserted, false).iterator();

            if (ita.hasNext() && S.get(i).y < ita.next().x + K) {
                res.add(new Pair(i, ita.next().y));
            }
            if (itb.hasNext() && itb.next().x < S.get(i).y + K) {
                res.add(new Pair(i, itb.next().y));
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
            if (this.x == other.x) {
                return Integer.compare(this.y, other.y);
            }
            return Integer.compare(this.x, other.x);
        }
    }
}