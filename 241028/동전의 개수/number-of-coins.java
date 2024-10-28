import java.util.Scanner;

public class Main {    
    public static final int MAX_N = 10;
    
    // 변수 선언
    public static int n, k;
    public static int[] coins = new int[MAX_N];
    
    public static int ans;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // 입력:
        n = sc.nextInt();
        k = sc.nextInt();
        for(int i = 0; i < n; i++)
            coins[i] = sc.nextInt();

        // 큰 동전부터 이용합니다.
        for(int i = n - 1; i >= 0; i--) {
            ans += k / coins[i];
            k %= coins[i];
        }

        System.out.print(ans);
    }
}