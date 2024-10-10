#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int start, end;
    // 두 정수 x와 y를 입력받습니다.
    cin >> start >> end;

    // 만약 start가 end보다 크다면, 두 값을 교환합니다.
    // 이렇게 하면 항상 start가 더 작거나 같게 됩니다.
    if (start > end) {
        swap(start, end);
    }

    int sum = 0; // 5의 배수를 제외한 수들의 합을 저장할 변수입니다.
    int count = 0; // 5의 배수를 제외한 수들의 개수를 저장할 변수입니다.

    // start부터 end까지의 모든 수를 확인합니다.
    for (int i = start; i <= end; i++) {
        // 현재 수가 5의 배수가 아니라면
        if (i % 5 != 0) {
            sum += i; // 합에 더해줍니다.
            count++; // 개수를 증가시킵니다.
        }
    }

    // 소수점 첫 번째 자리까지 반올림하여 출력하기 위해 설정합니다.
    cout << fixed << setprecision(1);
    // 합과 평균을 출력합니다.
    cout << sum << " " << static_cast<double>(sum) / count;

    return 0;
}