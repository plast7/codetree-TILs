#include <iostream>

using namespace std;

// 점수대별 학생 수를 저장할 배열을 초기화합니다.
// 0부터 10까지의 인덱스를 사용하므로 크기는 11로 설정합니다.
int scoreCount[11];

int main() {
    int numberOfStudents;
    // 학생 수를 입력받습니다.
    cin >> numberOfStudents;

    // 각 학생의 점수를 입력받고, 해당 점수대의 학생 수를 증가시킵니다.
    for (int i = 0; i < numberOfStudents; i++) {
        int score;
        cin >> score;
        // 점수를 10으로 나눈 몫을 인덱스로 사용하여 해당 점수대의 학생 수를 증가시킵니다.
        scoreCount[score / 10]++;
    }

    // 점수대별 학생 수를 높은 점수대부터 출력합니다.
    for (int i = 10; i >= 1; i--) {
        // 해당 점수대에 학생이 있는 경우에만 출력합니다.
        if (scoreCount[i] > 0) {
            // i * 10은 점수대를 의미하며, scoreCount[i]는 해당 점수대의 학생 수를 의미합니다.
            cout << i * 10 << " - " << scoreCount[i] << endl;
        }
    }

    return 0;
}