// 1525. Number of Good Ways to Split a String
#include "leetcode.h"

/*
 * you are given a string 's'. a split is called good if you can split 's' into
 * two non-empty strings 's_left' and 's_right' where their concatenation is
 * equal to 's' (ie. 's_left + s_right = s') and the number of distinct letters
 * in 's_left' and 's_right' is the same. return the number of good splits you
 * can make in 's'.
 */

int numSplits(char *s) {
  int l_map[26] = {0}, r_map[26] = {0};
  int cnt = 0, l_char = 0, r_char = 0, n = strlen(s);
  for (int i = 0; i < n; i++)
    if (!r_map[s[i] - 'a']++)
      r_char++;
  for (int i = 0; i < n - 1; i++) {
    if (!l_map[s[i] - 'a']++)
      l_char++;
    if (!--r_map[s[i] - 'a'])
      r_char--;
    if (l_char == r_char)
      cnt++;
  }
  return cnt;
}

int main() {
  char *s1 = "aacaba", *s2 = "abcd";
  printf("%d\n", numSplits(s1)); // expect: 2
  printf("%d\n", numSplits(s2)); // expect: 1
}
