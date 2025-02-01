// 3151. Special Array I
#include "leetcode.h"

/*
 * an array is considered special if every pair of its adjacent elements
 * contains two numbers with different parity. you are given an array of
 * integers 'nums'. return 'true' if 'nums' is a special array, otherwise return
 * 'false'.
 */

bool isArraySpecial(int *nums, int numsSize) {
  for (int i = 0; i < numsSize; i++)
    if (!(nums[i - 1] & 1) ^ (nums[i] & 1))
      return false;
  return true;
}

int main() {
  int n1[] = {1}, n2[] = {2, 1, 4}, n3[] = {4, 3, 1, 6};
  printf("%d\n", isArraySpecial(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", isArraySpecial(n2, ARRAY_SIZE(n2))); // expect: 1
  printf("%d\n", isArraySpecial(n3, ARRAY_SIZE(n3))); // expect: 0
}
