// 1400. Construct K Palindrome Strings
#include "leetcode.h"

/*
 * given a string 's' and an integer 'k', return true if you can use all the
 * characters in 's' to constuct 'k' palindrome strings or false otherwise.
 */

bool canConstruct(char *s, int k) {
  int n = strlen(s);
  if (n < k)
    return 0;
  int *c = calloc(26, sizeof(int));
  for (int i = 0; i < n; i++)
    c[s[i] - 'a']++;
  int odd = 0;
  for (int i = 0; i < 26; i++)
    if (c[i] % 2 == 1)
      odd++;
  free(c);
  if (odd > k)
    return 0;
  return 1;
}

int main() {
  char *s1 = "annabelle", *s2 = "leetcode", *s3 = "true";
  printf("%d\n", canConstruct(s1, 2)); // expect: 1
  printf("%d\n", canConstruct(s2, 3)); // expect: 0
  printf("%d\n", canConstruct(s3, 4)); // expect: 1
}
