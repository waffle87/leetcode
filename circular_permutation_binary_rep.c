// 1238. Circular Permutation in Binary Representation
#include "leetcode.h"

/*
 * given 2 integers 'n' and 'start', your task is to return any permutation of
 * '(0, 1, 2, ..., 2^n - 1)' such that 'p[0] = start', 'p[i]' and 'p[i + 1]'
 * differ by only one bit in their binary representation, and 'p[0]' and '[p2^n
 * - 1]' must also differ by oly one bit in their binary repesentation.
 */

int *circularPermutation(int n, int start, int *returnSize) {
  int x = pow(2, n), curr = 1, begin;
  *returnSize = x;
  int *tmp = (int *)malloc(x * sizeof(int));
  tmp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < curr; j++)
      tmp[curr + j] = tmp[curr - 1 - j] + (1 << i);
    curr *= 2;
  }
  for (int i = 0; i < x; i++)
    if (tmp[i] == start) {
      begin = i;
      break;
    }
  int *ans = (int *)malloc(x * sizeof(int));
  memcpy(ans, &tmp[begin], (x - begin) * sizeof(int));
  memcpy(&ans[x - begin], tmp, begin * sizeof(int));
  free(tmp);
  return ans;
}

int main() {
  int rs1, *cp1 = circularPermutation(2, 3, &rs1);
  int rs2, *cp2 = circularPermutation(3, 2, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", cp1[i]); // expect: 3 2 0 1
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", cp2[i]); // expect: 2 6 7 5 4 0 1 3
  printf("\n");
  free(cp1);
  free(cp2);
}
