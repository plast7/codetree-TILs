#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n;
map<string, int> m;
string s1, s2;

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    cin >> s1 >> s2;

    if (m.find(s2) == m.end()) {
      m.insert(make_pair(s2, 1));
    }
    else {
      m[s2]++;
    }
  }

  int s = 1;

  for (std::map<string, int>::iterator iter = m.begin(); iter != m.end(); ++iter) {
    s *= (iter->second + 1);
  }

  printf("%d\n", s - 1);

  return 0;
}