import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int arr[] = new int[n];

        
        for(int i = 0; i<n; i++){
             arr[i] = sc.nextInt();
        }

        int max = Integer.MIN_VALUE;
        int smax = Integer.MIN_VALUE;

        int z=0;
        for(int i = 0 ; i<n; i++){
            if(max<arr[i]){
                max=arr[i];
                z=i;
            }

               
        }

        for(int i = 0; i<n; i++){
            if(smax<arr[i]&&i!=z){
                smax=arr[i];
            }
        }


        System.out.print(max+" "+smax);
    }
}