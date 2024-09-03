// 777. Swap Adjacent in LR String
#include "leetcode.h"

/*
 * in a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a
 * move consists of either replacing one occurrence of "XL" with "LX", or
 * replacing one occurrence of "RX" with "XR". given the starting string 'start'
 * and the ending string 'end', return true if and only if there exists a
 * sequence of moves to transform 'start' to 'end'
 */

bool canTransform(char *start, char *end) {
  int c1 = 0, c2 = 0, i = 0, j = 0, n = strlen(start);
  for (i = 0; i < n; i++) {
    if (start[i] == 'X')
      c1++;
    if (end[i] == 'X')
      c2++;
  }
  if (c1 != c2)
    return false;
  i = j = 0;
  while (i < n && j < n) {
    if (start[i] == 'X')
      i++;
    else if (end[j] == 'X')
      j++;
    else {
      if ((start[i] != end[j]) || (start[i] == 'L' && i < j) ||
          start[i] == 'R' && i > j)
        return false;
      i++, j++;
    }
  }
  return true;
}

int main() {
  char *s1 = "RXXLRXRXL", *e1 = "XRLXXRRLX", *s2 = "X", *e2 = "L";
  printf("%d\n", canTransform(s1, e1)); // expect: 1
  printf("%d\n", canTransform(s2, e2)); // expect: 0
}
