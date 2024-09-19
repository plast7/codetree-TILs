#include <iostream>

using namespace std;

int main() {

    // 입출력 속도를 높이기 위해 사용합니다.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 총 숫자의 개수와 부분 배열의 크기를 입력받습니다.
    int totalNumbers, subarraySize;
    cin >> totalNumbers >> subarraySize;

    // 현재 부분 배열의 합을 저장할 변수를 초기화합니다.
    int currentSum = 0;
    // 숫자들을 저장할 배열을 선언합니다.
    int numbers[100000];

    // 첫 번째 부분 배열의 합을 계산합니다.
    for (int i = 0; i < subarraySize; i++) {
        cin >> numbers[i];
        currentSum += numbers[i];
    }

    // 최대 합과 그 최대 합을 갖는 구간의 개수를 초기화합니다.
    int maxSum = currentSum;
    int maxCount = 1;

    // 슬라이딩 윈도우 기법을 사용하여 부분 배열의 합을 계산합니다.
    for (int i = subarraySize; i < totalNumbers; i++) {
        cin >> numbers[i];
        // 새로운 숫자를 더하고, 가장 오래된 숫자를 뺍니다.
        currentSum += numbers[i] - numbers[i - subarraySize];
        // 현재 부분 배열의 합이 최대 합과 같거나 크다면
        if (currentSum >= maxSum) {
            // 현재 합이 최대 합과 같다면 구간의 개수를 증가시킵니다.
            if (currentSum == maxSum) {
                maxCount++;
            } 
            // 현재 합이 더 크다면 최대 합을 갱신하고 구간의 개수를 1로 초기화합니다.
            else {
                maxSum = currentSum;
                maxCount = 1;
            }
        }
    }

    // 최대 합이 0이라면 0만 출력합니다.
    if (maxSum == 0) {
        cout << "0";
    } 
    // 최대 합이 0이 아니라면 최대 합과 구간의 개수를 출력합니다.
    else {
        cout << maxSum << '\n' << maxCount;
    }

    return 0;
}