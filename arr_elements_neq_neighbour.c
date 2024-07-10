// 1968. Array With Elements Not Equal to Average of Neighbors
#include "leetcode.h"

/*
 * you are given a 0-indexed array 'nums' of distinct integers. you want to
 * rearrange the elements in the array such that every element in the rearranged
 * array is not equal to the average of its neighbors. more formally the
 * rearranged array should have the property such that for every 'i' in the
 * range '1 <= nums.len - 1', '(nums[i - 1] + nums[i + 1]) / 2' is not equal to
 * 'nums[i]'. return any rearrangement of 'nums' that meets the requirements.
 */

void swap(int *x, int *y) {
  if (x == y)
    return;
  *x ^= *y;
  *y ^= *x;
  *x ^= *y;
}

int *rearrangeArray(int *nums, int numsSize, int *returnSize) {
  int *ans = (int *)malloc(numsSize * sizeof(int)), i, j = 0;
  *returnSize = numsSize;
  for (int i = 1; i < numsSize - 1; i++)
    if (nums[i] * 2 == nums[i - 1] + nums[i + 1])
      swap(&nums[i], &nums[i + 1]);
  for (int i = numsSize - 2; i; i--)
    if (nums[i] * 2 == nums[i - 1] + nums[i + 1])
      swap(&nums[i], &nums[i - 1]);
  return ans;
}

int main() {
  int n1[] = {1, 2, 3, 4, 5}, n2[] = {6, 2, 0, 9, 7}, rs1, rs2;
  int *ra1 = rearrangeArray(n1, ARRAY_SIZE(n1), &rs1);
  int *ra2 = rearrangeArray(n2, ARRAY_SIZE(n2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", ra1[i]); // expect: 1,2,4,5,3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", ra2[i]); // expect: 9,7,6,2,0
  printf("\n");
  free(ra1), free(ra2);
}
