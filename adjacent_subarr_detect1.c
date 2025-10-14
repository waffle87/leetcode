// 3349. Adjacent Increasing Subarrays Detection I
#include "leetcode.h"

/*
 * given an array 'nums' of 'n' integers and an integer 'k', determine whther
 * there exist two adjacent subarrays of length 'k' such that both subarrays are
 * strictly increasing. specifically, check if there are two subarrays starting
 * at indices 'a' and 'b' ('a < b') where both subarrays 'nums[a..a + k - 1]'
 * and 'nums[b..b + k - 1]' are strictly increasing, and the subarrays must be
 * adjacent, meaning 'b = a + k'. return true if it is possible to find two such
 * subarrays and 'false'  otherwise.
 */

bool hasIncreasingSubarrays(int *nums, int numsSize, int k) {
  int inc = 1, prev = 0, max_len = 0;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] > nums[i - 1])
      inc++;
    else {
      prev = inc;
      inc = 1;
    }
    max_len = fmax(max_len, fmax(inc >> 1, fmin(prev, inc)));
    if (max_len >= k)
      return true;
  }
  return false;
}

int main() {
  int n1[] = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1},
      n2[] = {1, 2, 3, 4, 4, 4, 4, 5, 6, 7};
  printf("%d\n", hasIncreasingSubarrays(n1, ARRAY_SIZE(n1), 3)); // expect: 1
  printf("%d\n", hasIncreasingSubarrays(n2, ARRAY_SIZE(n2), 5)); // expect: 0
}
