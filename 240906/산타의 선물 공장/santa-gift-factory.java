import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static final int MAX_M = 10;

    public static Scanner sc;

    public static int n, m, q;
    
    // 각 id별로 상자 무게를 저장합니다.
    public static HashMap<Integer, Integer> weight = new HashMap<>();
    
    // id에 해당하는 상자의 nxt값과 prv값을 관리합니다.
    // 0이면 없다는 뜻입니다.
    public static HashMap<Integer, Integer> prv = new HashMap<>();
    public static HashMap<Integer, Integer> nxt = new HashMap<>();
    
    // 각 벨트별로 head, tail id를 관리합니다.
    // 0이면 없다는 뜻입니다.
    public static int[] head = new int[MAX_M];
    public static int[] tail = new int[MAX_M];
    
    // 벨트가 망가졌는지를 표시합니다.
    public static boolean[] broken = new boolean[MAX_M];
    
    // 물건 별로 벨트 번호를 기입합니다.
    // 벨트 번호가 0이면 사라진 것입니다.
    public static HashMap<Integer, Integer> beltNum = new HashMap<>();
    
    // 공장 설립
    public static void buildFactory() {
        // 공장 정보를 입력받습니다.
        n = sc.nextInt();
        m = sc.nextInt();
        int[] ids = new int[n];
        int[] ws = new int[n];
        for(int i = 0; i < n; i++)
            ids[i] = sc.nextInt();
        for(int i = 0; i < n; i++)
            ws[i] = sc.nextInt();
    
        // id마다 무게를 관리합니다.
        for(int i = 0; i < n; i++)
            weight.put(ids[i], ws[i]);
        
        // 벨트 별로 상자 목록을 넣어줍니다.
        int size = n / m;
        for(int i = 0; i < m; i++) {
            // head, tail을 설정해줍니다.
            head[i] = ids[i * size];
            tail[i] = ids[(i + 1) * size - 1];
            for(int j = i * size; j < (i + 1) * size; j++) {
                // 상자 ID마다 벨트 번호를 기입합니다.
                beltNum.put(ids[j], i + 1);
    
                // nxt, prv를 설정해줍니다.
                if(j < (i + 1) * size - 1) {
                    nxt.put(ids[j], ids[j + 1]);
                    prv.put(ids[j + 1], ids[j]);
                }
            }
        }
    }
    
    // Id에 해당하는 상자를 삭제합니다.
    public static void removeId(int id, boolean removeBelt) {
        int bNum = beltNum.get(id) - 1;
        // 벨트 번호를 제거해줍니다.
        if(removeBelt)
            beltNum.put(id, 0);
    
        // 하나 남은 원소라면
        // head, tail이 사라지고 끝납니다.
        if(head[bNum] == tail[bNum])
            head[bNum] = tail[bNum] = 0;
    
        // 삭제 되는게 head라면
        // head만 변경되고 끝납니다.
        else if(id == head[bNum]) {
            int nid = nxt.get(id);
            head[bNum] = nid;
            prv.put(nid, 0);
        }
        // 삭제 되는게 tail이라면
        // tail만 변경되고 끝납니다.
        else if(id == tail[bNum]) {
            int pid = prv.get(id);
            tail[bNum] = pid;
            nxt.put(pid, 0);
        }
        // 중간에 있는 id가 삭제되는 것이라면
        // nxt, prv만 수선해줍니다.
        else {
            int pid = prv.get(id), nid = nxt.get(id);
            nxt.put(pid, nid);
            prv.put(nid, pid);
        }
    
        // nxt, prv값을 지워줍니다.
        nxt.put(id, 0);
        prv.put(id, 0);
    }
    
    // targetId 바로 뒤에
    // id를 추가합니다.
    public static void pushId(int targetId, int id) {
        nxt.put(targetId, id);
        prv.put(id, targetId);
    
        // 만약 targetId가 tail이었다면
        // tail을 변경해줍니다.
        int bNum = beltNum.get(targetId) - 1;
        if(tail[bNum] == targetId)
            tail[bNum] = id;
    }
    
    // 물건 하차
    public static void dropOff() {
        int wMax = sc.nextInt();
    
        // 각 벨트마다 보며
        // 첫 번째 상자를 열어봅니다.
        long wSum = 0;
        for(int i = 0; i < m; i++) {
            // 망가진 벨트라면 넘어갑니다.
            if(broken[i])
                continue;
    
            // 벨트의 head를 확인합니다.
            if(head[i] != 0) {
                int id = head[i];
                int w = weight.get(id);
    
                // 가장 앞에 있는 상자의 무게가 wMax 이하라면
                // 하차시키고 답에 더해줍니다.
                if(w <= wMax) {
                    wSum += w;
    
                    // 하차를 진행합니다.
                    removeId(id, true);
                }
                // 그렇지 않다면
                // 상자를 맨 뒤로 올려줍니다.
                else if(nxt.get(id) != 0) {
                    // 제거해준 뒤
                    removeId(id, false);
                    
                    // 맨 뒤에 push해줍니다.
                    pushId(tail[i], id);
                }
            }
        }
    
        // 하차한 상자의 무게 합을 출력합니다.
        System.out.println(wSum);
    }
    
    // 물건 제거
    public static void remove() {
        int rId = sc.nextInt();
    
        // 이미 삭제된 상자라면
        // -1을 출력하고 패스합니다.
        if(beltNum.getOrDefault(rId, 0) == 0) {
            System.out.println(-1);
            return;
        }
            
        // 해당 상자를 제거합니다.
        removeId(rId, true);
        System.out.println(rId);
    }
    
    // 물건 확인
    public static void find() {
        int fId = sc.nextInt();
    
        // 이미 삭제된 상자라면
        // -1을 출력하고 패스합니다.
        if(beltNum.getOrDefault(fId, 0) == 0) {
            System.out.println(-1);
            return;
        }
    
        // 해당 상자를 찾아
        // 이를 맨 앞으로 당겨줍니다.
        // head가 아닌 경우에만 유효합니다.
        int bNum = beltNum.get(fId) - 1;
        if(head[bNum] != fId) {
            int origTail = tail[bNum];
            int origHead = head[bNum];
    
            // 새로 tail을 갱신해줍니다.
            int nowTail = prv.get(fId);
            tail[bNum] = nowTail;
            nxt.put(nowTail, 0);
    
            // 기존 tail의 nxt를 head로,
            // heda의 prv를 기존 tail로 만들어줍니다.
            nxt.put(origTail, origHead);
            prv.put(origHead, origTail);
    
            // 새로 head를 지정합니다.
            head[bNum] = fId;
        }
    
        // 해당 ID의 belt 번호를 출력합니다.
        System.out.println(bNum + 1);
    }
    
    // 벨트 고장
    public static void brokenBelt() {
        int bNum = sc.nextInt();
    
        bNum--;
        // 이미 망가져 있다면
        // -1을 출력하고 패스합니다.
        if(broken[bNum]) {
            System.out.println(-1);
            return;
        }
    
        broken[bNum] = true;
    
        // 만약 빈 벨트라면 패스합니다.
        if(head[bNum] == 0) {
            System.out.println(bNum + 1);
            return;
        }
    
        // 오른쪽으로 돌면서
        // 아직 망가지지 않은 벨트 위로 상자를 전부 옮겨줍니다.
        int nxtNum = bNum;
        while(true) {
            nxtNum = (nxtNum + 1) % m;
            // 최초로 망가지지 않은 곳이 보이면
            if(!broken[nxtNum]) {
                // 만약 해당 벨트가 비어있다면
                // 그대로 옮겨줍니다.
                if(tail[nxtNum] == 0) {
                    head[nxtNum] = head[bNum];
                    tail[nxtNum] = tail[bNum];
                }
                else {
                    // 해당 위치로 상자를 전부 옮겨줍니다.
                    // head만 tail뒤에 붙여준 뒤
                    pushId(tail[nxtNum], head[bNum]);
                    // tail만 갈아껴주면 됩니다.
                    tail[nxtNum] = tail[bNum];
                }
    
                // head부터 tail까지 보며
                // beltNum을 갱신해줍니다.
                int id = head[bNum];
                while(id != 0) {
                    beltNum.put(id, nxtNum + 1);
                    id = nxt.getOrDefault(id, 0);
                }
    
                head[bNum] = tail[bNum] = 0;
                break;
            }
        }
    
        System.out.println(bNum + 1);
    }

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        // 입력:
        q = sc.nextInt();
        while(q-- > 0) {
            int qType = sc.nextInt();
            if(qType == 100)
                buildFactory();
            else if(qType == 200)
                dropOff();
            else if(qType == 300)
                remove();
            else if(qType == 400)
                find();
            else
                brokenBelt();
        }
    }
}