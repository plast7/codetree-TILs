#include <iostream>
using namespace std;

int main() {
    int distance;
    cin >> distance;

    int max_speed = 0;
    int time = 0;
    int have_to_move = 0;
    while(true){
        max_speed++;
        int necessary_moved = (max_speed * max_speed); //반드시 {(최고 속도 * 최고 속도 + 1) - 최고 속도} 거리만큼 이동함

        if(necessary_moved > distance) break;
        
        time = max_speed * 2 - 1;

        have_to_move = distance - necessary_moved;

        time += (have_to_move / max_speed);

        if(have_to_move % max_speed !=0)
            time++;
        //소요된 시간은 최고 속도 * 2 - 1 + 같은 속도에 머무른 시간
    }
    cout << time;
    
    return 0;
}