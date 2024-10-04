import java.util.*;

public class Main {
    public static void main(String[] args) {
        // 여기에 코드를 작성해주세요.
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        TreeSet<Integer> set = new TreeSet<>();
        for(int i=0; i<N; i++){
            set.add(sc.nextInt());
        }
        set.add(1000000001);

        HashMap<Integer, Integer> map = new HashMap<>();
        int cnt=1;
        for(int num : set){
            map.put(num, cnt);
            cnt++;
        }
        // int st = 1;
        // int ed = 5;
        // System.out.println(set.ceiling(st) + " " + set.higher(ed));

        while(M-- > 0){
            int st = sc.nextInt();
            int ed = sc.nextInt();

            int newA = map.get(set.ceiling(st));
            int newB = map.get(set.higher(ed));

            System.out.println(newB - newA);
        }
        
    }
}