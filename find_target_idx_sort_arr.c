// 2089. Find Target Indices After Sorting Array
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums' and a target element 'target'.
 * a target index is an index 'i' such that 'nums[i] == target'. return a list
 * of target indices of 'nums' after sorting 'nums' in non-decreasing order.
 */

int *targetIndices(int *nums, int numsSize, int target, int *returnSize) {
  int less = 0, equal = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] < target)
      less++;
    else if (nums[i] == target)
      equal++;
  }
  int *ans = (int *)malloc(equal * sizeof(int));
  for (int i = 0; i < equal; i++)
    ans[i] = less + i;
  *returnSize = equal;
  return ans;
}

int main() {
  int nums[] = {1, 2, 5, 2, 3};
  int rs1, r1[] = {1, 2};
  int rs2, r2[] = {3};
  int rs3, r3[] = {4};
  int *ti1 = targetIndices(nums, ARRAY_SIZE(nums), 2, &rs1);
  int *ti2 = targetIndices(nums, ARRAY_SIZE(nums), 3, &rs2);
  int *ti3 = targetIndices(nums, ARRAY_SIZE(nums), 5, &rs3);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", ti1[i]);
    assert(ti1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", ti2[i]);
    assert(ti2[i] == r2[i]);
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%d ", ti3[i]);
    assert(ti3[i] == r3[i]);
  }
  printf("\n");
  free(ti1);
  free(ti2);
  free(ti3);
}
