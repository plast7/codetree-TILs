import java.io.*;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;

public class Main {

    static PriorityQueue<Integer> pq = new PriorityQueue<>();
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int maxSum = 0;
        for(int i=0; i<n; i++){
            int number = Integer.parseInt(st.nextToken());
            maxSum += number;
            pq.add(number);
        }

        maxSum -= pq.poll(); // n-1개가 된다.
        double ans = maxSum / (n-1);
        for(int i=1; i<n-2; i++){
            maxSum -= pq.poll();
            double curAvg = maxSum / (n-i-1);
            ans = Math.max(curAvg, ans);
        }
        System.out.printf("%.2f", ans);

    }
}