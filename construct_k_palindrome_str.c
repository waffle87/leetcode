// 1400. Construct K Palindrome Strings
#include "leetcode.h"

/*
 * given a string 's' and an integer 'k', return true if you can use all the
 * characters in 's' to constuct 'k' palindrome strings or false otherwise.
 */

bool canConstruct(char *s, int k) {
  int cnt[26] = {0}, odds = 0;
  if (k > strlen(s))
    return false;
  for (int i = 0; s[i]; i++)
    cnt[s[i] - 'a']++;
  for (int i = 0; i < 26; i++)
    odds += (cnt[i] % 2);
  return k >= odds;
}

int main() {
  char *s1 = "annabelle", *s2 = "leetcode", *s3 = "true";
  printf("%d\n", canConstruct(s1, 2)); // expect: 1
  printf("%d\n", canConstruct(s2, 3)); // expect: 0
  printf("%d\n", canConstruct(s3, 4)); // expect: 1
}
