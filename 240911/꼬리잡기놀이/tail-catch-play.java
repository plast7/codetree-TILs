package codetree.삼성2024하반기;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

/**
 * 삼성 SW 역량테스트 2022 상반기 오후 1번 문제
 * 골드 1
 */
public class Main {

    static int N, M, K, ROUND, ANS;
    static int[] DX = {-1, 0, 1, 0};
    static int[] DY = {0, 1, 0, -1};
    static int[][] MAP;
    static boolean[][] VISITED;
    static List<TeamInfo> TEAMS = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        ROUND = 1;
        MAP = new int[N][N];
        VISITED = new boolean[N][N];
        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<N; j++)
                MAP[i][j] = Integer.parseInt(st.nextToken());
        }

        simulate();
        System.out.println(ANS);
    }

    public static void simulate(){
        initTeam();
        for(int k=0; k<K; k++){
            simulateMove();
            simulateBall();
            ROUND += 1;
            if(ROUND > 4 * N)
                ROUND = 1;
        }
    }

    public static void initTeam(){
        int cnt = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(MAP[i][j] == 1 && !VISITED[i][j]){
                    TEAMS.add(new TeamInfo());
                    dfs(i, j, cnt);
                    cnt += 1;
                }
            }
        }
    }

    public static void dfs(int x, int y, int cnt){
        if(VISITED[x][y] || MAP[x][y] == 4) return;
        VISITED[x][y] = true;
        TEAMS.get(cnt).players.add(new PlayerInfo(x, y, MAP[x][y]));
        for(int i=0; i<4; i++){
            int nx = x + DX[i];
            int ny = y + DY[i];
            if (canGo(nx, ny) && MAP[nx][ny] - MAP[x][y] <= 1 && MAP[nx][ny] != 4 && MAP[nx][ny] != 0 && !VISITED[nx][ny])
                dfs(nx, ny, cnt);
        }
    }

    public static void simulateMove(){
        for(TeamInfo t : TEAMS){
            List<PlayerInfo> players = t.players;
            boolean connected = true;
            for(int i=0; i<4; i++){
                int nx = players.get(0).x + DX[i];
                int ny = players.get(0).y + DY[i];
                if(canGo(nx, ny) && MAP[nx][ny] == 4)
                    connected = false;
            }
            if(connected){
                boolean[][] toGo = new boolean[N][N];
                for(int i=0; i<4; i++){
                    int nx = players.get(0).x + DX[i];
                    int ny = players.get(0).y + DY[i];
                    if(canGo(nx, ny) && MAP[nx][ny] == 3)
                        toGo[nx][ny] = true;
                }
                for(PlayerInfo p : players){
                    for(int i=0; i<4; i++){
                        int nx = p.x + DX[i];
                        int ny = p.y + DY[i];
                        if(canGo(nx, ny) && toGo[nx][ny]){
                            toGo[nx][ny] = false;
                            toGo[p.x][p.y] = true;
                            p.x = nx;
                            p.y = ny;
                            MAP[p.x][p.y] = p.no;
                            break;
                        }
                    }
                }
            }else {
                for(PlayerInfo p : players){
                    for(int i=0; i<4; i++){
                        int nx = p.x + DX[i];
                        int ny = p.y + DY[i];
                        if(canGo(nx, ny) && MAP[nx][ny] == 4){
                            MAP[nx][ny] = p.no;
                            MAP[p.x][p.y] = 4;
                            p.x = nx;
                            p.y = ny;
                            break;
                        }
                    }
                }
            }
        }
    }

    public static void simulateBall(){
        if(ROUND >= 1 && ROUND <= N){
            for(int i=0; i<N; i++)
                if(MAP[ROUND - 1][i] >= 1 && MAP[ROUND - 1][i] <= 3)
                    if(ballHit(ROUND - 1, i)) return;
        }else if(ROUND > N && ROUND <= 2 * N){
            for(int i=N-1; i>=0; i--)
                if(MAP[i][ROUND - N - 1] >= 1 && MAP[i][ROUND - N - 1] <= 3)
                    if(ballHit(i, ROUND - N - 1)) return;
        }else if(ROUND > 2 * N && ROUND <= 3 * N){
            for(int i=N-1; i>=0; i--)
                if(MAP[N - (ROUND - 2 * N)][i] >= 1 && MAP[N - (ROUND - 2 * N)][i] <= 3)
                    if(ballHit(N - (ROUND - 2 * N), i)) return;
        }else if(ROUND > 3 * N && ROUND <= 4 * N){
            for(int i=0; i<N; i++)
                if(MAP[i][N - (ROUND - 3 * N)] >= 1 && MAP[i][N - (ROUND - 3 * N)] <= 3)
                    if(ballHit(i, N - (ROUND - 3 * N))) return;
        }
    }

    public static boolean ballHit(int tx, int ty){
        for(TeamInfo t : TEAMS){
            List<PlayerInfo> players = t.players;
            for(int i=0; i<players.size(); i++){
                int x = players.get(i).x;
                int y = players.get(i).y;
                if(x == tx && y ==ty){
                    ANS += (i + 1) * (i + 1);
                    t.reverse();
                    MAP[players.get(0).x][players.get(0).y] = 1;
                    MAP[players.get(players.size() - 1).x][players.get(players.size() - 1).y] = 3;
                    return true;
                }
            }
        }
        return false;
    }

    public static boolean canGo(int nx, int ny){
        return nx >= 0 && nx < N && ny >= 0 && ny < N;
    }
}

class PlayerInfo{
    public PlayerInfo(int x, int y, int no){
        this.x = x;
        this.y = y;
        this.no = no;
    }
    int x;
    int y;
    int no;
}

class TeamInfo{

    List<PlayerInfo> players = new ArrayList<>();

    public void reverse(){
        Collections.reverse(players);
        players.get(0).no = 1;
        players.get(players.size() - 1).no = 3; // reverse 할 때 MAP 최신화 필요
    }
}