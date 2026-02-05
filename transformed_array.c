// 3379. Transformed Array
#include "leetcode.h"

/*
 * you are given an integer array 'nms' that represents a circular array. your
 * task is to create a new array 'res' of the same size, following these rules.
 * for each index 'i', perform the following independent actions. if 'nums[i] >
 * 0' start at index 'i' and move 'nums[i]' steps to the right in the circular
 * array. set 'ans[i]' to the value of the index where you land. if 'nums[i] <
 * 0', start at index 'i' and move 'abs(nums[i])' steps to the left in the
 * circular array. set 'ans[i]' to the value of the index where you land. return
 * new array 'ans'.
 */

int *constructTransformedArray(int *nums, int numsSize, int *returnSize) {
  const int shift = 1 << 7, mask = (1 << 8) - 1;
  *returnSize = numsSize;
  for (int i = 0; i < numsSize; i++)
    nums[i] += shift;
  for (int i = 0; i < numsSize; i++) {
    int curr = nums[i] - shift;
    int idx = ((i + curr) % numsSize + numsSize) % numsSize;
    int val = nums[idx] & mask;
    nums[i] |= val << 8;
  }
  for (int i = 0; i < numsSize; i++)
    nums[i] = (nums[i] >> 8) - shift;
  return nums;
}

int main() {
  int n1[] = {3, -2, 1, 1}, r1[] = {1, 1, 1, 3}, rs1;
  int n2[] = {-1, 4, -1}, r2[] = {-1, -1, 4}, rs2;
  int *ctfa1 = constructTransformedArray(n1, ARRAY_SIZE(n1), &rs1);
  int *ctfa2 = constructTransformedArray(n2, ARRAY_SIZE(n2), &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", ctfa1[i]);
    assert(r1[i] == ctfa1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", ctfa2[i]);
    assert(r2[i] == ctfa2[i]);
  }
  printf("\n");
}
