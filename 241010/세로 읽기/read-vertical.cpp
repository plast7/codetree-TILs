#include <stdio.h>
#include <math.h>
#include <string.h>

int n, m;

char s[6][1003];
int v[200];
char d[200];

int main() {
  for (int i = 0; i < 5; i++) {
    scanf("%s", s[i]);
  }

  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 5; j++) {
      if (s[j][i] != 0) {
        printf("%c", s[j][i]);
      }
    }
  }

  return 0;
}