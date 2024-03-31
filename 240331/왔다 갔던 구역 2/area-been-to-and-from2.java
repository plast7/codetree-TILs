import java.util.*;
public class Main {
    public static void main(String[] args) {
        // 여기에 코드를 작성해주세요.
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();
        int[] arr = new int[2000];
        Arrays.fill(arr,0);
        int now=999;
        int size =0;
        for(int i=0; i<n; i++){
            int offset = sc.nextInt();
            char m = sc.next().charAt(0);
            if(m=='R'){
                for(int j=now; j<=now+offset; j++){
                    arr[j]++;
                }
                now+=offset;
            }
            else{
                for(int j=now; j>=now-offset; j--){
                    arr[j]++;
                }
                now-=offset;
            }
        }
        boolean flag= false;
        for(int i=0; i<2000; i++){  //size ( 겹치는 넓이) 카운트하기
            if(arr[i]>1 && flag == true){ //겹치기 카운트
                size++;
            }
            else if(arr[i]>1 && flag == false){ //겹치기 시작
                flag=true;
            }
            else if(arr[i]==1 && flag == true){ //겹치기 끝
                flag=false;
            }
        }
        System.out.print(size);
    }
}