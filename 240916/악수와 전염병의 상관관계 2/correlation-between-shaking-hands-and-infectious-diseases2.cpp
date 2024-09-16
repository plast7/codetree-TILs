#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int N,K,P,T; //N:개발자 수 , K:전염 횟수, P:처음 전염병 걸린 개발자 번호, T:몇번 악수 나눴나
    cin>>N>>K>>P>>T;
    int student[N+1]={0};
    bool inf[101] = {false};
    inf[P] = true; //감염 여부
    student[P] = K; //남은 감염 횟수
   
    for(int i=1; i<T; i++){
        int t,x,y;
        cin>>t>>x>>y;
        if(inf[x] and student[x]>0){
            student[x]--;
            if(!inf[y]){
                inf[y] = true;
                student[y] = K;
            }
        }
        if(inf[y] and student[y]>0){
            student[y]--;
            if(!inf[x]){
                inf[x] = true;
                student[x] = K;
            }
        }
    }
    for(int i=1; i<=N; i++){
        cout<<inf[i];
    }
    return 0;
}