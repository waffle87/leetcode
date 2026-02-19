// 696. Count Binary Substrings
#include "leetcode.h"

/*
 * given a binary string 's', return the number of non-empty substrings that
 * have the same number of 0's and 1's, and all the 0's and all the 1's in these
 * substrings are group consecutively. substrings that occur multiple times are
 * counted the number of times they occur.
 */

int countBinarySubstrings(char *s) {
  int curr = 1, pre = 0, ans = 0, n = strlen(s);
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1])
      curr++;
    else {
      ans += fmin(curr, pre);
      pre = curr;
      curr = 1;
    }
  }
  return ans + fmin(curr, pre);
}

int main() {
  char *s1 = "00110011", *s2 = "10101";
  int r1 = countBinarySubstrings(s1);
  int r2 = countBinarySubstrings(s2);
  printf("%d\n", r1); // expect: 6
  assert(r1 == 6);
  printf("%d\n", r2); // expect: 4
  assert(r2 == 4);
}
