// 1653. Minimum Deletions to Make String Balanced
#include "leetcode.h"

/*
 * you are given a string 's' consisting of only characters 'a' and 'b'. you can
 * delete any number of characters in 's' to make 's' balanced. 's' is balanced
 * if there is no pair of indices '(i, j)' such that 'i < j' and 's[i] = b' and
 * 's[j] = a'. return the minimum number of deletions needed to make 's'
 * balanced.
 */

int minimumDeletions(char *s) {
  int cnt = 0, ans = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == 'b') {
      cnt++;
    } else if (cnt) {
      ans++;
      cnt--;
    }
  }
  return ans;
}

int main() {
  char *s1 = "aababbab", *s2 = "bbaaaaabb";
  printf("%d\n", minimumDeletions(s1)); // expect: 2
  printf("%d\n", minimumDeletions(s2)); // expect: 2
}
