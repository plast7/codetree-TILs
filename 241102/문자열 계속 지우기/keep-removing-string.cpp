#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char a[101];
    char b[101];

    scanf("%s", a);
    scanf("%s", b);

    int len1 = strlen(a);
    int len2 = strlen(b);

    while(true){
        int idx = -1;

        int length = len1 - len2 + 1;

        for(int i = 0; i < length; i++){
            bool same = true;

            for(int j = 0; j < len2; j++){
                if(a[i + j] != b[j]){
                    same = false;
                    break;
                }
            }
            if(same){
                idx = i;
                break;
            }
        }

        if(idx = -1){
            break;
        }

        for(int i = idx + len2; i < len1; i++){
            a[i - len2] = a[i];
        }
        a[len1 - len2] = '\0';

        len1 = strlen(a);
    }

    printf("%s", a);
    
    return 0;
}