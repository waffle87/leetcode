// 977. Squares of a Sorted Array
#include "leetcode.h"

/*
 * given an integer array 'nums' sorted in non-decreasing order, return an array
 * of the squares sorted in non-decreasing order.
 */

int *sortedSquares(int *nums, int numsSize, int *returnSize) {
  int *ans = malloc(sizeof(int) * numsSize);
  *returnSize = numsSize;
  int end = numsSize - 1, start = 0, ptr = numsSize - 1;
  while (start <= end && ptr >= 0) {
    ans[ptr] = pow(nums[end], 2) >= pow(nums[start], 2) ? pow(nums[end--], 2)
                                                        : pow(nums[start++], 2);
    ptr--;
  }
  return ans;
}

int main() {
  int n1[] = {-4, -1, 0, 3, 10}, n2[] = {-7, -3, 2, 3, 11};
  int *rs1 = (int *)malloc(sizeof(int)), *rs2 = (int *)malloc(sizeof(int));
  int *ss1 = sortedSquares(n1, ARRAY_SIZE(n1), rs1);
  int *ss2 = sortedSquares(n2, ARRAY_SIZE(n2), rs2);
  for (int i = 0; i < ARRAY_SIZE(n1); i++)
    printf("%d ", ss1[i]); // expect: 0 1 9 16 100
  printf("\n");
  for (int i = 0; i < ARRAY_SIZE(n2); i++)
    printf("%d ", ss2[i]); // expect: 4 9 9 49 121
  printf("\n");
}
