#include <iostream>

using namespace std;

// 주사위를 던지는 횟수와 모드를 저장할 변수
int numRolls, mode;
// 주사위 결과를 저장할 배열
int diceRolls[1000];

// 모든 경우의 수를 생성하는 함수
void generateAllCombinations(int level) {
    // 주사위를 모두 던졌을 때 결과를 출력합니다.
    if (level == numRolls) {
        for (int i = 0; i < numRolls; i++) {
            cout << diceRolls[i] << " ";
        }
        cout << "\n";
    } else {
        // 주사위의 각 면(1~6)을 시도합니다.
        for (int i = 1; i <= 6; i++) {
            diceRolls[level] = i; // 현재 레벨에 주사위 결과 저장
            generateAllCombinations(level + 1); // 다음 레벨로 이동
        }
    }
}

// 중복을 배제한 경우의 수를 생성하는 함수
void generateUniqueCombinations(int start, int level) {
    // 주사위를 모두 던졌을 때 결과를 출력합니다.
    if (level == numRolls) {
        for (int i = 0; i < numRolls; i++) {
            cout << diceRolls[i] << " ";
        }
        cout << "\n";
    } else {
        // 시작점부터 주사위의 각 면을 시도합니다.
        for (int i = start; i <= 6; i++) {
            diceRolls[level] = i; // 현재 레벨에 주사위 결과 저장
            generateUniqueCombinations(i, level + 1); // 다음 레벨로 이동
        }
    }
}

// 중복된 눈이 나오지 않는 경우의 수를 생성하는 함수
void generateNonRepeatingCombinations(int level, int usedMask) {
    // 주사위를 모두 던졌을 때 결과를 출력합니다.
    if (level == numRolls) {
        for (int i = 0; i < numRolls; i++) {
            cout << diceRolls[i] << " ";
        }
        cout << "\n";
    } else {
        // 주사위의 각 면(1~6)을 시도합니다.
        for (int i = 1; i <= 6; i++) {
            // 이미 사용된 눈은 건너뜁니다.
            if ((usedMask & (1 << i)) == 0) {
                diceRolls[level] = i; // 현재 레벨에 주사위 결과 저장
                generateNonRepeatingCombinations(level + 1, usedMask | (1 << i)); // 다음 레벨로 이동
            }
        }
    }
}

int main() {
    // 입력을 받습니다.
    cin >> numRolls >> mode;

    // 모드에 따라 다른 함수를 호출합니다.
    if (mode == 1) {
        generateAllCombinations(0);
    } else if (mode == 2) {
        generateUniqueCombinations(1, 0);
    } else if (mode == 3) {
        generateNonRepeatingCombinations(0, 0);
    }

    return 0;
}