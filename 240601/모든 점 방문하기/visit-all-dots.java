import java.util.Arrays;
import java.util.Scanner;

public class Main {

    private static final int MAXN = 1005;

    private static int N;
    private static int[] cows = new int[MAXN];
    private static int[][] best = new int[MAXN][2], best2 = new int[MAXN][2];

    private static void mini(int[] a, int index, int b) {
        if (b < a[index]) {
            a[index] = b;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int[] row : best) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        N = sc.nextInt(); // 입력받기
        for (int i = 1; i <= N; i++) {
            cows[i] = sc.nextInt();
        }

        cows[++N] = 0; // 종료 값 추가
        Arrays.sort(cows, 1, N + 1);

        for (int i = 1; i <= N; i++) {
            if (cows[i] == 0) {
                best[i][0] = 0;
            }
        }

        for (int len = 1; len < N; len++) {
            int ccount = N - len;

            for (int[] row : best2) {
                Arrays.fill(row, Integer.MAX_VALUE);
            }

            for (int i = 1; i + len <= N + 1; i++) {
                mini(best2[i - 1], 0, best[i][0] + ccount * (cows[i] - cows[i - 1]));
                mini(best2[i - 1], 0, best[i][1] + ccount * (cows[i + len - 1] - cows[i - 1]));

                mini(best2[i], 1, best[i][0] + ccount * (cows[i + len] - cows[i]));
                mini(best2[i], 1, best[i][1] + ccount * (cows[i + len] - cows[i + len - 1]));
            }

            for (int j = 0; j < best.length; j++) {
                System.arraycopy(best2[j], 0, best[j], 0, best[j].length);
            }
        }

        mini(best[1], 0, best[1][1]);
        System.out.println(best[1][0]);

        sc.close();
    }
}