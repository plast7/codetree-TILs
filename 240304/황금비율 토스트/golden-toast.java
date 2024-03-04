import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        // 여기에 코드를 작성해주세요.
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        String str1 = sc.next();
        LinkedList<Character> l = new LinkedList<>();
        ListIterator<Character> it = l.listIterator(l.size());

        for(int i=0; i<str1.length(); i++){
            l.add(str1.charAt(i));
        }

        for(int i=0; i<m; i++){
            String[] str2 = sc.nextLine().split(" ");
            switch(str2[0]){
                case "L":
                    if(it.hasPrevious())
                        it.previous();
                    break;
                case "R":
                    if(it.hasNext());
                        it.next();
                    break;
                case "D":
                    it.next();
                    it.remove();
                    break;
                case "P":
                    char a = str2[1].charAt(0);
                    it.add(a);
                    it.next();
                    break;
            }
        }
        it = l.listIterator();
        while(it.hasNext()){
            System.out.print(it.next());
        }
    }
}