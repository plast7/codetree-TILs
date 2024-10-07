#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

// 최대 N의 크기를 정의합니다.
#define MAXN 20000

// 초기 배열을 저장할 배열을 선언합니다.
int originalArray[MAXN];

// 각 숫자의 위치를 저장할 맵을 선언합니다.
// 각 자리 이동 후의 배열에서 숫자의 위치를 기록합니다.
map<int, int> positionMap[5];

// 두 숫자를 비교하는 함수입니다.
// num1이 num2보다 더 앞에 있어야 하는지를 판단합니다.
bool compare(int num1, int num2) {
    // num1이 num2보다 앞에 있는 경우의 수를 셉니다.
    int count = 0;
    // 5번의 자리 이동 후 배열을 모두 확인합니다.
    for(int i = 0; i < 5; i++) {
        // num1이 num2보다 앞에 있는 경우 count를 증가시킵니다.
        count += positionMap[i][num1] < positionMap[i][num2];
    }
    // num1이 num2보다 앞에 있는 경우가 3번 이상이면 true를 반환합니다.
    return count > 2;
}

int main() {
    // 숫자의 개수를 입력받습니다.
    int numCount;
    cin >> numCount;

    // 5번의 자리 이동 후 배열을 입력받습니다.
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < numCount; j++) {
            int number;
            cin >> number;
            // 각 숫자의 위치를 기록합니다.
            positionMap[i][number] = j;
            // 초기 배열에 숫자를 저장합니다.
            originalArray[j] = number;
        }
    }

    // compare 함수를 이용하여 originalArray를 정렬합니다.
    sort(originalArray, originalArray + numCount, compare);

    // 정렬된 배열을 출력합니다.
    for(int i = 0; i < numCount; i++) {
        cout << originalArray[i] << '\n';
    }
}