import java.util.Scanner;

public class Main {
    public static final int INF = 987654321;
    public static final int MAX_N = 12;

    public static int n, m;
    public static int[] weights = new int[MAX_N];
    public static int[][] dp = new int[1 << MAX_N][102];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 변수를 입력받습니다.
        n = sc.nextInt();
        m = sc.nextInt();
        for(int i = 0; i < n; i++) weights[i] = sc.nextInt();

        for(int i = 0; i < n; i++) {
            if(weights[i] > m) {
                System.out.println(-1);
                return;
            }
        }

        for(int i = 0; i < (1 << n); i++) {
            for(int j = 0; j <= m; j++) {
                dp[i][j] = INF;
            }
        }

        dp[0][m] = 1;
        // 각 문제를 풀었는지 정보를 비트마스킹해 저장하고 dp를 수행합니다.
        for(int visited = 0; visited < (1 << n); visited++) {
            for(int capacity = 0; capacity <= m; capacity++) {
                if(dp[visited][capacity] == INF) continue;
                for(int i = 0; i < n; i++) {
                    if((visited & (1 << i)) != 0) continue;
                    int nextVisited = visited | (1 << i);
                    // 만약 용량을 넘지 않는다면, 팀원이 해당 문제도 풉니다.
                    if(capacity >= weights[i]) {
                        dp[nextVisited][capacity - weights[i]] = Math.min(dp[nextVisited][capacity - weights[i]], dp[visited][capacity]);
                    }
                    // 만약 용량을 넘는다면, 다음 팀원이 해당 문제를 풉니다.
                    else {
                        dp[nextVisited][m - weights[i]] = Math.min(dp[nextVisited][m - weights[i]], dp[visited][capacity] + 1);
                    }
                }
            }
        }

        int answer = INF;
        for(int i = 0; i <= m; i++) {
            answer = Math.min(dp[(1 << n) - 1][i], answer);
        }

        // 결과를 출력합니다.
        if(answer == INF) System.out.println(-1); // 불가능한 경우를 처리합니다.
        else System.out.println(answer);
    }
}