#include <stdio.h>
#include <math.h>
#include <string.h>

int n, m;

char s[100];
int v[200];
char d[200];

void print(int num, int base) {
  if (num == 0) {
    printf("0");
    return;
  }

  int c = 0;
  int r[101];

  while (num) {
    r[c++] = d[num % base];
    num /= base;
  }

  for (int i = c - 1; i >= 0; i--) {
    printf("%c", r[i]);
  }
}

int main() {
  for (int i = '0'; i <= '9'; i++) {
    v[i] = i - '0';
    d[i - '0'] = i;
  }
  for (int i = 'a'; i <= 'z'; i++) {
    v[i] = i - 'a' + 10;
    d[i - 'a' + 10] = i;
  }

  int base = 10;
  int target = 2;

  scanf("%d.%s", &n, s);

  for (int i = 0; i < 4; i++) {
    if ('0' <= s[i] && s[i] <= '9') {
      m = m * 10 + s[i] - '0';
    }
    else {
      m *= 10;
    }
  }

  print(n, target);

  printf(".");

  for (int i = 0; i < 4; i++) {
    m *= 2;
    printf("%d", m / 10000);
    m %= 10000;
  }

  return 0;
}