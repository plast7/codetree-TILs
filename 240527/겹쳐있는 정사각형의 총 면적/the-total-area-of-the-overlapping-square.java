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
        List<PairWithIndex> res = new ArrayList<>();
        Iterator<PairWithIndex> ita, itb;
        for(int i = 0, j = 0; i < S.size() && res.size() < 2; i++) {
            while (S.get(j).x + K <= S.get(i).x) {
                st.remove(new PairWithIndex(S.get(j).y, j));
                j++;
            }

            ita = itb = st.add(new PairWithIndex(S.get(i).y, i)) ? st.headSet(new PairWithIndex(S.get(i).y, i), true).descendingIterator() : null;
            if(ita != null && ita.hasNext() && S.get(i).y < ita.next().first + K) {
                res.add(new PairWithIndex(i, st.headSet(new PairWithIndex(S.get(i).y, i), false).descendingIterator().next().second));
            }
            if(itb != null && itb.hasNext() && itb.next().first < S.get(i).y + K) {
                res.add(new PairWithIndex(i, itb.next().second));
            }
        }

        long result = 0;
        if(res.size() > 1) {
            result = -1;
        } else if(res.size() == 1) {
            int dx = S.get(res.get(0).first).x - S.get(res.get(0).second).x;
            int dy = S.get(res.get(0).first).y - S.get(res.get(0).second).y;
            if(dx < 0) dx = -dx;
            if(dy < 0) dy = -dy;
            result = 1L * (K - dx) * (K - dy);
        }
        System.out.println(result);
    }
}

// Custom pair class to hold x and y coordinates
class Pair implements Comparable<Pair> {
    int x, y;

    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Pair o) {
        if (this.x != o.x) return Integer.compare(this.x, o.x);
        return Integer.compare(this.y, o.y);
    }
}

// Custom pair class with index for TreeSet
class PairWithIndex implements Comparable<PairWithIndex> {
    int first, second;

    PairWithIndex(int first, int second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public int compareTo(PairWithIndex o) {
        if (this.first != o.first) return Integer.compare(this.first, o.first);
        return Integer.compare(this.second, o.second);
    }
}