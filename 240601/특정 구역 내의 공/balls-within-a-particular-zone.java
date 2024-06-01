import java.util.*;

public class Main {
    static final int inf = 1 << 30;
    
    static int[] x = new int[3010];
    static int[] y = new int[3010];
    static int[] t = new int[3010];
    
    static int compress(int[] a, int z) {
        System.arraycopy(a, 0, t, 0, z);
        Arrays.sort(t, 0, z);
        int nz = 0;
        for (int i = 1; i < z; i++) {
            if (t[i] != t[nz]) {
                t[++nz] = t[i];
            }
        }
        nz++;
        for (int i = 0; i < z; i++) {
            a[i] = Arrays.binarySearch(t, 0, nz, a[i]) * 2;
        }
        return nz * 2;
    }
    
    static int xz, yz;
    static char[][] arr = new char[6010][6010];
    
    static int gz;
    static int[] mx = {-1, 0, 1, 0};
    static int[] my = {0, -1, 0, 1};
    
    static Stack<Short> sx = new Stack<>();
    static Stack<Short> sy = new Stack<>();
    
    static void put(int x, int y) {
        if (x < 0 || x >= xz || y < 0 || y >= yz) return;
        if (arr[x][y] == 'X') return;
        gz += (arr[x][y] == 'C') ? 1 : 0;
        arr[x][y] = 'X';
        sx.push((short)x);
        sy.push((short)y);
    }
    
    static void dfs(int startx, int starty) {
        // sx, sy should be empty
        put(startx, starty);
        while (!sx.isEmpty()) {
            int x = sx.pop();
            int y = sy.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + mx[i];
                int ny = y + my[i];
                put(nx, ny);
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int m = sc.nextInt();
        int z = 0;
        x[z] = y[z] = -inf; z++;
        x[z] = y[z] = inf; z++;
        for (int i = 0; i < 2 * n; i++) {
            x[z] = sc.nextInt();
            y[z] = sc.nextInt();
            z++;
        }
        for (int i = 0; i < m; i++) {
            x[z] = sc.nextInt();
            y[z] = sc.nextInt();
            z++;
        }
        xz = compress(x, z);
        yz = compress(y, z);
        for (char[] row : arr) Arrays.fill(row, '.');
        for (int i = 0; i < n; i++) {
            int a = i * 2 + 2;
            int b = i * 2 + 3;
            int x1 = x[a], y1 = y[a], x2 = x[b], y2 = y[b];
            if (x1 == x2) {
                if (y1 > y2) {
                    int temp = y1; y1 = y2; y2 = temp;
                }
                while (y1 <= y2) {
                    arr[x1][y1] = 'X';
                    y1++;
                }
            } else {
                if (x1 > x2) {
                    int temp = x1; x1 = x2; x2 = temp;
                }
                while (x1 <= x2) {
                    arr[x1][y1] = 'X';
                    x1++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int a = i + 2 * n + 2;
            arr[x[a]][y[a]] = 'C';
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int a = i + 2 * n + 2;
            gz = 0;
            dfs(x[a], y[a]);
            ans = Math.max(ans, gz);
        }
        System.out.println(ans);
    }
}