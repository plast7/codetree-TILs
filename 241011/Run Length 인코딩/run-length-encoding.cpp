#include <stdio.h>
#include <string.h>

int main() {
    char arr[1000];
    char arr1[1000];
    int arr2[1000];

    scanf("%s", arr);
    int len = strlen(arr);

    int num = 1;
    char curr_char = arr[0];
    int cnt = 0;
    for (int i = 1;i < len;i++){
        if (arr[i] == arr[i-1]){
            num++;
        }
        else {
            arr1[cnt] = arr[i-1];
            arr2[cnt] = num;
            
            num = 1;
            cnt++;
        }
    }
    int result = strlen(arr1) + (sizeof(arr2))/(sizeof(int));
    printf("%d\n", result);

    for (int i = 0;i < cnt;i++){
        printf("%c%d", arr1[i],arr2[i]);
    }
    return 0;
}