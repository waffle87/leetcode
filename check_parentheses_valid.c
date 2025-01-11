// 2116. Check if a Parentheses String Can Be Valid
#include "leetcode.h"
#include <math.h>
#include <string.h>

/*
 * a parentheses string is a non-empty string consisting only of '(' and ')'. it
 * is valid if any of the following conditions is true: it is '()', it can be
 * written as 'AB' where 'A' and 'B' are valid parentheses, it can be written as
 * '(A)' where 'A' is a valid parentheses string. you are given a parentheses
 * string 's' and a string 'locked', both of length 'n'. 'locked' is a binary
 * string consistion only of '0's and '1's. for each indiex 'i' of 'locked'.
 */

bool canBeValid(char *s, char *locked) {
  int n = strlen(s), total = 0, open = 0, closed = 0;
  if (n % 2 == 1)
    return false;
  for (int i = n - 1; i >= 0; i--) {
    if (locked[i] == '0')
      total++;
    else if (s[i] == '(')
      open++;
    else if (s[i] == ')')
      closed++;
    if (total - open + closed < 0)
      return false;
  }
  total = open = closed = 0;
  for (int i = 0; i < n; i++) {
    if (locked[i] == '0')
      total++;
    else if (s[i] == '(')
      open++;
    else if (s[i] == ')')
      closed++;
    if (total + open - closed < 0)
      return false;
  }
  return true;
}

int main() {
  char *s1 = "))()))", *l1 = "010100";
  char *s2 = "()()", *l2 = "0000";
  char *s3 = ")", *l3 = "0";
  printf("%d\n", canBeValid(s1, l1)); // expect: 1
  printf("%d\n", canBeValid(s2, l2)); // expect: 1
  printf("%d\n", canBeValid(s3, l3)); // expect: 0
}
