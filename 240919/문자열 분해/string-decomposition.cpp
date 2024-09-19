#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    string input; 
    cin >> input;
    int length = input.length();
    vector<int> sequence;
    vector<int> char_count(6, 0);

    // 입력 문자열을 숫자 시퀀스로 변환하고 각 문자의 개수를 셉니다.
    for (int i = 0; i < length; i++) {
        if (input[i] == 'a') {
            sequence.push_back(1);
            char_count[1]++;
        } else if (input[i] == 'b') {
            sequence.push_back(2);
            char_count[2]++;
        } else if (input[i] == 'c') {
            sequence.push_back(3);
            char_count[3]++;
        } else if (input[i] == 'd') {
            sequence.push_back(4);
            char_count[4]++;
        } else if (input[i] == 'e') {
            sequence.push_back(5);
            char_count[5]++;
        }
    }

    // 각 문자의 개수가 동일하지 않으면 분해가 불가능합니다.
    if (char_count[1] != char_count[2] || char_count[1] != char_count[3] || char_count[1] != char_count[4] || char_count[1] != char_count[5]) {
        cout << -1;
        return 0;
    }

    vector<vector<int>> segments;
    vector<int> segment_count;

    // 시퀀스를 순회하며 분해를 시도합니다.
    for (int i = 0; i < length; i++) {
        int current_char = sequence[i];
        bool added = false;

        // 'a'인 경우 새로운 세그먼트를 시작합니다.
        if (current_char == 1) {
            for (int k = 0; k < segments.size(); k++) {
                if (segments[k].empty()) {
                    segments[k].push_back(1);
                    added = true;
                    break;
                }
            }
            if (added) continue;
            vector<int> new_segment;
            new_segment.push_back(1);
            segments.push_back(new_segment);
            segment_count.push_back(0);
            continue;
        }

        // 'a'가 아닌 경우 이전 문자와의 연속성을 확인합니다.
        bool error = true;
        for (int j = 0; j < segments.size(); j++) {
            if (segments[j].empty()) continue;
            if (segments[j].back() == current_char - 1) {
                segments[j].push_back(current_char);
                error = false;
                if (segments[j].size() == 5) {
                    segments[j].clear();
                    segment_count[j]++;
                }
                break;
            }
        }
        if (error) {
            cout << -1;
            return 0;
        }
    }

    // 결과를 계산합니다.
    int result = 0;
    for (int i = 0; i < segment_count.size(); i++) {
        if (segment_count[i] > 0)
            result++;
    }

    if (result == 0)
        cout << -1;
    else
        cout << result;

    return 0;
}