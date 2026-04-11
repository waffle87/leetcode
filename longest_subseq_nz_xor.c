// 3702. Longest Subsequence With Non-Zero Bitwise XOR
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. return the length of the longest
 * subsequence in 'nums' whose bitwise xor is non zero. if no such subsequence
 * exists, return 0.
 */

int longestSubsequence(int *nums, int numsSize) {
  int sum = 0;
  bool pos = false;
  for (int i = 0; i < numsSize; i++) {
    pos |= (bool)nums[i];
    sum ^= nums[i];
  }
  return pos ? numsSize - !sum : 0;
}

int main() {
  int n1[] = {1, 2, 3}, n2[] = {2, 3, 4};
  int r1 = longestSubsequence(n1, ARRAY_SIZE(n1));
  int r2 = longestSubsequence(n2, ARRAY_SIZE(n2));
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 3);
}
