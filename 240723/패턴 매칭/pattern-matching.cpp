#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int n = a.length(), m = b.length();
    bool is_pos[25][25] = {false}; // 매칭 가능 여부를 저장하는 배열을 초기화합니다.

    // 문자열 a와 b를 비교하여 정규 표현식 패턴에 맞는지 확인합니다.
    a = " " + a; // 인덱스 접근을 편리하게 하기 위해 문자열 앞에 공백을 추가합니다.
    b = " " + b;

    is_pos[0][0] = true; // 초기 상태를 참으로 설정합니다.

    // is_pos[i][j] :: 문자열 a의 i번째와 표현식 b의 j번째까지가 서로 일치하면 true, 아니면 false
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            if(!is_pos[i][j]) continue;

            if(j != m - 1 && b[j + 2] == '*') {
                is_pos[i][j + 2] = true;

                for(int curi = i + 1; curi <= n; curi++) {
                    if(b[j + 1] != '.' && a[curi] != b[j + 1]) break;
                    is_pos[curi][j + 2] = true;
                }
            }
            else if(b[j + 1] == '.') {
                is_pos[i + 1][j + 1] = true;
            }
            else {
                if(a[i + 1] == b[j + 1]) is_pos[i + 1][j + 1] = true;
            }
        }
    }

    // 최종적으로 문자열 'a'와 'b'가 정규 표현식 패턴에 따라 일치하는지 결과를 출력합니다.
    if(is_pos[n][m]) cout << "true";
    else cout << "false";

    return 0;
}