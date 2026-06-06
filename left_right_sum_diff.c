// 2574. Left and Right Sum Differences
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums' of size 'n'. define two arrays
 * 'leftSum' and 'rightSum' where 'leftSum[i]' is the sum of elements to the
 * left of index 'i' in the array 'nums'. if there is no such element,
 * 'leftSum[i] = 0'. and vice-versa for 'rightSum'. return an integer array
 * 'answer' of size 'n' where 'answer[i] = |leftSum[i] - rightSum[i]|'.
 */

int *leftRightDifference(int *nums, int numsSize, int *returnSize) {
  *returnSize = numsSize;
  int *left_sum = (int *)calloc(numsSize, sizeof(int));
  int *right_sum = (int *)calloc(numsSize, sizeof(int));
  int *ans = (int *)malloc(numsSize * sizeof(int));
  for (int i = 1; i < numsSize; i++)
    left_sum[i] = left_sum[i - 1] + nums[i - 1];
  for (int j = numsSize - 2; j >= 0; j--)
    right_sum[j] = right_sum[j + 1] + nums[j + 1];
  for (int k = 0; k < numsSize; k++)
    ans[k] = abs(left_sum[k] - right_sum[k]);
  free(left_sum);
  free(right_sum);
  return ans;
}

int main() {
  int n1[] = {10, 4, 8, 3}, rs1, r1[] = {15, 1, 11, 22};
  int n2[] = {1}, rs2, r2[] = {0};
  int *lrd1 = leftRightDifference(n1, ARRAY_SIZE(n1), &rs1);
  int *lrd2 = leftRightDifference(n2, ARRAY_SIZE(n2), &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", lrd1[i]);
    assert(lrd1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", lrd2[i]);
    assert(lrd2[i] == r2[i]);
  }
  printf("\n");
  free(lrd1);
  free(lrd2);
}
