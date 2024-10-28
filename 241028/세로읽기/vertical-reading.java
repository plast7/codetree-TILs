import java.util.Scanner;

public class Main {
    // 각 줄의 문자들을 저장하는 배열입니다.
    public static char[][] a = new char[5][16];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 4개의 문자열을 입력받습니다.
        for(int i = 0; i < 4; i++)
            a[i] = sc.next().toCharArray();

        // 각 열에 대해 수행합니다.
        for(int j = 0; j < 15; j++) {
            // 각 행의 문자를 순서대로 출력합니다.
            for(int i = 0; i < 4; i++) {
                // 해당 위치에 문자가 있다면 출력합니다.
                if(j < a[i].length && a[i][j] != '\0')
                    System.out.print(a[i][j]);
            }
        }
    }
}