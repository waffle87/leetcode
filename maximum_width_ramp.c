// 962. Maximum Width Ramp
#include "leetcode.h"

/*
 * a ramp in an integer array 'nums' is a pair '(i, j)' for which 'i < j' and
 * 'nums[i] <= nums[j]'. the width of such ramp is 'j - i'. given an integer
 * array 'nums', return the maximum width of a ramp in 'nums' if there is no
 * ramp in 'nums', return 0
 */

int maxWidthRamp(int *nums, int numsSize) {
  int ans = 0, idx = 0;
  int *stack = (int *)malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; i++) {
    if (!idx)
      stack[idx++] = i;
    else {
      if (nums[i] <= nums[stack[idx - 1]])
        stack[idx++] = i;
    }
  }
  for (int i = numsSize - 1; i >= 0; i--)
    while (idx && nums[i] >= nums[stack[idx - 1]])
      ans = fmax(ans, i - stack[--idx]);
  free(stack);
  return ans;
}

int main() {
  int n1[] = {6, 0, 8, 2, 1, 5}, n2[] = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
  printf("%d\n", maxWidthRamp(n1, ARRAY_SIZE(n1))); // expect: 4
  printf("%d\n", maxWidthRamp(n2, ARRAY_SIZE(n2))); // expect: 7
}
