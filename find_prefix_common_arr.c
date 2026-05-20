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
  int *ans = (int *)malloc(ASize * sizeof(int));
  *returnSize = ASize;
  long long a = 0, b = 0;
  for (int i = 0; i < ASize; i++) {
    a |= (1LL << A[i]);
    b |= (1LL << B[i]);
    long long ab = a & b;
    ans[i] = __builtin_popcountll(ab);
  }
  return ans;
}

int main() {
  int a1[] = {1, 2, 3, 4}, b1[] = {3, 1, 2, 4}, r1[] = {0, 1, 3, 4};
  int a2[] = {2, 3, 1}, b2[] = {3, 1, 2}, r2[] = {0, 1, 3};
  int rs1, *ftpca1 = findThePrefixCommonArray(a1, ARRAY_SIZE(a1), b1,
                                              ARRAY_SIZE(b1), &rs1);
  int rs2, *ftpca2 = findThePrefixCommonArray(a2, ARRAY_SIZE(a2), b2,
                                              ARRAY_SIZE(b2), &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", ftpca1[i]);
    assert(ftpca1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", ftpca2[i]);
    assert(ftpca2[i] == r2[i]);
  }
  printf("\n");
  free(ftpca1);
  free(ftpca2);
}
