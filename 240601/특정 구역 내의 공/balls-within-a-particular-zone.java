import java.util.*;

public class Main {

    public static final int INF = 1 << 30;
    
    public static int[] x = new int[3010];
    public static int[] y = new int[3010];
    public static int[] t = new int[3010];
    
    public static int compress(int[] a, int z) {
        System.arraycopy(a, 0, t, 0, z);
        Arrays.sort(t, 0, z);
        int nz = (int) Arrays.stream(t, 0, z).distinct().count();
        for (int i = 0; i < z; i++) {
            a[i] = Arrays.binarySearch(t, 0, nz, a[i]) * 2;
        }
        return nz * 2;
    }
    
    public static int xz, yz;
    public static char[][] arr = new char[6010][6010];
    public static int gz;
    public static int[] mx = {-1, 0, 1, 0};
    public static int[] my = {0, -1, 0, 1};
    public static Stack<Short> sx = new Stack<>();
    public static Stack<Short> sy = new Stack<>();
    
    public static void put(int x, int y) {
        if (x < 0 || x >= xz || y < 0 || y >= yz) return;
        if (arr[x][y] == 'X') return;
        gz += (arr[x][y] == 'C') ? 1 : 0;
        arr[x][y] = 'X';
        sx.push((short) x);
        sy.push((short) y);
    }
    
    public static void dfs(int startx, int starty) {
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
        
        x[z] = y[z] = -INF; z++;
        x[z] = y[z] = INF; z++;
        
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
        
        for (int i = 0; i < 6010; i++) {
            Arrays.fill(arr[i], '.');
        }
        
        for (int i = 0; i < n; i++) {
            int a = i * 2 + 2;
            int b = i * 2 + 3;
            int x1 = x[a], y1 = y[a], x2 = x[b], y2 = y[b];
            if (x1 == x2) {
                if (y1 > y2) {
                    int temp = y1;
                    y1 = y2;
                    y2 = temp;
                }
                while (y1 <= y2) {
                    arr[x1][y1] = 'X';
                    y1++;
                }
            } else {
                if (x1 > x2) {
                    int temp = x1;
                    x1 = x2;
                    x2 = temp;
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