import java.util.*;

public class Main {
    public static int N, M;
    public static ArrayList<Integer> problems;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();

        problems = new ArrayList<>();

        for (int i = 0; i < N; i++){
            int v = sc.nextInt();
            problems.add(v);

        }

        Collections.sort(problems);

        int start = 0;
        int end = problems.size() -1;
        int ans = 0;

        while (0 <= end && start < N && start <= end ){
            int k = problems.get(end);
            if (k > M){
                ans = -1;
                break;
            }
            end--;
            ans++;
            while (start < N && k + problems.get(start) <= M){
                k += problems.get(start);
                start++;
            }
        }
        System.out.println(ans);
    }
}