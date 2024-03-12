#include <iostream>

using namespace std;

int n;
#define N_MAX (100 + 1)
int arr[N_MAX];

int main() {
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];    
    }
    int sum =0;
    int cnt = 0; 
    for(int i=0; i<n; i++){
        sum += arr[i];
        cnt++;
        if(sum>200){
            break; 
        }
    }
    double avg = (double)sum/cnt;
    cout<<fixed;
    cout.precision(1);
    cout<<sum<<'\n'<<avg; 
    
    return 0;
}