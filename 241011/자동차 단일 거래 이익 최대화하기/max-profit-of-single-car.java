import java.util.*;

public class Main {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
       
        int n = sc.nextInt(), index = 0;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        int[] price = new int[n];

        for(int i=0; i<n; i++){
            price[i] = sc.nextInt();
        }

        for(int i=0; i<n; i++){
            if(price[i] < min){
                min = price[i];
                index = i;
            }
        }
        if(index == n-1){
            System.out.print(0);
            return;
        }

        for(int i=index+1; i<n; i++){
            if(price[i]>max){
                max = price[i];
            }
        }
        if(max==min || max == Integer.MIN_VALUE){
            System.out.print(0);
            return;
        }else{
            System.out.print(max-min);
        }
    }
}