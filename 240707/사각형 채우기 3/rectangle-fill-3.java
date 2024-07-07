import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        long[] dp = new long[1001];

        dp[0]=1;
        dp[1]=2;
        dp[2]=7;
        long MOD = 1000000007;

        for(int i=3; i<=N; i++){
            // dp[i] = ((3*(long)dp[i-1])+((long)dp[i-2])-((long)dp[i-3]))%(long)1000000007;
            dp[i] = ((3 * dp[i - 1] + dp[i - 2] - dp[i - 3]) % MOD + MOD) % MOD;
        }

        System.out.println(dp[N]);
        // 여기에 코드를 작성해주세요.
    }
}