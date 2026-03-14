// 1415. The k-th Lexicographical String of All Happy Strings of Length n
#include "leetcode.h"

/*
 * a happy string is a string that consists only of letters of the set '[a, b,
 * c]', 's[i] != s[i + 1]' for all values of 'i' from 1 to 's.length - 1'. given
 * two integers 'n' and 'k', consider a list of all happy strings of length 'n'
 * sorted in lexicographical order. return the k'th string of this list or
 * return an empty string if there are less than 'k' strings of length 'n'.
 */

char *getHappyString(int n, int k) {
  const int m = 3 << (n - 1);
  if (m < k)
    return "";
  int t[3][2] = {{1, 2}, {0, 2}, {0, 1}};
  char *s = (char *)malloc((n + 1) * sizeof(char));
  s[n] = '\0';
  memset(s, 'a', n * sizeof(char));
  s[0] += (k > m / 3) + (k > 2 * m / 3);
  --k;
  for (int i = 1; i < n; ++i)
    s[i] += t[s[i - 1] - 'a'][(k & (1 << (n - i - 1))) > 0];
  return s;
}

int main() {
  char *r1 = getHappyString(1, 3);
  char *r2 = getHappyString(1, 4);
  char *r3 = getHappyString(3, 9);
  printf("%s\n", r1); // expect: c
  assert(!strcmp(r1, "c"));
  printf("%s\n", r2); // expect: null
  assert(!strcmp(r2, ""));
  printf("%s\n", r3); // expect: cab
  assert(!strcmp(r3, "cab"));
  free(r1);
  free(r3);
}
