import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // 여기에 코드를 작성해주세요.
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[100];
        int cnt= 0;
        int minVal = 100;

        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
            if(minVal > arr[i]){
                minVal = arr[i];
               
            }
        }
        for(int i = 0 ;  i< n; i ++){
            if(arr[i] == minVal){
                cnt++;
            }
        }
        System.out.print(minVal+ " "+ cnt);
    }
}