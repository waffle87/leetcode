// 1304. Find N Unique Integers Sum up to Zero
#include "leetcode.h"

/*
 * given an integer 'n', return any array containing 'n' unique integers such
 * that they add up to 0.
 */

int *sumZero(int n, int *returnSize) {
  int *ans = (int *)malloc(n * sizeof(int));
  *returnSize = n;
  for (int i = 0; i < n; ++i)
    ans[i] = i * 2 - n + 1;
  return ans;
}

int main() {
  int rs1, *sz1 = sumZero(5, &rs1);
  int rs2, *sz2 = sumZero(3, &rs2);
  int rs3, *sz3 = sumZero(1, &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", sz1[i]); // expect: -7 -1 1 3 4
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", sz2[i]); // expect: -1 0 1
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", sz3[i]); // expect: 0
  printf("\n");
  free(sz1);
  free(sz2);
  free(sz3);
}
