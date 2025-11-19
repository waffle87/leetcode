// 2154. Keep Multiplying Found Values by Two
#include "leetcode.h"

/*
 * you are given an array of integers 'nums'. you are also given an integer
 * 'original' which is the first number that needs to be searched for in 'nums'.
 * you then do the following: if 'original' is found in 'nums', multiply it by
 * two, otherwise stop the process. repeat this process with the new number as
 * long as you keep finding the number. return the final value of 'original'
 */

int findFinalValue(int *nums, int numsSize, int original) {
  int bits = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] % original)
      continue;
    nums[i] /= original;
    if (!(nums[i] & (nums[i] - 1)))
      bits |= nums[i];
  }
  int ans = bits + 1;
  return original * (ans & -ans);
}

int main() {
  int n1[] = {5, 3, 6, 1, 12}, n2[] = {2, 7, 9};
  printf("%d\n", findFinalValue(n1, ARRAY_SIZE(n1), 3)); // expect: 24
  printf("%d\n", findFinalValue(n2, ARRAY_SIZE(n2), 4)); // expect: 4
}
