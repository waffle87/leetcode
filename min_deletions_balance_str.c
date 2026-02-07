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
  int cnt = 0, del = 0;
  while (*s) {
    if (*s == 'a')
      del = fmin(++del, cnt);
    else
      cnt++;
    *s++;
  }
  return del;
}

int main() {
  char *s1 = "aababbab", *s2 = "bbaaaaabb";
  int r1 = minimumDeletions(s1);
  int r2 = minimumDeletions(s2);
  printf("%d\n", r1); // expect: 2
  assert(r1 == 2);
  printf("%d\n", r1); // expect: 2
  assert(r2 == 2);
}
