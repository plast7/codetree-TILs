import java.util.Scanner;

public class Main {
    
    static final int MAX_N = 50; // 변수 선언 영역
    static int n, m;
    static int[] points = new int[MAX_N + 1];
    
    // dp[i][j][k][l] : 둘 다 시작점에서 출발하여 서로 겹치지 않게 카드를 순서대로 선택하면서
    //                  마지막으로 i번 카드까지 확인했고,
    //                  첫번째 사람은 마지막으로 j번 카드를 골랐고,
    //                  두번째 사람은 마지막으로 k번 카드를 골랐을 때
    //                  지금까지 l개의 카드를 스킵했을 때
    //                  지금까지 온 거리의 합 중 가능한 최솟값
    static int[][][][] dp = new int[MAX_N + 1][MAX_N + 1][MAX_N + 1][MAX_N + 1];
    
    // 두 카드의 거리를 계산합니다.
    // 원래는 |points[x] - points[y]|가 되지만,
    // x = 0의 초기값일 때에는 0을 반환해야 합니다.
    static int Dist(int x, int y) {
        if(x == 0) return 0;
        return Math.abs(points[x] - points[y]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // 입력
        n = sc.nextInt();
        m = sc.nextInt();

        for (int i = 1; i <= n; i++)
            points[i] = sc.nextInt();

        // 최소를 구하는 문제이므로
        // 처음에 dp값을 큰 값으로 설정합니다.
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                for (int k = 0; k <= n; k++)
                    for (int l = 0; l <= m; l++)
                        dp[i][j][k][l] = (int) 2e9;

        // 초기조건을 설정합니다.
        // Bitonic Cycle 유형에서
        // 둘 다 카드를 아무것도 고르지 않은 순간입니다.
        dp[0][0][0][0] = 0;

        // 뿌려주는 dp를 진행합니다.
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= n; k++) {
                    for (int l = 0; l <= m; l++) {
                        int next = i + 1;

                        if (next == n + 1)
                            continue;

                        // 첫번째 사람이 next카드를 뽑는 경우입니다.
                        dp[next][next][k][l] = Math.min(dp[next][next][k][l], dp[i][j][k][l] + Dist(j, next));

                        // 두번째 사람이 next카드를 뽑는 경우입니다.
                        dp[next][j][next][l] = Math.min(dp[next][j][next][l], dp[i][j][k][l] + Dist(k, next));

                        // 또는 카드를 스킵할 수 있습니다.
                        if (l != m)
                            dp[next][j][k][l + 1] = Math.min(dp[next][j][k][l + 1], dp[i][j][k][l]);
                    }
                }
            }
        }

        // n에 도달한 경우에 대해서 최솟값을 구해줍니다.
        int ans = (int) 2e9;
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                ans = Math.min(ans, dp[n][j][k][m]);
            }
        }

        System.out.println(ans);
    }
}