import java.util.Scanner;
import java.util.ArrayList;

public class Main {

    static int n, k;
    static List<Integer> list = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        k = sc.nextInt();

        recursive(0);

    }

    static void recursive(int index) {

        if (index == k) {
            for (int i = 0; i < k; i++) {
                System.out.print(list.get(i) + " ");
            }
            System.out.println();
            return;
        }

        for (int i = 1; i <= n; i++) {

            list.add(i);
            recursive(index + 1);
            list.remove(list.size() - 1);

        }



    }


}