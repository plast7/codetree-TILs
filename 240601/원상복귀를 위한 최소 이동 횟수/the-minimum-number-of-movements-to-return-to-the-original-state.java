import java.util.*;

public class Main {
    static class Pt {
        int x, y;
        Pt(int a, int b) { x = a; y = b; }
    }

    static int N;
    static int[] x = new int[100], y = new int[100], indx = new int[100];
    static Set<Pair<Integer, Integer>> points = new HashSet<>(); // keeps track of which (x, y) coordinates are farms
    static List<Pt> nodes = new ArrayList<>();
    static List<Integer>[] adj = new ArrayList[500]; // adjacency list

    static {
        for (int i = 0; i < 500; i++) {
            adj[i] = new ArrayList<>();
        }
    }

    // Returns the taxicab distance between nodes[a] and nodes[b].
    static int length(int a, int b) {
        return Math.abs(nodes.get(a).x - nodes.get(b).x) + Math.abs(nodes.get(a).y - nodes.get(b).y);
    }

    // Returns whether the first point (x1, y1) is on the segment (x2, y2) -> (x3, y3).
    static boolean inSegment(int x1, int y1, int x2, int y2, int x3, int y3) {
        if (x2 == x3)
            return x1 == x2 && y1 > Math.min(y2, y3) && y1 < Math.max(y2, y3);
        else if (y2 == y3)
            return y1 == y2 && x1 > Math.min(x2, x3) && x1 < Math.max(x2, x3);
        else // invalid
            return true;
    }

    // Returns whether a right-angle path from nodes[a] to nodes[b] is possible (does not intersect any of the N original points, except potentially at endpoints).
    static boolean possible(int a, int b) {
        // Method 1: travel vertical first, then horizontal
        boolean good1 = nodes.get(a).x == nodes.get(b).x || nodes.get(a).y == nodes.get(b).y || !points.contains(new Pair<>(nodes.get(a).x, nodes.get(b).y));
        for (int i = 0; i < N; i++)
            if (inSegment(x[i], y[i], nodes.get(a).x, nodes.get(a).y, nodes.get(a).x, nodes.get(b).y) || inSegment(x[i], y[i], nodes.get(a).x, nodes.get(b).y, nodes.get(b).x, nodes.get(b).y)) {
                good1 = false;
                break;
            }
        if (good1)
            return true;

        // Method 2: travel horizontal first, then vertical
        boolean good2 = nodes.get(a).x == nodes.get(b).x || nodes.get(a).y == nodes.get(b).y || !points.contains(new Pair<>(nodes.get(b).x, nodes.get(a).y));
        for (int i = 0; i < N; i++)
            if (inSegment(x[i], y[i], nodes.get(a).x, nodes.get(a).y, nodes.get(b).x, nodes.get(a).y) || inSegment(x[i], y[i], nodes.get(b).x, nodes.get(a).y, nodes.get(b).x, nodes.get(b).y)) {
                good2 = false;
                break;
            }
        if (good2)
            return true;

        return false;
    }

    // Returns the length of the shortest path from nodes[a] to nodes[b].
    static boolean[] vis = new boolean[500];
    static int[] dist = new int[500], infinity = {1023456789};

    static int dijkstra(int a, int b) {
        Arrays.fill(dist, infinity[0]);
        Arrays.fill(vis, false);

        // Don't visit farms (except for the start and end locations).
        for (int i = 0; i < N; i++)
            if (indx[i] != a && indx[i] != b)
                vis[indx[i]] = true;

        dist[a] = 0;
        for (int i = 0; i < nodes.size(); i++) {
            int next = 0;
            for (int j = 0; j < nodes.size(); j++)
                if (!vis[j] && (dist[j] < dist[next] || vis[next]))
                    next = j;
            if (vis[next] || dist[next] == infinity[0])
                return -1;
            if (next == b)
                return dist[next];
            vis[next] = true;
            for (int j : adj[next])
                if (!vis[j])
                    dist[j] = Math.min(dist[j], dist[next] + length(next, j));
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
            points.add(new Pair<>(x[i], y[i]));
        }

        // Make nodes
        for (int i = 0; i < N; i++)
            for (int a = -1; a <= 1; a++)
                for (int b = -1; b <= 1; b++) {
                    if (a == 0 && b == 0) {
                        nodes.add(new Pt(x[i], y[i]));
                        indx[i] = nodes.size() - 1;
                    } else if (a * b == 0 && !points.contains(new Pair<>(x[i] + a, y[i] + b))) {
                        nodes.add(new Pt(x[i] + a, y[i] + b));
                    }
                }

        // Make edges
        for (int i = 0; i < nodes.size(); i++)
            for (int j = i + 1; j < nodes.size(); j++)
                if (possible(i, j)) {
                    adj[i].add(j);
                    adj[j].add(i);
                }

        // Dijkstra's Algorithm
        int answer = 0;
        for (int i = 0; i < N; i++) {
            int next = dijkstra(indx[i], indx[(i + 1) % N]);
            if (next < 0) {
                answer = -1;
                break;
            } else {
                answer += next;
            }
        }

        System.out.println(answer);
    }
}

class Pair<U, V> {
    public final U first;
    public final V second;

    public Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public boolean equals(Object o) {
        if (!(o instanceof Pair)) return false;
        Pair<?, ?> p = (Pair<?, ?>) o;
        return Objects.equals(first, p.first) && Objects.equals(second, p.second);
    }

    @Override
    public int hashCode() {
        return Objects.hash(first, second);
    }
}