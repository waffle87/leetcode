// 1027. Longest Arithmetic Subsequence
#include <stdio.h>
#include <string.h>

/*
 * given an array 'nums' of integers, return the length of the longest
 * arithmetic subsequence in 'nums'. note that
 * - a subsequence is an array that can be derived from another array by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 * - a sequence 'seq' is arithmetic if 'seq[i + 1] - seq[i]' are all the same
 * value (for '0 <= i < seq.len() - 1')
 */

int longestArithSeqLength(int *nums, int nums_size) {
  if (!nums)
    return 0;
  int min = nums[0], max = min;
  for (int i = 0; i < nums_size; i++) {
    if (nums[i] < min)
      min = nums[i];
    if (nums[i] > max)
      max = nums[i];
  }
  int tmp = max - min, map[nums_size][2 * tmp + 1], ans = 0;
  memset(map, 0, sizeof(map[0][0]) * nums_size * (2 * tmp + 1));
  for (int i = 0; i < nums_size; i++)
    for (int j = 0; j < i; j++) {
      int diff = nums[i] - nums[j] + tmp;
      map[i][diff] = map[j][diff] + 1;
      if (map[i][diff] > ans)
        ans = map[i][diff];
    }
  return ans + 1;
}

int main() {
  int n1[] = {3, 6, 9, 12}, ns1 = 4;
  int n2[] = {9, 4, 7, 2, 10}, ns2 = 5;
  int n3[] = {20, 1, 15, 3, 10, 5, 8}, ns3 = 7;
  printf("%d\n", longestArithSeqLength(n1, ns1)); // expect: 4
  printf("%d\n", longestArithSeqLength(n2, ns2)); // expect: 3
  printf("%d\n", longestArithSeqLength(n3, ns3)); // expect: 4
}
