// 1356. Sort Integers by The Number of 1 Bits
#include "leetcode.h"

/*
 * given an integer array 'arr', sort the integers in the array in ascending
 * order by the number of 1's in their binary representation and in case of two
 * or more integers have the same number of 1's, you have to sort them in
 * ascending order. return the array after sorting it.
 */

int cmp(const void *a, const void *b) {
  int aa = *(int *)a, bb = *(int *)b;
  int bca = __builtin_popcount(aa);
  int bcb = __builtin_popcount(bb);
  if (bca == bcb)
    return aa < bb ? -1 : aa > bb ? 1 : 0;
  return bca < bcb ? -1 : 1;
}

int *sortByBits(int *arr, int arrSize, int *returnSize) {
  qsort(arr, arrSize, sizeof(int), cmp);
  *returnSize = arrSize;
  return arr;
}

int main() {
  int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8}, rs1;
  int r1[] = {0, 1, 2, 4, 8, 3, 5, 6, 7};
  int a2[] = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1}, rs2;
  int r2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
  int *sbb1 = sortByBits(a1, ARRAY_SIZE(a1), &rs1);
  int *sbb2 = sortByBits(a2, ARRAY_SIZE(a2), &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", sbb1[i]); // expect: 0 1 2 4 8 3 5 6 7
    assert(sbb1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", sbb2[i]); // expect: 1 2 4 8 16 32 64 128 256 512 1024
    assert(sbb2[i] == r1[i]);
  }
  printf("\n");
}
