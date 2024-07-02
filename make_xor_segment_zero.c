// 1787. Make the XOR of All Segments Equal to Zero
#include "leetcode.h"

/*
 * given an array 'nums' and an integer 'k'. the xor of a segment '[left,
 * right]' where 'left <= right' is the xor of all the elements with indices
 * between 'left' and 'right', inclusive 'nums[left] xor nums[left + 1] xor ...
 * xor nums[right]'. return the minimum number of elements to change in the
 * array such that the 'xor' of all segments of size 'k' is equal to zero
 */

int minChanges(int *nums, int numsSize, int k) {
  int freq[k][1025], dp[k + 1][1025];
  memset(freq, 0, sizeof(freq));
  for (int i = 0; i <= k; i++)
    for (int j = 0; j < 1025; j++)
      dp[i][j] = 1e9 + 5;
  dp[0][0] = 0;
  for (int i = 0; i < numsSize; i++)
    freq[i % k][nums[i]]++;
  int prev_min = 0, prev_min2 = 1e9 + 5;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 1025; j++)
      for (int l = 0; l < numsSize; l += k)
        if ((j ^ nums[l]) < 1025)
          dp[i + 1][j ^ nums[l]] = fmin(
              dp[i + 1][j ^ nums[l]],
              dp[i][j] + ceil((numsSize - i) * 1.0 / k) - freq[i][nums[l]]);
    for (int j = 0; j < 1025; j++) {
      dp[i + 1][j] =
          fmin(dp[i + 1][j], ceil((numsSize - i) * 1.0 / k) + prev_min);
      prev_min2 = fmin(prev_min2, dp[i + 1][j]);
    }
    prev_min = prev_min2;
  }
  return dp[k][0];
}

int main() {
  int n1[] = {1, 2, 0, 3, 0}, n2[] = {3, 4, 5, 2, 1, 7, 3, 4, 7},
      n3[] = {1, 2, 4, 1, 2, 5, 1, 2, 6};
  printf("%d\n", minChanges(n1, ARRAY_SIZE(n1), 1)); // expect: 3
  printf("%d\n", minChanges(n2, ARRAY_SIZE(n2), 3)); // expect: 3
  printf("%d\n", minChanges(n3, ARRAY_SIZE(n3), 3)); // expect: 3
}
