import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    private static final Scanner sc = new Scanner(System.in);

    private static int n, m, answer = Integer.MAX_VALUE;
    private static final Steps steps = new Steps(new ArrayList<>());
    private static List<Integer> expected;

    public static void main(String[] args) {
        n = sc.nextInt();
        m = sc.nextInt();

        for (int i = 0; i < m; i++) {
            int lineNumber = sc.nextInt();
            int height = sc.nextInt();

            Step step = new Step(lineNumber, height);
            steps.add(step);
        }

        expected = playLadder(steps);

        recursive(0, new ArrayList<>());

        System.out.println(answer);
    }

    private static List<Integer> playLadder(Steps steps) {
        List<Integer> result = new ArrayList<>();
        for (int position = 1; position <= n; position++) {
            int resultPosition = steps.play(position);
            result.add(resultPosition);
        }
        return result;
    }

    private static void recursive(int index, List<Step> chooseSteps) {
        if (index >= steps.size()) {
            Steps my_steps = new Steps(chooseSteps);
            List<Integer> result = playLadder(my_steps);

            for (int i = 0; i < result.size(); i++) {
                if (expected.get(i) != result.get(i)) {
                    return;
                }
            }

            answer = Math.min(answer, chooseSteps.size());

            return;
        }

        // 골랐을 때
        Step step = steps.get(index);
        chooseSteps.add(step);

        recursive(index + 1, chooseSteps);

        chooseSteps.remove(chooseSteps.size() - 1);

        // 고르지 않았을 때
        recursive(index + 1, chooseSteps);
    }
}

class Steps {

    private final List<Step> steps;

    public Steps(List<Step> steps) {
        this.steps = new ArrayList<>(steps);
    }

    public void add(Step step) {
        steps.add(step);
    }

    public int play(int position) {
        int height = 0;
        int maxHeight = calculateMaxHeight();

        while (height <= maxHeight) {
            height++;
            position = move(height, position);
        }
        return position;
    }

    private int calculateMaxHeight() {
        if (steps.isEmpty()) {
            return 0;
        }
        return steps.stream()
                .mapToInt(Step::getHeight)
                .max().getAsInt();
    }

    private int move(int height, int position) {
        Step step = filterSameHeight(height, position);
        if (step.lineNumber == position) {
            return position + 1;
        }
        if (step.lineNumber == position - 1) {
            return position - 1;
        }
        return position;
    }

    private Step filterSameHeight(int height, int position) {
        for(int i = 0; i < steps.size(); i++) {
            if(steps.get(i).height == height && (steps.get(i).lineNumber == position || steps.get(i).lineNumber == position - 1)) {
                return steps.get(i);
            }
        }
        return new Step(-1, -1);
    }

    public int size() {
        return steps.size();
    }

    public Step get(int index) {
        return steps.get(index);
    }
}

class Step {

    int lineNumber;
    int height;

    public Step(int lineNumber, int height) {
        this.lineNumber = lineNumber;
        this.height = height;
    }

    public int getHeight() {
        return height;
    }
}