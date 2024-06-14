// 1685. Sum of Absolute Differences in a Sorted Array
#include "leetcode.h"

/*
 * you are given an integer array 'nums' sorted in non-decreasing order. build
 * and return an integer array 'result' with the same length as 'nums' such that
 * 'result[i] is equal to the summation of absolute differences between 'nums[i]
 * and all the other elements in the array. in other words, 'result[i] is equal
 * to 'sum(|nums[i] - nums[j]|) where '0 <= j < nums.length()' and 'j != i'.
 */

int *getSumAbsoluteDifferences(int *nums, int nums_size, int *return_size) {
  *return_size = nums_size;
  int sum = 0, tmp_sum = 0;
  for (int i = 0; i < nums_size; i++)
    sum += nums[i];
  int *ans = (int *)malloc(nums_size * sizeof(int));
  for (int i = 0; i < nums_size; i++) {
    tmp_sum += nums[i];
    int tmp = sum + (2 * i - nums_size) * nums[i];
    ans[i] = !i ? tmp : tmp - 2 * (tmp_sum - nums[i]);
  }
  return ans;
}

int main() {
  int n1[] = {2, 3, 5}, n2[] = {1, 4, 6, 8, 10};
  int rs1[] = {}, rs2[] = {};
  int *gsad1 = getSumAbsoluteDifferences(n1, ARRAY_SIZE(n1), rs1);
  int *gsad2 = getSumAbsoluteDifferences(n2, ARRAY_SIZE(n2), rs2);
  for (int i = 0; i < ARRAY_SIZE(n1); i++)
    printf("%d ", gsad1[i]); // expect: 4 3 5
  printf("\n");
  for (int i = 0; i < ARRAY_SIZE(n2); i++)
    printf("%d ", gsad2[i]); // expect: 24 15 13 15 21
  printf("\n");
}
