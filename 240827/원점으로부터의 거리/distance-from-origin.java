import java.util.*;

class Dot implements Comparable<Dot>{
    int x, y, num;

    public Dot(int x, int y, int num){
        this.x = x;
        this.y = y;
        this.num = num;
    }

    @Override
    public int comapareTo(Dot dot){
        if(Math.abs(this.x) + Math.abs(this.y) == Math.abs(dot.x) - Math.abs(dot.y)){
            return this.num - dot.num;
        }
        return Math.abs(this.x) + Math.abs(this.y) - Math.abs(dot.x) - Math.abs(dot.y);
    }
}

public class Main {
    public static void main(String[] args) {
        // 여기에 코드를 작성해주세요.
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        Dot[] dot = new Dot[n];
        for(int i=0; i<n; i++){
            int x = sc.nextInt();
            int y = sc.nextInt();

            dot[i] = Dot(x, y, i+1);
        }

        Arrays.sort(dot);

        for(int i=0;i<n;i++){
            System.out.println(dot[i].num);
        }

    }
}