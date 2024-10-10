#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int numCount;
    cin >> numCount;

    // 입력받은 숫자들을 저장할 벡터를 선언합니다.
    vector<int> numbers(numCount);
    for (int i = 0; i < numCount; i++) {
        cin >> numbers[i];
    }

    // 100에 가장 가까운 수를 저장할 변수를 초기화합니다.
    int closestToHundred = numbers[0];
    // 100 이상의 수 중 가장 작은 수를 저장할 변수를 초기화합니다.
    // 초기값은 -1로 설정하여 조건을 만족하는 수가 없을 경우를 대비합니다.
    int smallestAboveHundred = -1;

    // 모든 숫자를 순회하며 조건에 맞는 값을 찾습니다.
    for (int i = 0; i < numCount; i++) {
        // 현재 숫자가 100에 더 가까운지 혹은 같은 거리일 때 더 작은지 확인합니다.
        if (abs(numbers[i] - 100) < abs(closestToHundred - 100) || 
            (abs(numbers[i] - 100) == abs(closestToHundred - 100) && numbers[i] < closestToHundred)) {
            closestToHundred = numbers[i];
        }
        // 현재 숫자가 100 이상이고, 가장 작은 100 이상의 수인지 확인합니다.
        if (numbers[i] >= 100 && (smallestAboveHundred == -1 || numbers[i] < smallestAboveHundred)) {
            smallestAboveHundred = numbers[i];
        }
    }

    // 결과를 출력합니다.
    cout << closestToHundred << " " << smallestAboveHundred;
}