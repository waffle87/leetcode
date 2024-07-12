// 1717. Maximum Score From Removing Substrings
#include "leetcode.h"

/*
 * given a sting 's' and two integers 'x' and 'y'. you can perform two types of
 * operations any number of times. remove substring "ab" and gain 'x' points.
 * remove substring "ba" and gain 'y' points. return the maximum points you can
 * gain after applying the above operations on 's'
 */

int remove_pattern(char *s, const char *r, int x) {
  int i = 0, res = 0, n = strlen(s);
  for (int j = 0; j < n; ++j) {
    s[i++] = s[j];
    if (i > 1 && s[i - 2] == r[0] && s[i - 1] == r[1]) {
      i -= 2;
      res += x;
    }
  }
  s[i] = '\0';
  return res;
}

int maximumGain(char *s, int x, int y) {
  char a[3] = "ab", b[3] = "ba";
  if (x < y) {
    char tmp[3];
    strcpy(tmp, a);
    strcpy(a, b);
    strcpy(b, tmp);
    int tmp_x = x;
    x = y;
    y = tmp_x;
  }
  return remove_pattern(s, a, x) + remove_pattern(s, b, y);
}

int main() {
  char s1[] = "cdbcbbaaabab", s2[] = "aabbaaxybbaabb";
  printf("%d\n", maximumGain(s1, 4, 5)); // expect: 19
  printf("%d\n", maximumGain(s2, 5, 4)); // expect: 20
}
