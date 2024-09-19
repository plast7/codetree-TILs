#include <iostream>

using namespace std;

// 빙고판을 저장할 2차원 배열
int bingoBoard[5][5];
// 각 숫자의 위치를 저장할 배열
pair<int, int> numberPosition[26];

// 빙고가 3개 이상인지 확인하는 함수
bool checkBingo() {
    int bingoCount = 0;
    int diagonal1 = 0;
    int diagonal2 = 0;

    // 각 행과 열을 검사합니다.
    for (int i = 0; i < 5; i++) {
        int rowCount = 0;
        int colCount = 0;
        for (int j = 0; j < 5; j++) {
            // 행 검사
            if (bingoBoard[i][j] == 0) {
                rowCount++;
            }
            // 열 검사
            if (bingoBoard[j][i] == 0) {
                colCount++;
            }
        }
        // 행이 빙고인 경우
        if (rowCount == 5) {
            bingoCount++;
        }
        // 열이 빙고인 경우
        if (colCount == 5) {
            bingoCount++;
        }
        // 대각선 검사
        if (bingoBoard[i][i] == 0) {
            diagonal1++;
        }
        if (bingoBoard[i][4 - i] == 0) {
            diagonal2++;
        }
    }
    // 대각선이 빙고인 경우
    if (diagonal1 == 5) {
        bingoCount++;
    }
    if (diagonal2 == 5) {
        bingoCount++;
    }
    // 빙고가 3개 이상인지 반환합니다.
    return bingoCount >= 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 빙고판 입력을 받습니다.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> bingoBoard[i][j];
            // 각 숫자의 위치를 저장합니다.
            numberPosition[bingoBoard[i][j]] = {i, j};
        }
    }

    int callOrder = 0;
    // 사회자가 부르는 숫자를 입력받습니다.
    for (int i = 0; i < 25; i++) {
        callOrder++;
        int calledNumber;
        cin >> calledNumber;
        // 부른 숫자를 빙고판에서 지웁니다.
        bingoBoard[numberPosition[calledNumber].first][numberPosition[calledNumber].second] = 0;
        // 12번째 숫자부터 빙고를 검사합니다.
        if (callOrder >= 12 && checkBingo()) {
            cout << callOrder;
            return 0;
        }
    }

    return 0;
}