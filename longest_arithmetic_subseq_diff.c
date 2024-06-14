// 1218. Longest Arithmetic Subsequence of Given Difference
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer array 'arr' and an integer 'difference', return the length
 * of the longest subsequence in 'arr' which is an arithmetic sequence such that
 * the difference between adjacent elements in the subsequence equals
 * 'difference'. a subsequence is a sequence that can be derived from 'arr' by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 */

int longestSubsequence(int *arr, int arr_size, int difference) {
  int idx, max = 0, cnt[20001] = {0};
  for (int i = 0; i < arr_size; i++) {
    idx = 10000 + arr[i];
    if (max < cnt[idx])
      max = cnt[idx];
    if (idx + difference >= 0 && idx + difference <= 2000)
      cnt[idx + difference] = cnt[idx] + 1;
  }
  return max + 1;
}

int main() {
  int a1[] = {1, 2, 3, 4}, a2[] = {1, 3, 5, 7},
      a3[] = {1, 5, 7, 8, 5, 3, 4, 2, 1};
  printf("%d\n", longestSubsequence(a1, 4, 1));  // expect: 4
  printf("%d\n", longestSubsequence(a2, 4, 1));  // expect: 1
  printf("%d\n", longestSubsequence(a3, 9, -2)); // expect: 4
}
