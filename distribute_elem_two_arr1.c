// 3069. Distribute Elements Into Two Arrays I
#include "leetcode.h"

/*
 * you are given a 1-indexed array of distinct integers 'nums' of length 'n'.
 * you need to distribute all the elements of 'nums' between two arrays 'arr1'
 * and 'arr2' using 'n' operations. in the first operation, append 'nums[1]' to
 * 'arr1'. in the second operation, append 'nums[2]' to 'arr2'. afterwards, in
 * the i'th operation, if the last element of 'arr1' is greater than the last
 * element of 'arr2', append 'nums[i]' to 'arr1'. otherwise, append 'nums[i]' to
 * 'arr2'. the array 'result' is formed by concatenating the arrays 'arr1' and
 * 'arr2'. return the array 'result'.
 */

int *resultArray(int *nums, int numsSize, int *returnSize) {
  int *distributed = (int *)malloc(numsSize * sizeof(int));
  int idx1 = 0, idx2 = numsSize - 1;
  distributed[idx1] = nums[0];
  distributed[idx2] = nums[1];
  for (int i = 2; i < numsSize; i++) {
    if (distributed[idx1] > distributed[idx2])
      distributed[++idx1] = nums[i];
    else
      distributed[--idx2] = nums[i];
  }
  *returnSize = 0;
  for (int i = 0; i <= idx1; i++)
    nums[(*returnSize)++] = distributed[i];
  for (int i = numsSize - 1; i >= idx2; i--)
    nums[(*returnSize)++] = distributed[i];
  free(distributed);
  return nums;
}

int main() {
  int n1[] = {2, 1, 3}, r1[] = {2, 3, 1};
  int n2[] = {5, 4, 3, 8}, r2[] = {5, 3, 4, 8};
  int rs1, *ra1 = resultArray(n1, ARRAY_SIZE(n1), &rs1);
  int rs2, *ra2 = resultArray(n2, ARRAY_SIZE(n2), &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", ra1[i]);
    assert(ra1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", ra2[i]);
    assert(ra2[i] == r2[i]);
  }
  printf("\n");
}
