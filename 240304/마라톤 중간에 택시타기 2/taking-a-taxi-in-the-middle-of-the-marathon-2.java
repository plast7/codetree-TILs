import java.util.*;

public class Main {
    static int MIN = Integer.MAX_VALUE;
    static List<List<Integer>> graph;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        graph = new ArrayList<List<Integer>>();

        for (int i = 0; i < n; i++) {   // Index : 0  ~ n-1까지 
            List<Integer> coordinates = new ArrayList<>();
            coordinates.add(Integer.valueOf(sc.nextInt()));
            coordinates.add(Integer.valueOf(sc.nextInt()));
            graph.add(coordinates);
        }

        for (int i = 1; i < n -1; i++) { // 1 ~ n-2까지 
            List<Integer> placeBefore = graph.get(0);

            int sum = 0;

            int beforeX = placeBefore.get(0);
            int beforeY = placeBefore.get(1);


            for (int j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }

                List<Integer> place = graph.get(j);
                int x = place.get(0);
                int y = place.get(1);

                if(j<i){
                    sum += Math.abs(beforeX - x) + Math.abs(beforeY - y);
                    beforeX = x;
                    beforeY = y;
                }else if(j>i){
                    sum+=Math.abs(x -beforeX)+ Math.abs(y-beforeY);
                    beforeX = x;
                    beforeY = y;
                }

            }

            MIN = Math.min(MIN, sum);
        }

        System.out.println(MIN);
    }
}