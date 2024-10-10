#include <iostream>
using namespace std;

int main() {
    int score;
    cin >> score; // 점수를 입력받습니다.

    // 점수가 90 이상이면 통과입니다.
    if(score >= 90) {
        cout << "passed"; // "passed"를 출력합니다.
    } else {
        // 점수가 90 미만이면 몇 점이 더 필요한지 계산합니다.
        cout << "need " << 90 - score << " more score"; // 필요한 점수를 출력합니다.
    }
}