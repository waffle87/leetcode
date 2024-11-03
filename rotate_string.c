// 796. Rotate String
#include "leetcode.h"

/*
 * given two strings 's' and 'goal', return 'true' if and only if 's' can become
 * 'goal' after some number of shifts on 's'. a shift on 's' consists of moving
 * the leftmost character of 's' to the rightmost position. for example, if 's =
 * "abcde"', then it will be "bcdea" after one shift.
 */

bool rotateString(char *s, char *goal) {
  int sn = strlen(s), gn = strlen(goal);
  if (sn == gn) {
    for (int i = 0; i < sn; i++) {
      if (!strcmp(s, goal))
        return true;
      char tmp = s[0];
      for (int j = 0; j < gn - 1; j++)
        s[j] = s[j + 1];
      s[sn - 1] = tmp;
    }
  }
  return false;
}

int main() {
  char *s1 = "abcde", *g1 = "cdeab";
  char *s2 = "abcde", *g2 = "abced";
  printf("%d\n", rotateString(s1, g1)); // expect: 1
  printf("%d\n", rotateString(s2, g2)); // expect: 0
}
