#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // 복장의 개수를 저장할 변수입니다.
    int numberOfClothes;
    cin >> numberOfClothes;

    // 각 복장 종류별로 몇 개의 복장이 있는지를 저장할 map입니다.
    map<string, int> clothingTypeCount;
    string clothingName, clothingType;

    // 모든 복장에 대해 입력을 받습니다.
    for (int i = 0; i < numberOfClothes; i++) {
        cin >> clothingName >> clothingType;

        // 해당 복장 종류가 처음 등장하는 경우, map에 추가합니다.
        if (clothingTypeCount.find(clothingType) == clothingTypeCount.end()) {
            clothingTypeCount[clothingType] = 1;
        } else {
            // 이미 존재하는 복장 종류라면, 개수를 증가시킵니다.
            clothingTypeCount[clothingType]++;
        }
    }

    // 가능한 코디의 총 수를 계산할 변수입니다.
    long long totalCombinations = 1;

    // 각 복장 종류별로 코디의 경우의 수를 계산합니다.
    // 각 종류별로 해당 종류의 복장을 착용하지 않는 경우도 포함하여 +1을 해줍니다.
    for (auto it = clothingTypeCount.begin(); it != clothingTypeCount.end(); ++it) {
        totalCombinations *= (it->second + 1);
    }

    // 전체 경우의 수에서 아무것도 착용하지 않는 경우를 제외하기 위해 -1을 해줍니다.
    cout << totalCombinations - 1 << endl;

    return 0;
}