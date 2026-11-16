// 2243. Calculate Digit Sum of a String
#include "leetcode.h"

char *digitSum(char *s, int k) {
  for (int i = strlen(s), m, n, o, p; i > k; i = m) {
    for (m = 0, n = 0, o = 0; s[n] != '\0'; n += o) {
      for (o = 1, p = s[n] - '0'; o < k; o++) {
        if (s[n + o] == '\0')
          break;
        p += s[n + o] - '0';
      }
      if (p > 99)
        s[m++] = (p / 100) + '0';
      if (p > 9)
        s[m++] = ((p / 10) % 10) + '0';
      s[m++] = (p % 10) + '0';
    }
    s[m] = '\0';
  }
  return s;
}

int main() {
  char *s1 = "11111222223", *r1 = "135";
  char *s2 = "00000000", *r2 = "000";
  char *ds1 = digitSum(s1, 3);
  char *ds2 = digitSum(s2, 3);
  printf("%s\n", ds1);
  assert(!strcmp(ds1, r1));
  printf("%s\n", ds2);
  assert(!strcmp(ds2, r2));
}
