#include <iostream>

using namespace std;

// 각 줄의 문자들을 저장하는 배열입니다.
char a[5][16];

int main(){
    // 4개의 문자열을 입력받습니다.
    for(int i = 0; i < 4; i++)
        cin >> a[i];
    
    // 각 열에 대해 수행합니다.
    for(int j = 0; j < 15; j++)
    {
        // 각 행의 문자를 순서대로 출력합니다.
        for(int i = 0; i < 4; i++)
        {
            // 해당 위치에 문자가 있다면 출력합니다.
            if(a[i][j] != '\0')
                cout << a[i][j];
        }
    }

    return 0;
}