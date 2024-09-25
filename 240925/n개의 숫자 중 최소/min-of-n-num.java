import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] arr = new int[10];

        for (int i = 0; i < 10; i++) {
            arr[i] = sc.nextInt();
        }

        int minVal = Integer.MAX_VALUE;
        int cnt = 0;

        for (int i = 0; i < 10; i++) {
            if (minVal > arr[i]) {
                minVal = arr[i];
            }
        }

        for (int i = 0; i < 10; i++) {
            if (arr[i] == minVal) {
                cnt++;
            }
        }

        System.out.print(minVal + " ");
        System.out.println(cnt);
    }
}