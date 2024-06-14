// 713. Subarray Product Less Than K
#include "leetcode.h"

/*
 * given an array of integers 'nums' and an integer 'k', return the number of
 * contiguous subarrays where the product of all the elements in the subarray is
 * strictly less than 'k'.
 */

int numSubarrayProductLessThanK(int *nums, int numsSize, int k) {
  int n = numsSize, ans = 0, prod = 0, line = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (i == j) {
        prod = nums[i];
        if (prod < k) {
          line++;
          continue;
        } else
          break;
      } else {
        prod *= nums[j];
        if (prod < k)
          line++;
        else
          break;
        ;
      }
    }
    if (line == n - i)
      break;
    else
      ans += line;
  }
  for (int i = line; i >= 0; i--)
    ans += i;
  return ans;
}

int main() {
  int n1[] = {10, 5, 2, 6}, n2[] = {1, 2, 3};
  printf("%d\n",
         numSubarrayProductLessThanK(n1, ARRAY_SIZE(n1), 100)); // expect: 8
  printf("%d\n",
         numSubarrayProductLessThanK(n2, ARRAY_SIZE(n2), 0)); // expect: 0
}
