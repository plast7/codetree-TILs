#include <iostream>
using namespace std;

int main() {
    int gender, age;
    // 성별과 나이를 입력받습니다.
    cin >> gender >> age;

    // 성별이 남자인 경우
    if (gender == 0) {
        // 나이가 19세 이상인 경우 성인 남자이므로 'M'을 출력합니다.
        if (age >= 19)
            cout << "M";
        // 나이가 19세 미만인 경우 미성년 남자이므로 'B'를 출력합니다.
        else
            cout << "B";
    } 
    // 성별이 여자인 경우
    else {
        // 나이가 19세 이상인 경우 성인 여자이므로 'W'를 출력합니다.
        if (age >= 19)
            cout << "W";
        // 나이가 19세 미만인 경우 미성년 여자이므로 'G'를 출력합니다.
        else
            cout << "G";
    }

    return 0;
}