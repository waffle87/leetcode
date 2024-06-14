// 2317. Maximum XOR After Operations
#include "leetcode.h"

/*
 * given a 0-indexed integer array 'nums'. in one operations, select any
 * non-negative integer 'x' and an index 'i' then update 'nums[i]' to be equal
 * to 'nums[i] & (nums[i] ^ x)'. return the maximum possible bitwsie xor of all
 * elements after applying the operation any number of times.
 */

int maximumXOR(int *nums, int numsSize) {
  int ans = 0;
  for (int i = 0; i < numsSize; i++)
    // 0 | 3 = 3
    // 3 | 2 = 3
    // 3 | 4 = 7
    // 7 | 6 = 7
    ans |= nums[i];
  return ans;
}

int main() {
  int n1[] = {3, 2, 4, 6}, n2[] = {1, 2, 3, 9, 2};
  printf("%d\n", maximumXOR(n1, ARRAY_SIZE(n1))); // expect: 7
  printf("%d\n", maximumXOR(n2, ARRAY_SIZE(n2))); // expect: 11
}
