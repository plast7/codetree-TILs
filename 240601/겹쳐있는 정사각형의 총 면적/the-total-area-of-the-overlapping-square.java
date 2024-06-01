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

        Set<PairWithIndex> st = new TreeSet<>();
        List<PairWithIndex> res = new ArrayList<>();
        Iterator<PairWithIndex> ita, itb;
        for (int i = 0, j = 0; i < S.size() && res.size() < 2; i++) {
            for (; S.get(j).x + K <= S.get(i).x; j++) {
                st.remove(new PairWithIndex(S.get(j).y, j));
            }

            PairWithIndex inserted = new PairWithIndex(S.get(i).y, i);
            st.add(inserted);
            ita = st.headSet(inserted, false).iterator();
            itb = st.tailSet(inserted, false).iterator();

            if (ita.hasNext() && S.get(i).y < ita.next().y + K) {
                res.add(new PairWithIndex(i, ita.next().index));
            }
            if (itb.hasNext() && itb.next().y < S.get(i).y + K) {
                res.add(new PairWithIndex(i, itb.next().index));
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
}

class Pair implements Comparable<Pair> {
    int x, y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Pair other) {
        if (this.x != other.x) {
            return Integer.compare(this.x, other.x);
        }
        return Integer.compare(this.y, other.y);
    }
}

class PairWithIndex implements Comparable<PairWithIndex> {
    int y, index;

    public PairWithIndex(int y, int index) {
        this.y = y;
        this.index = index;
    }

    @Override
    public int compareTo(PairWithIndex other) {
        if (this.y != other.y) {
            return Integer.compare(this.y, other.y);
        }
        return Integer.compare(this.index, other.index);
    }
}