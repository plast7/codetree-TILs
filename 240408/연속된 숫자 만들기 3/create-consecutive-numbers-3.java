import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static final int MAX_N = 3;
    
    public static int n = 3;
    public static int[] a = new int[MAX_N];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // 입력:
        for(int i = 0; i < n; i++)
            a[i] = sc.nextInt();

        // Case 1. 3개의 숫자가 전부 연속한 경우
        // 이 경우에는 이동할 필요가 없으므로
        // 최대 이동 횟수는 0이 됩니다.
        if(a[0] + 1 == a[1] && a[1] + 1 == a[2]) {
            System.out.print(0);
            System.exit(0);
        }
        
        int maxMove = 0;
        // 그렇지 않은 경우 왼쪽 끝 사람이 이동하는 경우와
        // 오른쪽 끝 사람이 이동하는 경우로 나뉘게 됩니다.
        // 각각 거리를 한칸씩 좁혀가면서 이동하는 방식이 최대 이동횟수를 만들기 때문에
        // Case 2. 왼쪽 끝 사람이 가장 먼저 이동하는 경우
        // 최대 이동 횟수는 (오른쪽 끝 사람과 가운데 사람의 거리) - 1 회가 됩니다.
        int move = a[2] - a[1] - 1;
        maxMove = Math.max(maxMove, move);

        // Case 3. 오른쪽 끝 사람이 가장 먼저 이동하는 경우
        // 최대 이동 횟수는 (왼쪽 끝 사람과 가운데 사람의 거리) - 1 회가 됩니다.
        move = a[1] - a[0] - 1;
        maxMove = Math.max(maxMove, move);

        System.out.print(maxMove);
    }
}