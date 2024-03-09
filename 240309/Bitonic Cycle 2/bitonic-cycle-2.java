import java.util.*;
import java.io.*;

class point implements Comparable<point>{
    int x, y;
    public point(int x, int y){
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(point p){
        return this.x - p.x;
    }
}

public class Main {
    public static final int MAX_POINT = 1000;
    public static final long MAX_LONG = (long)1e12;
    public static point[] pointArr = new point[MAX_POINT];
    public static long[][] DP = new long[MAX_POINT][MAX_POINT];
    public static long[][] maxDP = new long[MAX_POINT][MAX_POINT];
    public static int n = -1;

    public static long calDist(int i, int j){
        return (long)(Math.pow(pointArr[i].x - pointArr[j].x, 2) + Math.pow(pointArr[i].y - pointArr[j].y, 2));
    }

    public static void makeDP(){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                int next = Math.max(i, j) + 1;

                if(next >= n){
                    continue;
                }

                if(DP[next][j] > DP[i][j] + calDist(i, next)){
                    DP[next][j] = DP[i][j] + calDist(i, next);
                    maxDP[next][j] = Math.max(maxDP[i][j], calDist(i, next));
                }
                else if(DP[next][j] == DP[i][j] + calDist(i, next)){
                    long inMaxVal = Math.max(maxDP[i][j], calDist(i, next));
                    maxDP[next][j] = Math.max(maxDP[next][j], inMaxVal);
                }

                if(DP[i][next] > DP[i][j] + calDist(j, next)){
                    DP[i][next] = DP[i][j] + calDist(j, next);
                    maxDP[i][next] = Math.max(maxDP[i][j], calDist(j, next));
                }
                else if(DP[i][next] == DP[i][j] + calDist(j, next)){
                    long inMaxVal = Math.max(maxDP[i][j], calDist(j, next));
                    maxDP[i][next] = Math.max(maxDP[i][next], inMaxVal);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        for(int i = 0 ; i < n ; i++){
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            pointArr[i] = new point(x, y);
        }

        Arrays.sort(pointArr, 0, n);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                DP[i][j] = MAX_LONG;
            }
        }

        DP[0][0] = 0;

        makeDP();
        
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = 0 ; j < n ; j++){
        //         System.out.print(calDist(i, j) + " ");
        //     }
        //     System.out.println();
        // }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                System.out.print(DP[i][j] + " ");
            }
            System.out.println();
        }

        // System.out.println();

        // for(int i = 0 ; i < n ; i++){
        //     for(int j = 0 ; j < n ; j++){
        //         System.out.print(maxDP[i][j] + " ");
        //     }
        //     System.out.println();
        // }
        
        long ans = MAX_LONG;
        for(int i = 0 ; i < n ; i++){
            long totalDist = DP[i][n - 1] + calDist(i, n - 1);
            long maxDist = Math.max(maxDP[i][n - 1], calDist(i, n - 1));
            long ansDist = totalDist - maxDist;
            ans = Math.min(ans, ansDist);
        }

        System.out.println(ans);
    }
}