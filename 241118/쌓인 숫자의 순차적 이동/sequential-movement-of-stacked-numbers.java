import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static int[] dr = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int[] dc = {0, 1, 1, 1, 0, -1, -1, -1};
    static List<Integer>[] list;
    static List<Integer>[][] map;
    static int[] find;
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        find = new int[M];
        map = new ArrayList[N][N];

        // 지도를 그리지 않고,
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                // 지도 위치와 값을 넣어준다.
                map[i][j] = new ArrayList<>();
                map[i][j].add(Integer.parseInt(st.nextToken()));
            }
        }

        // 찾을 값을 저장
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            find[i] = Integer.parseInt(st.nextToken());
        }

        // 그러면, 반복을 돌면서 위치한 숫자가 있는 곳을 탐색
        for (int target : find) {
            boolean moved = false;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    // 값을 포함하고 있다면, 현재 위치에서 제일 큰 값 탐색
                    if (!moved && map[i][j].contains(target)) {
                        int max = Integer.MIN_VALUE;
                        int moveR = 0, moveC = 0;
                        for (int k = 0; k < 8; k++) {
                            int nr = i + dr[k];
                            int nc = j + dc[k];
                            if (inRange(nr, nc) && !map[nr][nc].isEmpty()) {
                                int curr = map[nr][nc].get(0);
                                if (curr > max) {
                                    max = curr;
                                    moveR = nr;
                                    moveC = nc;
                                }
                            }
                        }

                        // 값이 있으면 움직임, 탐색 인덱스 기준으로 위의 값들은 전부 다 옮겨짐
                        if (max != Integer.MIN_VALUE) {
                            int w = 0;
                            for (int x = map[i][j].size()-1; x >= 0; x--) {
                                if (map[i][j].get(x) != target)
                                    w++;
                                else
                                    break;
                            }

                            Stack<Integer> stack = new Stack<>();

                            int idx = 0;
                            while(idx <= w) {
                                int a = map[i][j].remove(map[i][j].size() - 1);
                                stack.push(a);
                                idx++;
                            }

                            while(!stack.isEmpty()) {
                                map[moveR][moveC].add(stack.pop());
                            }

                            moved = true;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(map[i][j].isEmpty()) System.out.print("None");
                else {
                    for (int k = map[i][j].size()-1; k >= 0; k--) {
                        System.out.print(map[i][j].get(k) + " ");
                    }
                }
                System.out.println();
            }
        }


    }

    public static boolean inRange(int r, int c) {
        return r >= 0 && r < N && c >= 0 && c < N;
    }
}
