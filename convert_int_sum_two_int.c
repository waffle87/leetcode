// 1317. Convert Integer to the Sum of Two No-Zero Integers
#include "leetcode.h"

/*
 * no-zero integer is a positive integer that does not contain any 0 in its
 * decimal representation. given an integer 'n', return a list of two integers
 * '[a, b]' where 'a' and 'b' are no-zero integers and 'a + b = n'. the test
 * cases are generated such that there is at lease one valid solution. if there
 * are many valid solutions, you can return any of them
 */

int *getNoZeroIntegers(int n, int *returnSize) {
  int *ans = (int *)malloc(2 * sizeof(int));
  for (int i = 1; i < n; ++i) {
    int j = n - i, valid = 1;
    int a = i, b = j;
    while (a > 0) {
      if (!(a % 10)) {
        valid = false;
        break;
      }
      a /= 10;
    }
    while (b > 0 && valid) {
      if (!(b % 10)) {
        valid = false;
        break;
      }
      b /= 10;
    }
    if (valid) {
      ans[0] = i;
      ans[1] = j;
      *returnSize = 2;
      return ans;
    }
  }
  *returnSize = 0;
  return NULL;
}

int main() {
  int rs1, *gnzi1 = getNoZeroIntegers(2, &rs1);
  int rs2, *gnzi2 = getNoZeroIntegers(11, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", gnzi1[i]); // expect: 1 1
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", gnzi2[i]); // expect: 2 9
  printf("\n");
  free(gnzi1);
  free(gnzi2);
}
