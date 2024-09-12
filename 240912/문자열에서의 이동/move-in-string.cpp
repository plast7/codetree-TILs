#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string street;
    cin >> street;

    // 각 위치까지의 최소 에너지를 저장하는 벡터를 초기화합니다.
    vector<int> min_energy(n, INT_MAX);
    min_energy[0] = 0; // 시작 위치의 에너지는 0입니다.

    // 문자열의 각 위치를 순회합니다.
    for (int i = 0; i < n; i++) {
        // 현재 위치까지 도달할 수 없는 경우, 건너뜁니다.
        if (min_energy[i] == INT_MAX) continue;

        // 다음에 밟아야 할 문자를 결정합니다.
        char next_char;
        if (street[i] == 'a') next_char = 'b';
        else if (street[i] == 'b') next_char = 'c';
        else next_char = 'a';

        // 현재 위치에서 다음 위치를 찾습니다.
        for (int j = i + 1; j < n; j++) {
            // 다음에 밟아야 할 문자를 찾습니다.
            if (street[j] == next_char) {
                // 이동하는데 드는 에너지를 계산합니다.
                int energy = (j - i) * (j - i);
                // 최소 에너지를 갱신합니다.
                min_energy[j] = min(min_energy[j], min_energy[i] + energy);
            }
        }
    }

    // 마지막 위치까지 도달할 수 있는지 확인합니다.
    if (min_energy[n - 1] == INT_MAX) {
        // 도달할 수 없는 경우 -1을 출력합니다.
        cout << -1 << endl;
    } else {
        // 도달할 수 있는 경우 최소 에너지를 출력합니다.
        cout << min_energy[n - 1] << endl;
    }

    return 0;
}