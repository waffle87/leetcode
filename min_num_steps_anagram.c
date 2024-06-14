// 1347. Minimum Number of Steps to Make Two Strings Anagram
#include "leetcode.h"

/*
 * given two trings of the same length 's' and 't'. in one step you can choose
 * any character of 't' and replace itwith another characters. return the
 * minimum numberof steps to make 't' an anagram of 's'. an anagram of a string
 * is a string that contains the same characters witha different ordering.
 */

int minSteps(char *s, char *t) {
  int *alpha = calloc(26, sizeof(int));
  for (int i = 0; i < strlen(s); i++) {
    alpha[s[i] - 'a']++;
    alpha[t[i] - 'a']--;
  }
  int ans = 0;
  for (int i = 0; i < 26; i++)
    if (alpha[i] > 0)
      ans += alpha[i];
  return ans;
}

int main() {
  char *s1 = "bab", *t1 = "aba";
  char *s2 = "leetcode", *t2 = "practice";
  char *s3 = "anagram", *t3 = "mangaar";
  printf("%d\n", minSteps(s1, t1)); // expect: 1
  printf("%d\n", minSteps(s2, t2)); // expect: 5
  printf("%d\n", minSteps(s3, t3)); // expect: 0
}
