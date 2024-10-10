#include <iostream>
#include <vector>

using namespace std;

// 주사위를 던지는 횟수를 저장하는 변수입니다.
int numberOfRolls;
// 현재 조합을 저장하는 벡터입니다.
vector<int> currentCombination;

// 주사위를 던져서 나올 수 있는 모든 경우의 수를 생성하는 함수입니다.
void generateCombinations(int rollIndex) {
    // 주사위를 모두 던진 경우, 현재 조합을 출력합니다.
    if (rollIndex == numberOfRolls) {
        // 현재 조합을 출력합니다.
        for (int i = 0; i < numberOfRolls - 1; i++) {
            cout << currentCombination[i] << "-";
        }
        // 마지막 숫자는 '-' 없이 출력합니다.
        cout << currentCombination[numberOfRolls - 1] << endl;
        return;
    }

    // 주사위의 눈은 1부터 시작합니다.
    int startValue = 1;
    // 중복을 피하기 위해 이전 주사위의 값보다 크거나 같은 값부터 시작합니다.
    if (rollIndex >= 1) {
        startValue = currentCombination[rollIndex - 1];
    }
    // 주사위의 눈은 1부터 6까지 가능합니다.
    for (int i = startValue; i <= 6; i++) {
        // 현재 주사위의 눈을 조합에 추가합니다.
        currentCombination.push_back(i);
        // 다음 주사위를 던집니다.
        generateCombinations(rollIndex + 1);
        // 현재 주사위의 눈을 조합에서 제거합니다.
        currentCombination.pop_back();
    }
}

int main() {
    // 주사위를 던지는 횟수를 입력받습니다.
    cin >> numberOfRolls;
    // 주사위를 던져서 나올 수 있는 모든 경우의 수를 생성합니다.
    generateCombinations(0);
    return 0;
}