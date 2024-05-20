#include <iostream>

using namespace std;

int main() {
    int n, k, sum=0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> k;
        sum += k;
    }
    if(sum%3==0) cout << 1;
    else cout << 0;
    return 0;
}