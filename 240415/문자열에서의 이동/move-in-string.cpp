#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int n;
string s;
int dp[1005];

int main() {
    cin>>n>>s;
    int sz=s.size();

    assert(s[0] == 'a');

    fill(dp,dp+1005,1e9);

    dp[0]=0;

    for(int i=0;i<sz;i++){
        for(int j=i+1;j<sz;j++){
            if((s[i]+1-'a')%3!=s[j]-'a') continue;
            dp[j]=min(dp[j],dp[i]+(j-i)*(j-i));
        }
        //cout<<dp[i]<<' ';
    }

    if(dp[sz-1]==1e9) cout<<-1;
    else cout<<dp[sz-1];

    return 0;
}