#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 최대 홀수 개수를 저장할 변수입니다.
int max_odd_count = -1;
// 최소 홀수 개수를 저장할 변수입니다.
int min_odd_count = 1e9;

// 주어진 숫자에서 홀수의 개수를 세는 함수입니다.
int count_odds(int number) {
    int odd_count = 0;
    // 숫자의 각 자릿수를 확인합니다.
    while (number > 0) {
        int digit = number % 10;
        // 자릿수가 홀수인 경우 개수를 증가시킵니다.
        if (digit % 2 == 1) odd_count++;
        number /= 10;
    }
    return odd_count;
}

// 주어진 숫자를 분할하여 홀수 개수를 찾는 함수입니다.
void find_odd_counts(int current_number, int current_odd_count) {
    // 숫자가 한 자리 수일 때
    if (current_number < 10) {
        // 현재까지의 홀수 개수와 비교하여 최대, 최소 값을 갱신합니다.
        max_odd_count = max(current_odd_count, max_odd_count);
        min_odd_count = min(current_odd_count, min_odd_count);
        return;
    } 
    // 숫자가 두 자리 수일 때
    else if (current_number < 100) {
        // 두 자리 수를 두 개의 숫자로 나누어 합을 구합니다.
        int new_number = current_number / 10 + current_number % 10;
        // 새로운 숫자에서 홀수 개수를 세고 재귀 호출합니다.
        find_odd_counts(new_number, current_odd_count + count_odds(new_number));
    } 
    // 숫자가 세 자리 수 이상일 때
    else {
        string number_str = to_string(current_number);
        int length = number_str.length();
        // 숫자를 세 부분으로 나누어 합을 구합니다.
        for (int i = 1; i < length - 1; i++) {
            for (int j = i + 1; j < length; j++) {
                string part1 = number_str.substr(0, i);
                string part2 = number_str.substr(i, j - i);
                string part3 = number_str.substr(j, length - j);
                int new_number = stoi(part1) + stoi(part2) + stoi(part3);
                // 새로운 숫자에서 홀수 개수를 세고 재귀 호출합니다.
                find_odd_counts(new_number, current_odd_count + count_odds(new_number));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int input_number;
    // 입력을 받습니다.
    cin >> input_number;
    // 초기 홀수 개수를 세고 재귀 호출을 시작합니다.
    find_odd_counts(input_number, count_odds(input_number));
    // 결과를 출력합니다.
    cout << min_odd_count << " " << max_odd_count << "\n";
}