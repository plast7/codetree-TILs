import java.util.*;

public class Main {
    static class Interval implements Comparable<Interval> {
        int start, end;
        public Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }
        @Override
        public int compareTo(Interval other) {
            return this.start - other.start;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCommands = sc.nextInt();

        // 명령어를 저장할 리스트
        List<Interval> intervals = new ArrayList<>();
        int currentPosition = 0;

        // 명령어를 입력받아 intervals 리스트에 저장합니다.
        for (int i = 0; i < numCommands; ++i) {
            int steps = sc.nextInt();
            char direction = sc.next().charAt(0);

            if (direction == 'R') {
                int newPosition = currentPosition + steps;
                intervals.add(new Interval(currentPosition, newPosition));
                currentPosition = newPosition;
            } else {
                int newPosition = currentPosition - steps;
                intervals.add(new Interval(newPosition, currentPosition));
                currentPosition = newPosition;
            }
        }

        // intervals 리스트를 정렬합니다.
        Collections.sort(intervals);

        // 구간의 시작과 끝을 기록할 맵
        TreeMap<Integer, Integer> pointCount = new TreeMap<>();

        // 각 구간의 시작과 끝을 맵에 기록합니다.
        for (Interval interval : intervals) {
            pointCount.put(interval.start, pointCount.getOrDefault(interval.start, 0) + 1);
            pointCount.put(interval.end, pointCount.getOrDefault(interval.end, 0) - 1);
        }

        int overlappedLength = 0;
        int currentOverlap = 0;
        int lastPoint = pointCount.firstKey();

        // 맵을 순회하며 2번 이상 지나간 구간의 길이를 계산합니다.
        for (Map.Entry<Integer, Integer> point : pointCount.entrySet()) {
            if (currentOverlap >= 2) {
                overlappedLength += point.getKey() - lastPoint;
            }
            currentOverlap += point.getValue();
            lastPoint = point.getKey();
        }

        System.out.println(overlappedLength);
    }
}