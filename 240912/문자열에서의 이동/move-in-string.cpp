#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // 문자열의 길이를 입력받습니다.
    int length;
    cin >> length;
    
    // 문자열을 입력받습니다.
    string path;
    cin >> path;
    
    // 각 위치까지의 최소 에너지를 저장할 벡터를 선언합니다.
    vector<int> min_energy(length, INT_MAX);
    // 시작 위치의 에너지는 0으로 초기화합니다.
    min_energy[0] = 0;
    
    // 문자열의 각 위치를 순회합니다.
    for (int i = 0; i < length; ++i) {
        // 만약 현재 위치까지 도달할 수 없다면, 다음 위치로 넘어갑니다.
        if (min_energy[i] == INT_MAX) continue;
        
        // 다음에 밟아야 할 문자를 결정합니다.
        char next_char;
        if (path[i] == 'a') next_char = 'b';
        else if (path[i] == 'b') next_char = 'c';
        else next_char = 'a';
        
        // 현재 위치에서 다음 위치로 이동할 수 있는지 확인합니다.
        for (int j = i + 1; j < length; ++j) {
            // 다음에 밟아야 할 문자가 맞다면
            if (path[j] == next_char) {
                // 이동하는데 드는 에너지를 계산합니다.
                int energy_cost = (j - i) * (j - i);
                // 최소 에너지를 갱신합니다.
                min_energy[j] = min(min_energy[j], min_energy[i] + energy_cost);
            }
        }
    }
    
    // 마지막 위치까지 도달할 수 있는지 확인합니다.
    if (min_energy[length - 1] == INT_MAX)
        // 도달할 수 없다면 -1을 출력합니다.
        cout << -1 << endl;
    else
        // 도달할 수 있다면 최소 에너지를 출력합니다.
        cout << min_energy[length - 1] << endl;
    
    return 0;
}