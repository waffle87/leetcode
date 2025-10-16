// 3350. Adjacent Increasing Subarrays Detection II
#include "leetcode.h"
#include <math.h>

/*
 * given an array 'nums' of 'n' integers, your task is to find the maximum value
 * of 'k' for which there exists two adjacent subarrays of length 'k' each, such
 * that both subarrays are strictly increasing. specifically, check if there are
 * two subarrays of length 'k' starting at indices 'a' and 'b' where both
 * subarrays are strictly increasing, and the subarrays must be adjacent,
 * meaning 'b = a + k'. return the maximum possible value of 'k'. a subarrays is
 * a contiguous non-empty sequence of elements within an array
 */

int maxIncreasingSubarrays(int *nums, int numsSize) {
  int up = 1, pre = 0, ans = 0;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] > nums[i - 1])
      up++;
    else {
      pre = up;
      up = 1;
    }
    int half = up >> 1;
    int m = fmin(pre, up);
    int candidate = fmax(half, m);
    if (candidate > ans)
      ans = candidate;
  }
  return ans;
}

int main() {
  int n1[] = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1},
      n2[] = {1, 2, 3, 4, 4, 4, 4, 5, 6, 7};
  printf("%d\n", maxIncreasingSubarrays(n1, ARRAY_SIZE(n1))); // expect: 3
  printf("%d\n", maxIncreasingSubarrays(n2, ARRAY_SIZE(n2))); // expect: 2
}
