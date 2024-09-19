#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // 전구의 개수와 명령어의 개수를 입력받습니다.
    int num_bulbs, num_commands;
    cin >> num_bulbs >> num_commands;
    
    // 전구 상태를 저장할 벡터를 선언합니다. 1-based index를 사용하기 위해 크기를 num_bulbs + 1로 설정합니다.
    vector<int> bulbs(num_bulbs + 1, 0);
    
    // 초기 전구 상태를 입력받습니다.
    for(int i = 1; i <= num_bulbs; i++){
        cin >> bulbs[i];
    }
    
    // 각 명령어를 처리합니다.
    for(int i = 0; i < num_commands; i++){
        int command_type, start_index, end_value;
        cin >> command_type >> start_index >> end_value;
        
        // 명령어 타입에 따라 전구 상태를 변경합니다.
        if(command_type == 1) {
            // 명령어 1: start_index 번째 전구의 상태를 end_value로 변경합니다.
            bulbs[start_index] = end_value;
        } 
        else if(command_type == 2) {
            // 명령어 2: start_index부터 end_value까지의 전구 상태를 반전시킵니다.
            for(int j = start_index; j <= end_value; j++){
                bulbs[j] = !bulbs[j];
            }
        } 
        else if(command_type == 3) {
            // 명령어 3: start_index부터 end_value까지의 전구 상태를 0으로 변경합니다.
            for(int j = start_index; j <= end_value; j++){
                bulbs[j] = 0;
            }
        } 
        else if(command_type == 4) {
            // 명령어 4: start_index부터 end_value까지의 전구 상태를 1로 변경합니다.
            for(int j = start_index; j <= end_value; j++){
                bulbs[j] = 1;
            }
        }
    }
    
    // 최종 전구 상태를 출력합니다.
    for(int i = 1; i <= num_bulbs; i++){
        cout << bulbs[i] << ' ';
    }
}