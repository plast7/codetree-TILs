import java.io.*;
import java.util.*;

public class Main {
	
	static Giant[] giants;
	static int[][] visited;
	static int R, C, K, totalScore = 0;
	static int[] clock = {1, 2, 3, 0}, reclock = {3, 0, 1, 2};
	static int[] nextDir = {2, 3, 1};
	// 북, 동, 남, 서
	static int[] dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};
	
	static class Pos {
		int r, c;
		public Pos(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}
	
	static class Giant extends Pos{
		int dir;
		public Giant(int r, int c, int dir) {
			super(r, c);
			this.dir = dir;
		}
	}

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		giants = new Giant[K+1];
		visited = new int[R+1][C+1]; // 이게 곧 숲임.
		
		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			int c = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			
			giants[i+1] = new Giant(0, c, d);
		}

		int si = 0;
		for (int i = 1; i <= K; i++) {
			// 행 총합 구하고, 숲 비우기
			if(!isMovLoc(i))
				visited = new int[R+1][C+1];
			
		}
		
		
		System.out.println(totalScore);
	}
	
	private static boolean isMovLoc(int giantIdx) {
		boolean isFirstIter = true;
//		System.out.println(giantIdx);
		
		// 여기 로직 문제
		// 계속해서 isMovLoc가 돌면서, 남, 서, 동을 확인하고 아무 방향도 진행하지 못한 경우에는 탈출
		
		while(true) {
			
			boolean isNextIter = false;
			// 여기 반복문 안에서 남, 서, 동 확인
			for (int i = 0; i < 3; i++) {
				int nDir = nextDir[i];
				
				if(isEmptyLoc(nDir, giantIdx)) {
					// 여기 들어왔다는 것 자체가 한번 이동했다는 것임
					// 이동했다면, 다시 남쪽부터 탐색 되어야 함.
					isFirstIter = false;
					isNextIter = true;
					break;
				}
			}
			
			// 남, 서, 동 모두 이동할 수 없는 상황
			if(!isNextIter) break; 
		}
		
		// 만일 여기 까지 내려온다면 숲에 들어오고 난 뒤 부터 움직이지 못한거임 => false 반환해서 숲 비우기 실행
		if(isFirstIter || giants[giantIdx].r==1) return false;
		
		// 여기서 골렘의 위치가 고정된다.
		checkVisited(giantIdx);
		// 골렘 위치 고정 후 visited 를 통해 정령이 가장 남쪽으로 이동한 경우를 검색
		
		totalScore += bfs(giantIdx);
		
		return true;
	}
	
	private static int bfs(int giantIdx) {
		
		int gr = giants[giantIdx].r, gc = giants[giantIdx].c;
		boolean[][] tmpVisited = new boolean[R+1][C+1];
		
		ArrayDeque<Pos> q = new ArrayDeque<>();
		q.offer(new Pos(gr, gc));
		tmpVisited[gr][gc] = true;
		
		int maxR = 0;
		
		while(!q.isEmpty()) {
			Pos p = q.poll();
			int r = p.r, c = p.c;

			// 갱신
			maxR = Math.max(maxR, r);
			
			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				
				if(nr<=R && nc<=C && nr>0 && nc>0) {
					if(visited[nr][nc]!=0 && !tmpVisited[nr][nc]) {
						// 만일 이전과 다른 골렘이라면 해당 위치가 출구여야 함.
						if(visited[nr][nc]==visited[r][c]) {
							tmpVisited[nr][nc] = true;
							q.offer(new Pos(nr, nc));
						} else {
							int curGiantIdx = visited[r][c];
							// 여기가 이 골렘의 출구니?
							if(giants[curGiantIdx].r + dr[giants[curGiantIdx].dir]==r && giants[curGiantIdx].c + dc[giants[curGiantIdx].dir]==c) {
								tmpVisited[nr][nc] = true;
								q.offer(new Pos(nr, nc));
							}
						}
					}
				}
			}
		}
		
		return maxR;
	}

	private static void checkVisited(int giantIdx) {
		int r = giants[giantIdx].r, c = giants[giantIdx].c;
		
		visited[r][c] = giantIdx;
		for (int d = 0; d < 4; d++)
			visited[r+dr[d]][c+dc[d]] = giantIdx;
	}

	private static boolean isEmptyLoc(int dir, int giantIdx) {
		
		Giant giant = giants[giantIdx];
		int gr = giant.r, gc = giant.c, gdir = giant.dir;
		
		// 향하는 방향에 칸이 비어있는지 확인하기
		if(dir==1) { // 동쪽 회전 시계
			if(gc+2<=C && gr-1>=0 && gr+2<=R) {
				if(visited[gr][gc+2]==0 && visited[gr-1][gc+1]==0 && visited[gr+1][gc+1]==0 && visited[gr+2][gc+1]==0 && visited[gr+1][gc+2]==0) {
					
					// giant 정보 갱신
					giants[giantIdx].r = gr+1;
					giants[giantIdx].c = gc+1;
					giants[giantIdx].dir = clock[gdir];
					
					return true;
				}
			}
			
		} else if(dir==2) {
			if(gr+2<=R && gc+1<=C && gc-1>0) {
				if(visited[gr+2][gc]==0 && visited[gr+1][gc+1]==0 && visited[gr+1][gc-1]==0) {
					
					// giant 정보 갱신
					giants[giantIdx].r = gr+1;
					giants[giantIdx].c = gc;
					giants[giantIdx].dir = gdir;
					
					return true;
				}
			}
			
		} else if(dir==3) { // 서쪽 회전
			if(gc-2>0 && gr+2<=R && gr-1>=0) {
				if(visited[gr][gc-2]==0 && visited[gr-1][gc-1]==0 && visited[gr+1][gc-1]==0 && visited[gr+2][gc-1]==0 && visited[gr+1][gc-2]==0) {
					
					// giant 정보 갱신
					giants[giantIdx].r = gr+1;
					giants[giantIdx].c = gc-1;
					giants[giantIdx].dir = reclock[gdir];
					
					return true;
				}
			}
		}
		return false;
	}
	
}