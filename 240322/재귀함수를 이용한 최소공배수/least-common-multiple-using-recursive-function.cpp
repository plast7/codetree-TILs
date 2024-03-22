#include <iostream>

using namespace std;
int n;
int arr[11];

int gcd(int a, int b) {
    if(b == 0) return a;  
    else return gcd(b, a%b);  
}

// gcd는 a, b의 최대공약수이다.
int lcm(int a, int b) {
    return a*b/gcd(a,b);
}

int Ans(int n){
    int tmp=1;
    for(int i=0; i<n; i++){
        tmp=lcm(tmp,arr[i]);
    }
    return tmp;
    
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<Ans(n);

    return 0;
}