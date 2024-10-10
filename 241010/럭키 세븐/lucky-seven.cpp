#include <iostream>
#include <iomanip> // 소수점 출력을 위한 라이브러리입니다.
using namespace std;

int main() {
    int numCount; // 입력받을 정수의 개수를 저장할 변수입니다.
    cin >> numCount; // 정수의 개수를 입력받습니다.
    
    int numbers[101]; // 최대 100개의 정수를 저장할 배열입니다.
    for(int i = 0; i < numCount; i++) {
        cin >> numbers[i]; // 각 정수를 입력받아 배열에 저장합니다.
    }

    int sumOfMultiples = 0; // 7의 배수의 합을 저장할 변수입니다.
    int countOfMultiples = 0; // 7의 배수의 개수를 저장할 변수입니다.

    // 모든 정수를 순회하며 7의 배수를 찾습니다.
    for(int i = 0; i < numCount; i++) {
        if(numbers[i] % 7 == 0) { // 7의 배수인지 확인합니다.
            countOfMultiples++; // 7의 배수의 개수를 증가시킵니다.
            sumOfMultiples += numbers[i]; // 7의 배수의 합을 증가시킵니다.
        }
    }

    // 7의 배수의 평균을 계산합니다.
    double averageOfMultiples = static_cast<double>(sumOfMultiples) / countOfMultiples;

    // 소수 첫째 자리까지 출력하기 위해 fixed와 setprecision을 사용합니다.
    cout << fixed << setprecision(1);
    // 7의 배수의 개수, 합, 평균을 출력합니다.
    cout << countOfMultiples << " " << sumOfMultiples << " " << averageOfMultiples;

    return 0; // 프로그램을 종료합니다.
}