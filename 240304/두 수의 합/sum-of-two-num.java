import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        HashMap<Long, Integer> map = new HashMap<>();

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        long[] arr = new long[n];
        int result = 0;

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            long num = Long.parseLong(st.nextToken());

            arr[i] = num;
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        for (int i = 0; i < n; i++) {
            long temp = k - arr[i];

            if (map.containsKey(temp) && map.get(arr[i]) > 0) {
                result += map.get(temp);

                if (arr[i] == temp) {
                    result--;
                }

                map.put(arr[i], map.get(arr[i]) - 1);
            }
        }

        System.out.println(result);
    }
}