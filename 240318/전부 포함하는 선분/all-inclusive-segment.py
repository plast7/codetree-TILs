import java.util.Scanner;

public class Main {
    public static final int INT_MAX = Integer.MAX_VALUE;
    public static final int MAX_N = 100;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] x1 = new int[MAX_N];
        int[] x2 = new int[MAX_N];
        int ans = INT_MAX;

        // 입력
        for(int i = 0; i < n; i++) {
            x1[i] = sc.nextInt();
            x2[i] = sc.nextInt();
        }

        // 가장 시작점이 작은 선분을 지우거나, 가장 끝점이 큰 선분을 지울 때에만
        // 전부 포함하는 선분이 줄어들 가능성이 있습니다.
        // 가장 시작점이 작은 선분을 찾습니다.
        int skip = 0;
        for(int i = 0; i < n; i++) {
            if(x1[skip] > x1[i]) skip = i;
        }

        int max_x2 = 0;
        int min_x1 = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(i == skip) continue;

            // 시작점 중 가장 앞에 있는 좌표와 끝점 중 가장 뒤에 있는 점의 좌표를 확인합니다.
            max_x2 = Math.max(max_x2, x2[i]);
            min_x1 = Math.min(min_x1, x1[i]);
        }

        // 조건을 만족하는 선분의 길이는 max_x2 - min_x1입니다.
        // 정답보다 이 선분의 길이가 작으면 업데이트합니다.
        ans = Math.min(ans, max_x2 - min_x1);

        // 가장 끝점이 큰 선분을 찾습니다.
        skip = 0;
        for(int i = 0; i < n; i++) {
            if(x2[skip] < x2[i]) skip = i;
        }

        max_x2 = 0;
        min_x1 = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(i == skip) continue;

            // 시작점 중 가장 앞에 있는 좌표와 끝점 중 가장 뒤에 있는 점의 좌표를 확인합니다.
            max_x2 = Math.max(max_x2, x2[i]);
            min_x1 = Math.min(min_x1, x1[i]);
        }

        // 조건을 만족하는 선분의 길이는 max_x2 - min_x1입니다.
        // 정답보다 이 선분의 길이가 작으면 업데이트합니다.
        ans = Math.min(ans, max_x2 - min_x1);

        System.out.println(ans);
    }
}