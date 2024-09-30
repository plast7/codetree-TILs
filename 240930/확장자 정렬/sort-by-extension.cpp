#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    int file_count;
    cin >> file_count;

    // 확장자와 그 개수를 저장할 map을 선언합니다.
    map<string, int> extension_count;
    string file_name;

    // 파일 이름을 읽고 확장자를 카운트합니다.
    for (int i = 0; i < file_count; i++) {
        cin >> file_name;
        // 파일 이름에서 확장자를 추출합니다.
        string extension = file_name.substr(file_name.find('.') + 1);
        // 해당 확장자의 개수를 증가시킵니다.
        extension_count[extension]++;
    }

    // 확장자와 그 개수를 사전순으로 출력합니다.
    for (const auto& entry : extension_count) {
        cout << entry.first << " " << entry.second << endl;
    }

    return 0;
}