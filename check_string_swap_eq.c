// 1790. Check if One String Swap Can Make Strings Equal
#include "leetcode.h"

/*
 * you are given two strings 's1' and 's2' of equal length. a string swap is an
 * operation where you choose two indices in a string (not necessarily
 * different) and swap the characters at these indices. return 'true' if it is
 * possible to make both strings equal by performing at most one string swap on
 * exactly one of the strings. otherwise, return 'false'.
 */

bool areAlmostEqual(char *s1, char *s2) {
  int n = strlen(s1), cnt = 0, idx1 = 0, idx2 = 0;
  for (int i = 0; i < n; i++)
    if (s1[i] != s2[i]) {
      cnt++;
      if (!idx1)
        idx1 = i;
      else
        idx2 = i;
    }
  return (!cnt || cnt == 2) && s1[idx1] == s2[idx2] && s1[idx2] == s2[idx1];
}

int main() {
  char *s11 = "bank", *s21 = "kanb";
  char *s12 = "attack", *s22 = "defend";
  char *s13 = "kelb", *s23 = "kelb";
  printf("%d\n", areAlmostEqual(s11, s21)); // expect: 1
  printf("%d\n", areAlmostEqual(s12, s22)); // expect: 0
  printf("%d\n", areAlmostEqual(s13, s23)); // expect: 1
}
