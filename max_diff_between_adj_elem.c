// 3423. Maximum Difference Between Adjacent Elements in a Circular Array
#include "leetcode.h"

/*
 * given a circular array 'nums', find the maximum absolute difference between
 * adjacent elements. note, in a circular array, the first and last elements are
 * adjacent.
 */

int maxAdjacentDistance(int *nums, int numsSize) {
  int ans = abs(nums[0] - nums[numsSize - 1]);
  for (int i = 1; i < numsSize; i++) {
    int curr = abs(nums[i - 1] - nums[i]);
    ans = fmax(ans, curr);
  }
  return ans;
}

int main() {
  int n1[] = {1, 2, 4}, n2[] = {-5, -10, -5};
  printf("%d\n", maxAdjacentDistance(n1, ARRAY_SIZE(n2))); // expect: 3
  printf("%d\n", maxAdjacentDistance(n1, ARRAY_SIZE(n2))); // expect: 5
}
