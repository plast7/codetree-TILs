import java.util.*;

class Pair{ int x, y; public Pair(int x, int y){ this.x = x; this.y = y; } }

public class Main {

public static int n,m;
public static ArrayList<Pair> arr = new ArrayList<>();
public static ArrayList<Pair> select = new ArrayList<>();
//public static ArrayList<Integer> min = new ArrayList<>();
public static double small = 20000;

// 고른 점들 중에서 가장 먼 두 점을 고르기
public static void check(){
    if(select.size() != n)
        return;
    Collections.sort(select, new Comparator<Pair>() {
        @Override
        public int compare(Pair p1, Pair p2) {
            return Integer.compare(p1.x, p2.x);
        }
    });
    /*for(int i=0; i<select.size()-1; i++)
        System.out.println(select.get(i).x+" "+select.get(i).y);
    System.out.println("---------------------------");*/
    int x1 = select.get(0).x;
    int y1 = select.get(0).y;
    int x2 = select.get(select.size()-1).x;
    int y2 = select.get(select.size()-1).y;
    double result = Math.pow(Math.abs(x1-x2),2) + Math.pow(Math.abs(y1-y2),2);
    small = Math.min(small, result);
}

//num번째 선택할 점 고르기
public static void choose(int num){
    if(num == n){
        check();
        return;
    }

    //arr의 num번째 점을 고르는 경우
    select.add(arr.get(num));
    choose(num+1);
    select.remove(select.size()-1);

    //arr의 num번째 점을 고르지 않는 경우
    choose(num+1);
}

public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    m = sc.nextInt();
    for(int i=0; i<n; i++){
        int x = sc.nextInt();
        int y = sc.nextInt();
        arr.add(new Pair(x,y));
    }

    choose(0);
    System.out.println((int)small);
}
}