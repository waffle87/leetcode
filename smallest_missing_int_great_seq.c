// 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum
#include "leetcode.h"

/*
 * you are given a 0-indexed array of integers 'nums'. a prefix 'nums[0 ... i]'
 * is sequence if f or all '1 <= j <= i', 'nums[j] = nums[j - 1] + 1'. in
 * particular, the prefix consisting only of 'nums[0]' is sequential. return the
 * smallest integer 'x' missing from 'nums' such that 'x' is greater than or
 * equal to the sum of the longest sequential prefix.
 */

int missingInteger(int *nums, int numsSize) {
  int sum = 0, j = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (!i || nums[i] == nums[i - 1] + 1)
      sum += nums[i];
    else
      break;
  }
  while (j < numsSize) {
    if (nums[j] == sum) {
      sum++;
      j = 0;
    }
    j++;
  }
  return sum;
}

int main() {
  int n1[] = {1, 2, 3, 2, 5};
  int n2[] = {3, 4, 5, 1, 12, 14, 13};
  int r1 = missingInteger(n1, ARRAY_SIZE(n1));
  int r2 = missingInteger(n2, ARRAY_SIZE(n2));
  printf("%d\n", r1);
  assert(r1 == 6);
  printf("%d\n", r2);
  assert(r2 == 15);
}
