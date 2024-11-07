#include <stdio.h>

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    scanf("%d", &n);

    int a1, b1, c1;
    scanf("%d %d %d", &a1, &b1, &c1);

    int a2, b2, c2;
    scanf("%d %d %d", &a2, &b2, &c2);

    int cnt = 0;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                if (
                    ((-2 <= i-a1 && i-a1 <= 2) || (-2  <= n-(i-a1) && n-(i-a1) <= 2)) && 
                    ((-2 <= j-b1 && j-b1 <= 2) || (-2  <= n-(j-b1) && n-(j-b1) <= 2)) && 
                    ((-2 <= k-c1 && k-c1 <= 2) || (-2  <= n-(k-c1) && n-(k-c1) <= 2))) {
                    cnt++;
                    continue;
                }
                if (
                    ((-2 <= i-a2 && i-a2 <= 2) || (-2  <= n-(i-a2) && n-(i-a2) <= 2)) && 
                    ((-2 <= j-b2 && j-b2 <= 2) || (-2  <= n-(j-b2) && n-(j-b2) <= 2)) && 
                    ((-2 <= k-c2 && k-c2 <= 2) || (-2  <= n-(k-c2) && n-(k-c2) <= 2))) {
                    cnt++;
                    continue;
                }
            }
        }
    }

    printf("%d", cnt);
    return 0;
}