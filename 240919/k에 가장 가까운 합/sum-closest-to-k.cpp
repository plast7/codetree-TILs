#include <iostream>
#include <algorithm>
#include <tuple>
#include <climits> 
#include <unordered_map> 

using namespace std;

int n, k; 
#define N_MAX (1'000'000 + 1)
int arr[N_MAX]; 
int ans = INT_MAX;
long long cnt = 0; 

int main() {
    cin>>n>>k; 
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n); 
    
    int start=0;
    int end = n-1;
    while(start<end){
        int val = arr[start] + arr[end];
        val = abs(val-k);
        // if val > ans -> do not touch 
        // 
        if(val<ans){
            cnt = 1;
            ans = val; 
        }
        else if(val==ans){
            cnt++; 
        }
        // reached the end point 
        if(start+1==end)
            break; 
        int val1 = arr[start+1] + arr[end];
        int val2 = arr[start] + arr[end-1]; 
        val1 = abs(k-val1);
        val2 = abs(k-val2);
        if(val1<val2)
            start++;
        else if(val2<val1)
            end--; 
        else{ // val1 == val2 
            if(val1==ans)
                cnt++;
            end--;  
        }
    }
    
    cout<<cnt; 

    return 0;
}


// -k/2 for each (?)
// [s+1, e] vs [s, e-1] -> all same
// [s+1, e]
// [s, e]

// a1-k/2, a2-k/2, ..., xxx