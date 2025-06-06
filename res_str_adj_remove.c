// 3561. Resulting String After Adjacent Removals
#include "leetcode.h"

/*
 * you are given a string 's' consisting of lowercase english letters. you must
 * repeatedly perform the following operation while the string 's' has at least
 * two consecutive characters: remove the leftmost pair of adjacent characters
 * in the string that are consecutive in the alphabet, in either order, and
 * shift the remaining characters to the left to fill the gap. return the
 * resulting string after no more operations can be performed. note: consider
 * the alphabet as circular, thus 'a' and 'z' are consecutive.
 */

bool helper(char a, char b) {
  int c = fabs(a - b);
  return c == 1 || c == 25;
}

char *resultingString(char *s) {
  int n = strlen(s), top = -1;
  char *ans = (char *)malloc((n + 1) * sizeof(char));
  for (int i = 0; i < n; i++) {
    if (top >= 0 && helper(ans[top], s[i]))
      top--;
    else
      ans[++top] = s[i];
  }
  ans[top + 1] = '\0';
  return ans;
}

int main() {
  char *s1 = "abc", *rs1 = resultingString(s1);
  char *s2 = "adcb", *rs2 = resultingString(s2);
  char *s3 = "zadb", *rs3 = resultingString(s3);
  printf("%s\n", rs1); // expect: c
  printf("%s\n", rs2); // expect: null
  printf("%s\n", rs3); // expect: db
  free(rs1);
  free(rs2);
  free(rs3);
}
