#include <iostream>
#include <iomanip> // 소수점 출력을 위한 라이브러리입니다.

using namespace std;

int main() {
    int numberOfStudents; // 학생 수를 저장할 변수입니다.
    double scores[21]; // 학생들의 점수를 저장할 배열입니다. 최대 20명이므로 21로 설정합니다.

    // 학생 수를 입력받습니다.
    cin >> numberOfStudents;
    // 각 학생의 점수를 입력받습니다.
    for (int i = 0; i < numberOfStudents; i++) {
        cin >> scores[i];
    }

    double totalScore = 0; // 총점을 저장할 변수입니다.
    // 모든 학생의 점수를 더하여 총점을 계산합니다.
    for (int i = 0; i < numberOfStudents; i++) {
        totalScore += scores[i];
    }

    // 평균을 소수 첫째 자리까지 출력하기 위해 설정합니다.
    cout << fixed << setprecision(1);
    // 평균 점수를 계산하여 출력합니다.
    cout << totalScore / numberOfStudents;

    return 0; // 프로그램이 정상적으로 종료되었음을 알립니다.
}