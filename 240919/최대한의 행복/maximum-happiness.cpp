#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 사람의 수를 입력받습니다.
    int num_people;
    cin >> num_people;

    // 각 사람에게 인사했을 때 잃게 되는 에너지와 얻게 되는 행복을 저장할 벡터를 선언합니다.
    vector<int> energy_loss(num_people);
    vector<int> happiness_gain(num_people);

    // 최대 에너지가 100이므로, 각 에너지 상태에서 얻을 수 있는 최대 행복을 저장할 벡터를 선언합니다.
    vector<int> max_happiness(101, 0);

    // 각 사람에게 인사했을 때 잃게 되는 에너지를 입력받습니다.
    for (int i = 0; i < num_people; i++) {
        cin >> energy_loss[i];
    }

    // 각 사람에게 인사했을 때 얻게 되는 행복을 입력받습니다.
    for (int i = 0; i < num_people; i++) {
        cin >> happiness_gain[i];
    }

    // 각 사람에 대해 반복합니다.
    for (int i = 0; i < num_people; i++) {
        // 에너지를 100부터 감소시키면서 최대 행복을 갱신합니다.
        // 이때, 에너지가 음수가 되지 않도록 주의합니다.
        for (int energy = 100; energy >= energy_loss[i]; energy--) {
            // 현재 에너지 상태에서 얻을 수 있는 최대 행복을 갱신합니다.
            max_happiness[energy] = max(max_happiness[energy], max_happiness[energy - energy_loss[i]] + happiness_gain[i]);
        }
    }

    // 에너지가 100일 때 얻을 수 있는 최대 행복을 출력합니다.
    cout << max_happiness[100];

    return 0;
}