// 2657. Find the Prefix Common Array of Two Arrays
#include "leetcode.h"

/*
 * you are given two 0-indexed integer permutations 'a' and 'b' of length 'n'. a
 * prefix common array of 'a' and 'b' is an array 'c' such that 'c[i]' is equal
 * to the count of numbers that are present at or before the index 'i' in both
 * 'a' and 'b'. return the prefix common array of 'a' and 'b'. a sequence of 'n'
 * integers is called a permutation if it contains all integers from 1 to 'n'
 * exactly once.
 */

int *findThePrefixCommonArray(int *A, int ASize, int *B, int BSize,
                              int *returnSize) {
  int *ans = (int *)malloc(ASize * sizeof(int)), cnt = 0;
  int *vis = (int *)malloc((ASize + 1) * sizeof(int));
  for (int i = 0; i < ASize; i++) {
    if (++vis[A[i]] == 2)
      cnt++;
    if (++vis[B[i]] == 2)
      cnt++;
    ans[i] = cnt;
  }
  free(vis);
  *returnSize = ASize;
  return ans;
}

int main() {
  int a1[] = {1, 2, 3, 4}, b1[] = {3, 1, 2, 4}, rs1;
  int a2[] = {2, 3, 1}, b2[] = {3, 1, 2}, rs2;
  int *ftpca1 =
      findThePrefixCommonArray(a1, ARRAY_SIZE(a1), b1, ARRAY_SIZE(b1), &rs1);
  int *ftpca2 =
      findThePrefixCommonArray(a2, ARRAY_SIZE(a2), b2, ARRAY_SIZE(b2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", ftpca1[i]); // expect: 0 2 3 4
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", ftpca2[i]); // expect: 0 1 3
  printf("\n");
  free(ftpca1), free(ftpca2);
}
