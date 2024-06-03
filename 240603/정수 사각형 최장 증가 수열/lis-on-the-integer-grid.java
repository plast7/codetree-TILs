import java.util.Scanner;

public class Main {
    public static final int DIR_NUM = 4;
    public static final int MAX_N = 500;
    
    // 변수 선언
    public static int n;
    public static int[][] grid = new int[MAX_N][MAX_N];
    public static int[][] dp = new int[MAX_N][MAX_N];
    
    public static boolean inRange(int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < n;
    }
    
    // (x, y)에서 출발하여 조건을 만족하며
    // 도달할 수 있는 칸의 수 중
    // 최대 칸의 수를 구합니다.
    public static int findMax(int x, int y) {
        // 이미 계산해본적이 있다면
        // 그 값을 바로 반환합니다.
        if(dp[x][y] != -1)
            return dp[x][y];
    
        // 기본값은 자기자신이 됩니다.
        int best = 1;
    
        // 정수값이 작은 칸부터 순서대로 보며
        // 4방향에 대해 최적의 칸 수를 계산합니다.
        int[] dx = new int[]{-1, 1,  0, 0};
        int[] dy = new int[]{ 0, 0, -1, 1};
    
        for(int j = 0; j < DIR_NUM; j++) {
            int nx = x + dx[j], ny = y + dy[j];
            if(inRange(nx, ny) && grid[nx][ny] > grid[x][y])
                best = Math.max(best, findMax(nx, ny) + 1);
        }
    
        return dp[x][y] = best;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 입력
        n = sc.nextInt();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                grid[i][j] = sc.nextInt();

        // 메모이제이션을 위해 
        // 전부 초기값을 -1로 셋팅해줍니다.
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = -1;

        // 각 칸에 시작했을 떄
        // 최대로 이동할 수 있는 칸의 수 중 
        // 최댓값을 갱신합니다.
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                ans = Math.max(ans, findMax(i, j));
        
        System.out.print(ans);
    }
}