#include <iostream>

using namespace std;

// grid 배열과 prefixSum 배열을 선언합니다.
int grid[1025][1025], prefixSum[1025][1025];

int main()
{
    // 입출력 속도를 높이기 위해 사용합니다.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 격자의 크기와 질의의 수를 입력받습니다.
    int gridSize, queryCount;
    cin >> gridSize >> queryCount;

    // 격자의 값을 입력받고 동시에 prefixSum 배열을 채웁니다.
    for(int row = 1; row <= gridSize; row++)
    {
        for(int col = 1; col <= gridSize; col++)
        {
            // 각 칸의 값을 입력받습니다.
            cin >> grid[row][col];
            // prefixSum 배열을 채웁니다.
            // 현재 칸의 prefixSum 값은 위쪽 칸의 prefixSum 값, 왼쪽 칸의 prefixSum 값,
            // 대각선 왼쪽 위 칸의 prefixSum 값을 이용하여 계산합니다.
            prefixSum[row][col] = prefixSum[row-1][col] + prefixSum[row][col-1] - prefixSum[row-1][col-1] + grid[row][col];
        }
    }

    // 각 질의에 대해 구간 합을 계산합니다.
    for(int i = 0; i < queryCount; i++)
    {
        // 질의의 좌표를 입력받습니다.
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // 구간 합을 계산합니다.
        // (x1, y1)부터 (x2, y2)까지의 합은 prefixSum[x2][y2]에서
        // prefixSum[x1-1][y2], prefixSum[x2][y1-1], prefixSum[x1-1][y1-1]을 이용하여 계산합니다.
        int sum = prefixSum[x2][y2] - prefixSum[x1-1][y2] - prefixSum[x2][y1-1] + prefixSum[x1-1][y1-1];
        
        // 결과를 출력합니다.
        cout << sum << '\n';
    }

    return 0;
}