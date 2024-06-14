// 1404. Number of Steps to Reduce a Number in Binary Representation to One
#include "leetcode.h"

/*
 * given the binary representation of an integer as a string 's', return the
 * number of steps to reduce it to 1 under the following rules. if the current
 * number is even, you have to divide it by 2. if the current number is odd, you
 * have to add 1 to it. it is guaranteed that you can always reach one for all
 * test cases.
 */

int numSteps(char *s) {
  int n = strlen(s), k = n / 2;
  char *tmp = (char *)malloc((n + k + 1) * sizeof(char));
  for (int i = 0; i < k; i++)
    tmp[i] = '0';
  strncpy(&tmp[k], s, n + 1);
  int l = k, r = n + k - 1, step = 0;
  while (l != r) {
    if (tmp[r] == '0')
      r--;
    else if (tmp[r] == '1') {
      tmp[r] = '0';
      int m = r - 1;
      while (1) {
        if (tmp[m] == '0') {
          tmp[m] = '1';
          if (m < l)
            l = m;
          break;
        } else {
          tmp[m] = '0';
        }
        m--;
      }
    }
    step++;
  }
  return step;
}

int main() {
  char *s1 = "1101", *s2 = "10", *s3 = "1";
  printf("%d\n", numSteps(s1)); // expect: 6
  printf("%d\n", numSteps(s2)); // expect: 1
  printf("%d\n", numSteps(s3)); // expect: 0
}
