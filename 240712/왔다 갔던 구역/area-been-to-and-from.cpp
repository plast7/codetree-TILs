#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int main()
{
    pii cover1, cover2[100005];
    int n, point=1000000000, sum=0, maxi=0;
    int i, s=0;
    cover1.first=1000000000, cover1.second=1000000000;
    
    cin >> n;
    for(i=0;i<n;i++){
        char dir;
        int step;
        cin >> step >> dir;
        if(dir=='R'){
            point+=step;
            cover2[s].first=point-step, cover2[s++].second=min(cover1.second, point);
            if(cover2[s-1].first==cover2[s-1].second)
                s--;
            if(point>cover1.second)
                cover1.second=point;
        }
        else{
            point-=step;
            cover2[s].first=max(cover1.first, point), cover2[s++].second=point+step;
            if(cover2[s-1].first==cover2[s-1].second)
                s--;
            if(point<cover1.first)
                cover1.first=point;
        }
    }
    sort(cover2, cover2+s);
    for(i=0;i<s;i++){
        if(cover2[i].second>maxi){
            sum+=cover2[i].second-max(cover2[i].first, maxi);
            maxi=cover2[i].second;
        }
    }
    
    cout << sum << endl;
    
    return 0;
}