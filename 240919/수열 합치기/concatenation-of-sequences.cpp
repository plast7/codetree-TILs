#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 수열 A와 B의 크기를 입력받습니다.
    int sizeA, sizeB;
    cin >> sizeA >> sizeB;
    
    // 수열 A와 B를 저장할 벡터를 선언합니다.
    vector<int> sequenceA(sizeA);
    vector<int> sequenceB(sizeB);
    
    // 수열 A의 원소들을 입력받습니다.
    for(int i = 0; i < sizeA; i++)
        cin >> sequenceA[i];
    
    // 수열 B의 원소들을 입력받습니다.
    for(int i = 0; i < sizeB; i++)
        cin >> sequenceB[i];
    
    // 수열 A와 B를 각각 오름차순으로 정렬합니다.
    sort(sequenceA.begin(), sequenceA.end());
    sort(sequenceB.begin(), sequenceB.end());
    
    // 두 수열을 합치기 위한 인덱스를 초기화합니다.
    int indexA = 0, indexB = 0;
    
    // 두 수열을 오름차순으로 합칩니다.
    while (indexA < sizeA && indexB < sizeB) {
        // 수열 A의 현재 원소가 수열 B의 현재 원소보다 작거나 같으면 출력합니다.
        if (sequenceA[indexA] <= sequenceB[indexB]) {
            cout << sequenceA[indexA++] << " ";
        } else {
            // 수열 B의 현재 원소가 더 작으면 출력합니다.
            cout << sequenceB[indexB++] << " ";
        }
    }
    
    // 수열 A에 남은 원소들을 출력합니다.
    while (indexA < sizeA) {
        cout << sequenceA[indexA++] << " ";
    }
    
    // 수열 B에 남은 원소들을 출력합니다.
    while (indexB < sizeB) {
        cout << sequenceB[indexB++] << " ";
    }
    
    return 0;
}