#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int a[1010];
int b[1010];
int main() {
    // 여기에 코드를 작성해주세요.
    int n, i, j, a_dis, b_dis, dis, min=1010, x, y;
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
    }

    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            a_dis=abs(a[i]-a[j]);
            b_dis=abs(b[i]-b[j]);
            dis=a_dis+b_dis;
            
            if(min>dis)
            {
                x=a_dis;
                y=b_dis;
            }
            min=fmin(min, dis);

        }
    }

    printf("%d", x*x+y*y);
    return 0;
}