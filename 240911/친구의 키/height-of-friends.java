import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        int[][] adjArr = new int[n+1][n+1];
        int[] degree = new int[n+1];
        for (int i=0; i<m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            adjArr[a][b] = 1;
            degree[b]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i=1; i<=n; i++) {
            if (degree[i] == 0)
                q.add(i);
        }

        while(!q.isEmpty()) {
            int curr = q.poll();

            System.out.print(curr + " ");
            for (int i=1; i<=n; i++) {
                if (adjArr[curr][i] == 1) {
                    degree[i]--;
                    adjArr[curr][i] = 0;
                    if (degree[i] == 0)
                        q.add(i);
                }
            }
        }

    }
}