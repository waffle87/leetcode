// 2161. Partition Array According to Given Pivot
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums' and an integer 'pivot'.
 * rearrange 'nums' such that the following conditions are satisfied: every
 * element less than 'pivot' appears befor every element greater than 'pivot',
 * every element equal to 'pivot' appears in between the elements less than and
 * greater than 'pivot', the relative order of the elments less than 'pivot' and
 * the elements greater than 'pivot' is maintained. return 'nums' after the
 * rearrangement
 */

int *pivotArray(int *nums, int numsSize, int pivot, int *returnSize) {
  int *ans = (int *)malloc(numsSize * sizeof(int));
  int idx = 0;
  for (int i = 0; i < numsSize; i++)
    if (nums[i] < pivot)
      ans[idx++] = nums[i];
  for (int i = 0; i < numsSize; i++)
    if (nums[i] == pivot)
      ans[idx++] = nums[i];
  for (int i = 0; i < numsSize; i++)
    if (nums[i] > pivot)
      ans[idx++] = nums[i];
  *returnSize = numsSize;
  return ans;
}

int main() {
  int n1[] = {9, 12, 5, 10, 14, 3, 10}, rs1;
  int n2[] = {-3, 4, 3, 2}, rs2;
  int *pa1 = pivotArray(n1, ARRAY_SIZE(n1), 10, &rs1);
  int *pa2 = pivotArray(n2, ARRAY_SIZE(n2), 2, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", pa1[i]); // expect: 9,5,3,10,10,12,14
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", pa2[i]); // expect: -3,2,4,3
  printf("\n");
  free(pa1);
  free(pa2);
}
