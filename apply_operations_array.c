// 2460. Apply Operations to an Array
#include "leetcode.h"

/*
 * you are given 0-indexed array 'nums' of size 'n' consisting of non-negative
 * integers. you need to apply 'n - 1' operations to this array where in the
 * i'th operation (0-indexed), you will apply the following on the i'th element
 * of 'nums': if 'nums[i] == nums[i + 1]', then multiply 'nums[i]' by 2 and set
 * 'nums[i + 1]' to operate 0. otherwise, you skip this operation. after
 * performing all the operations, shift all the 0's to the end of the array.
 * return the resulting array. note that the operations are applied sequentially
 * not all at once.
 */

int *applyOperations(int *nums, int numsSize, int *returnSize) {
  for (int i = 0; i < numsSize - 1; i++)
    if (nums[i] == nums[i + 1] && nums[i]) {
      nums[i] *= 2;
      nums[i + 1] = 0;
    }
  int *ans = (int *)malloc(numsSize * sizeof(int)), j = 0;
  *returnSize = numsSize;
  for (int i = 0; i < numsSize; i++)
    if (nums[i])
      ans[j++] = nums[i];
  while (j < numsSize)
    ans[j++] = 0;
  return ans;
}

int main() {
  int n1[] = {1, 2, 2, 1, 1, 0}, n2[] = {0, 1}, rs1, rs2;
  int *ao1 = applyOperations(n1, ARRAY_SIZE(n1), &rs1);
  int *ao2 = applyOperations(n2, ARRAY_SIZE(n2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", ao1[i]); // expect: 1 4 2 0 0 0
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", ao2[i]); // expect: 1 0
  printf("\n");
  free(ao1), free(ao2);
}
