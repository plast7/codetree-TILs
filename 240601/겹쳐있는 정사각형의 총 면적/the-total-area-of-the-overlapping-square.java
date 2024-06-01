import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int K = sc.nextInt();

        List<Pair<Integer, Integer>> S = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            S.add(new Pair<>(x, y));
        }
        S.sort(Comparator.comparing(Pair::getKey));

        TreeSet<Pair<Integer, Integer>> st = new TreeSet<>(Comparator.comparing(Pair::getKey).thenComparing(Pair::getValue));
        List<Pair<Integer, Integer>> res = new ArrayList<>();
        Iterator<Pair<Integer, Integer>> ita, itb;

        for (int i = 0, j = 0; i < S.size() && res.size() < 2; i++) {
            for (; S.get(j).getKey() + K <= S.get(i).getKey(); j++) {
                st.remove(new Pair<>(S.get(j).getValue(), j));
            }

            Pair<Integer, Integer> insertedPair = new Pair<>(S.get(i).getValue(), i);
            ita = st.headSet(insertedPair, true).descendingIterator();
            itb = st.tailSet(insertedPair, false).iterator();

            st.add(insertedPair);

            if (ita.hasNext() && S.get(i).getValue() < ita.next().getKey() + K) {
                res.add(new Pair<>(i, ita.next().getValue()));
            }
            if (itb.hasNext() && itb.next().getKey() < S.get(i).getValue() + K) {
                res.add(new Pair<>(i, itb.next().getValue()));
            }
        }

        long result = 0;
        if (res.size() > 1) {
            result = -1;
        } else if (res.size() == 1) {
            int dx = S.get(res.get(0).getKey()).getKey() - S.get(res.get(0).getValue()).getKey();
            int dy = S.get(res.get(0).getKey()).getValue() - S.get(res.get(0).getValue()).getValue();
            if (dx < 0) dx = -dx;
            if (dy < 0) dy = -dy;
            result = 1L * (K - dx) * (K - dy);
        }
        
        System.out.println(result);
        sc.close();
    }
}

class Pair<K, V> {
    private K key;
    private V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }
}