#include <iostream>
using namespace std;

// 수열을 저장할 배열을 선언합니다.
int sequence[4001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // 입력받을 원소의 개수와 명령어의 개수를 선언합니다.
    int numElements, numCommands;
    cin >> numElements >> numCommands;
    
    // 수열의 각 원소를 입력받습니다.
    for(int i = 1; i <= numElements; i++){
        cin >> sequence[i];
    }
    
    // 주어진 명령어의 개수만큼 반복하여 명령어를 처리합니다.
    for(int i = 0; i < numCommands; i++){
        int commandType, startIndex, endIndex;
        cin >> commandType >> startIndex >> endIndex;
        
        // 명령어의 종류에 따라 수열을 변환합니다.
        if(commandType == 1) {
            // 1번 명령어: startIndex 위치의 원소를 endIndex 값으로 변경합니다.
            sequence[startIndex] = endIndex;
        } else if(commandType == 2) {
            // 2번 명령어: startIndex부터 endIndex까지의 원소를 0은 1로, 1은 0으로 변경합니다.
            for(int j = startIndex; j <= endIndex; j++){
                sequence[j] = 1 - sequence[j];
            }
        } else if(commandType == 3) {
            // 3번 명령어: startIndex부터 endIndex까지의 원소를 0으로 변경합니다.
            for(int j = startIndex; j <= endIndex; j++){
                sequence[j] = 0;
            }
        } else if(commandType == 4) {
            // 4번 명령어: startIndex부터 endIndex까지의 원소를 1으로 변경합니다.
            for(int j = startIndex; j <= endIndex; j++){
                sequence[j] = 1;
            }
        }
    }
    
    // 명령어를 모두 수행한 후의 수열을 출력합니다.
    for(int i = 1; i <= numElements; i++){
        cout << sequence[i] << ' ';
    }
}