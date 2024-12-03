import java.util.*;
public class Main {
    public static int[][] paper = new int[2001][2001];
    public static int size,total,max_x,max_y,maxx_val,maxy_val;
    public static void main(String[] args) {
        // 여기에 코드를 작성해주세요.
        Scanner sc = new Scanner(System.in);
        maxx_val = -1;
        maxy_val = -1;
        int now = 1000;
        for(int s = 0; s<2; s++){
            int x1 = sc.nextInt();
            int y1 = sc.nextInt();
            int x2 = sc.nextInt();
            int y2 = sc.nextInt();
            for(int i = x1+now; i<x2+now; i++){
                for(int j = y1 + now; j<y2+now; j++){
                    if(s == 0){
                        paper[i][j]++;
                    }else{
                        paper[i][j]--;
                    }
                }
            }
        }
        for(int i = 0; i<2001; i++){
            max_x = 0;
            for(int j = 0; j < 2001; j++){
                if(paper[i][j] == 1){
                    max_x++;
                }
            }
            if(max_x>maxx_val){
                maxx_val = max_x;
            }
        
        }
        
        for(int i = 0; i<2001; i++){
            max_y = 0;
            for(int j = 0; j < 2001; j++){
                if(paper[j][i] == 1){
                    max_y++;
                }
            }
            if(max_y>maxy_val){
                maxy_val = max_y;
            }
            
        }
        // System.out.println(maxx_val);
        // System.out.println(maxy_val);
        System.out.println(maxx_val*maxy_val);

    }
}
