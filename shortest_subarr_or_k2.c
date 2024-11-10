// 3097. Shortest Subarray With OR at Least K II
#include "leetcode.h"

/*
 * you are given an array 'nums' of non-negative integers and an integer 'k'. an
 * array is called special if the bitwise OR of all its elements is at least
 * 'k'. return the length of the shortest special non-empty subarray of 'nums',
 * or return -1 if no special subarray exists.
 */

int minimumSubarrayLength(int *nums, int numsSize, int k) {
  int cnt[30] = {}, curr = 0, ans = INT_MAX;
  for (int i = 0, j = 0; i < numsSize; ++i) {
    for (int b = 0; b < 30; ++b)
      if ((1 << b) & nums[i])
        if (++cnt[b] == 1)
          curr += (1 << b);
    while (curr >= k && j <= i) {
      ans = fmin(ans, i - j + 1);
      for (int b = 0; b < 30; ++b)
        if ((1 << b) & nums[j])
          if (!(--cnt[b]))
            curr -= (1 << b);
      ++j;
    }
  }
  return ans == INT_MAX ? -1 : ans;
}

int main() {
  int n1[] = {1, 2, 3}, n2[] = {2, 1, 8}, n3[] = {1, 2};
  printf("%d\n", minimumSubarrayLength(n1, ARRAY_SIZE(n1), 2));  // expect: 1
  printf("%d\n", minimumSubarrayLength(n2, ARRAY_SIZE(n2), 10)); // expect: 3
  printf("%d\n", minimumSubarrayLength(n3, ARRAY_SIZE(n3), 0));  // expect: 1
}
