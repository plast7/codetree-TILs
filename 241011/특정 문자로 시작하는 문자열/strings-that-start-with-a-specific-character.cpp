#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char arr[n][20];
    for (int i = 0;i < n;i++){
        scanf("%s", arr[i]);
    }
    char word;
    scanf("%c", &word);

    int num = 0;
    double len = 0;
    for (int i = 0;i < n;i++){
        if (arr[i][0] == word){
            num++;
            len += strlen(arr[i]);
        }
    }

    printf("%d %.2lf", num, len/num);
    
    return 0;
}