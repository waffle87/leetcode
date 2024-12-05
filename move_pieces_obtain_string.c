// 2337. Move Pieces to Obtain a String
#include "leetcode.h"

/*
 * you are given two strings 'start' and 'target' both of length 'n'. each
 * string consists only of the characters 'L', 'R', and '_' where the characters
 * 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if
 * there is a blank space directly to its left, and piece 'R' can move to the
 * right only if there is a blank space directly to its right. return true if it
 * is possible to obtain the string 'target' by moving the pieces of string
 * 'start' any number of times. otherwise, return false.
 */

bool canChange(char *start, char *target) {
  int n = strlen(target), i = 0, j = 0;
  while (i <= n && j <= n) {
    while (i < n && target[i] == '_')
      i++;
    while (j < n && start[j] == '_')
      j++;
    if (i == n || j == n)
      return i == n && j == n;
    if (target[i] != start[j])
      return false;
    if (target[i] == 'L') {
      if (j < i)
        return false;
    } else if (i < j)
      return false;
    i++, j++;
  }
  return true;
}

int main() {
  char *s1 = "_L__R__R_", *t1 = "L______RR";
  char *s2 = "R_L_", *t2 = "__LR";
  char *s3 = "_R", *t3 = "R_";
  printf("%d\n", canChange(s1, t1)); // expect: 1
  printf("%d\n", canChange(s2, t2)); // expect: 0
  printf("%d\n", canChange(s3, t3)); // expect: 0
}
