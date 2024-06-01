import java.util.Scanner;

public class Main {
    public static final int MOD = 2012;
    public static final int MAXN = 1010;

    public static int[] A = new int[MAXN];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();

        int L = 1;
        A[1] = 1;
        for (int i = 0; i < input.length(); i++) {
            char ch = input.charAt(i);
            if (ch != '(' && ch != ')') break;

            int dir = ch == '(' ? 1 : -1;
            L += dir;
            for (int j = (dir < 0) ? 1 : L; 1 <= j && j <= L; j -= dir) {
                A[j] += A[j - dir];
                if (A[j] >= MOD) A[j] -= MOD;
            }
            A[L + 1] = 0;
        }

        System.out.println(L == 1 ? A[1] : 0);
    }
}