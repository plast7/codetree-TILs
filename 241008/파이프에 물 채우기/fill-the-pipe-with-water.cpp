#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최대 파이프 개수를 정의합니다.
#define MAX_PIPES 10005

// 각 파이프를 채우는데 걸리는 시간을 저장합니다.
long long fillTime[MAX_PIPES];

// 각 파이프의 의존성을 저장하는 그래프입니다.
vector<int> dependencyGraph[MAX_PIPES];

// 각 파이프의 최소 완료 시간을 저장합니다.
long long minCompletionTime[MAX_PIPES];

// 파이프 i의 최소 완료 시간을 반환합니다.
// 아직 계산되지 않은 경우, 그 값을 계산합니다.
long long calculateMinCompletionTime(int pipeIndex) {
    // 만약 최소 완료 시간이 아직 계산되지 않았다면
    if (minCompletionTime[pipeIndex] == -1) {
        // 가장 빠른 시작 시간을 초기화합니다.
        long long earliestStart = 0;
        // 현재 파이프에 의존하는 모든 파이프에 대해
        for (int dependency : dependencyGraph[pipeIndex]) {
            // 의존하는 파이프의 최소 완료 시간을 계산하여
            // 가장 큰 값을 earliestStart에 저장합니다.
            earliestStart = max(earliestStart, calculateMinCompletionTime(dependency));
        }
        // 현재 파이프의 최소 완료 시간은 가장 빠른 시작 시간에
        // 현재 파이프를 채우는데 걸리는 시간을 더한 값입니다.
        minCompletionTime[pipeIndex] = earliestStart + fillTime[pipeIndex];
    }
    // 최소 완료 시간을 반환합니다.
    return minCompletionTime[pipeIndex];
}

int main() {
    int numberOfPipes, numberOfDependencies;
    // 파이프의 개수와 의존성의 개수를 입력받습니다.
    cin >> numberOfPipes >> numberOfDependencies;

    // 각 파이프에 대해
    for (int i = 0; i < numberOfPipes; i++) {
        // 물을 채우는데 걸리는 시간을 입력받습니다.
        cin >> fillTime[i];
        // 최소 완료 시간을 아직 계산되지 않은 상태로 초기화합니다.
        minCompletionTime[i] = -1;
    }

    // 각 의존성에 대해
    for (int i = 0; i < numberOfDependencies; i++) {
        int pipeA, pipeB;
        // 의존성을 입력받습니다.
        cin >> pipeA >> pipeB;
        // 0-based index로 변환합니다.
        pipeA--; 
        pipeB--; 
        // pipeB가 pipeA에 의존함을 그래프에 추가합니다.
        dependencyGraph[pipeB].push_back(pipeA);
    }

    // 모든 파이프의 최소 완료 시간 중 최대 값을 찾습니다.
    long long totalMinTime = 0;
    for (int i = 0; i < numberOfPipes; i++) {
        totalMinTime = max(totalMinTime, calculateMinCompletionTime(i));
    }

    // 모든 파이프에 물을 다 채우는데 필요한 최단 시간을 출력합니다.
    cout << totalMinTime << endl;

    return 0;
}