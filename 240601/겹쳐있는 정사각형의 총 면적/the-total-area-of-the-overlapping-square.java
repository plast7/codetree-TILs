import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int K = sc.nextInt();

        List<Pair> S = new ArrayList<>();
        for(int i = 0; i < N; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            S.add(new Pair(x, y));
        }
        Collections.sort(S);

        TreeSet<PairWithIndex> st = new TreeSet<>();
        List<Pair> res = new ArrayList<>();
        Iterator<PairWithIndex> ita, itb;
        for(int i = 0, j = 0; i < S.size() && res.size() < 2; i++) {
            for(; S.get(j).x + K <= S.get(i).x; j++) {
                st.remove(new PairWithIndex(S.get(j).y, j));
            }

            PairWithIndex inserted = new PairWithIndex(S.get(i).y, i);
            st.add(inserted);
            ita = st.headSet(inserted, false).isEmpty() ? null : st.headSet(inserted, false).iterator();
            itb = st.tailSet(inserted, false).isEmpty() ? null : st.tailSet(inserted, false).iterator();

            if (ita != null && ita.hasNext()) {
                PairWithIndex itaPair = ita.next();
                if (S.get(i).y < itaPair.value + K) {
                    res.add(new Pair(i, itaPair.index));
                }
            }
            if (itb != null && itb.hasNext()) {
                PairWithIndex itbPair = itb.next();
                if (itbPair.value < S.get(i).y + K) {
                    res.add(new Pair(i, itbPair.index));
                }
            }
        }

        long result = 0;
        if (res.size() > 1) {
            result = -1;
        } else if (res.size() == 1) {
            int dx = Math.abs(S.get(res.get(0).x).x - S.get(res.get(0).y).x);
            int dy = Math.abs(S.get(res.get(0).x).y - S.get(res.get(0).y).y);
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
        public int compareTo(Pair o) {
            if (this.x != o.x) {
                return Integer.compare(this.x, o.x);
            } else {
                return Integer.compare(this.y, o.y);
            }
        }
    }

    static class PairWithIndex implements Comparable<PairWithIndex> {
        int value, index;
        PairWithIndex(int value, int index) {
            this.value = value;
            this.index = index;
        }

        @Override
        public int compareTo(PairWithIndex o) {
            if (this.value != o.value) {
                return Integer.compare(this.value, o.value);
            } else {
                return Integer.compare(this.index, o.index);
            }
        }
    }
}