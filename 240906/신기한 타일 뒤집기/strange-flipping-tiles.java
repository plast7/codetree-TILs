import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();

        int white = 0;
        int black = 0;

        for(int i = 0; i < n; i++) {
            int spaces = scan.nextInt();
            char direction = scan.next().charAt(0);

            switch(direction) {
                case 'R':
                    if(white >= spaces) {
                        white = white - spaces;
                        black = black + spaces;
                    } else {
                        if(black != 0) {
                            black = black + spaces - 1;
                        } else {
                            black = black + spaces;
                        }
                        white = 0;
                    }
                    break; 

                case 'L':
                    if(black >= spaces) {
                        black = black - spaces;
                        white = white + spaces;
                    } else {
                        if(white != 0) {
                            white = white + spaces - 1;
                        } else {
                            white = white + spaces;
                        }
                        black = 0;
                    }
                    break;  

                default:
                    break;
            }
        }
        System.out.println(white + " " + black);
    }
}