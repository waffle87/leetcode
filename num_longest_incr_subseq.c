// 673. Number of Longest Increasing Subsequence
#include <stdio.h>

/*
 * given an integer array 'nums', return the number of longest increasing
 * subsequences. notice that the sequence has to strictly increasing.
 */

int findNumberOfLIS(int *nums, int nums_size) {
  if (!nums_size)
    return 0;
  int sec_len[nums_size], sec_num[nums_size];
  int max_len = 0, max_num = 0;
  for (int i = 0; i < nums_size; ++i) {
    int num = 1, len = 0;
    for (int j = 0; j < i; ++j) {
      if (nums[j] < nums[i]) {
        if (len < sec_len[j]) {
          len = sec_len[j];
          num = sec_len[j];
        } else if (len == sec_len[j])
          num += sec_num[j];
      }
    }
    sec_len[i] = ++len;
    sec_num[i] = num;
    if (len >= max_len)
      max_len = len;
  }
  for (int i = 0; i < nums_size; ++i)
    if (max_len == sec_len[i])
      max_num += sec_num[i];
  return max_num;
}

int main() {
  int n1[] = {1, 3, 5, 4, 7}, n2[] = {2, 2, 2, 2, 2};
  printf("%d\n", findNumberOfLIS(n1, 5)); // expect: 2
  printf("%d\n", findNumberOfLIS(n2, 5)); // expect: 5
}
