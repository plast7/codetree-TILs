import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static final int MAXN = 1005;

    public static int N;
    public static int[] cows = new int[MAXN];
    public static int[][] best = new int[MAXN][2], best2 = new int[MAXN][2];

    public static void mini(int[] arr, int index, int value) {
        if (value < arr[index]) {
            arr[index] = value;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Initialize best array with a large value
        for (int i = 0; i < MAXN; i++) {
            Arrays.fill(best[i], Integer.MAX_VALUE);
        }

        N = sc.nextInt();

        for (int i = 1; i <= N; i++) {
            cows[i] = sc.nextInt();
        }

        cows[++N] = 0;

        Arrays.sort(cows, 1, N + 1);

        for (int i = 1; i <= N; i++) {
            if (cows[i] == 0) {
                best[i][0] = 0;
            }
        }

        for (int len = 1; len < N; len++) {
            int ccount = N - len;

            // Initialize best2 array with a large value
            for (int i = 0; i < MAXN; i++) {
                Arrays.fill(best2[i], Integer.MAX_VALUE);
            }

            for (int i = 1; i + len <= N + 1; i++) {
                mini(best2[i - 1], 0, best[i][0] + ccount * (cows[i] - cows[i - 1]));
                mini(best2[i - 1], 0, best[i][1] + ccount * (cows[i + len - 1] - cows[i - 1]));

                mini(best2[i], 1, best[i][0] + ccount * (cows[i + len] - cows[i]));
                mini(best2[i], 1, best[i][1] + ccount * (cows[i + len] - cows[i + len - 1]));
            }

            for (int i = 0; i < MAXN; i++) {
                System.arraycopy(best2[i], 0, best[i], 0, 2);
            }
        }

        mini(best[1], 0, best[1][1]);
        System.out.println(best[1][0]);

        sc.close();
    }
}