// 2401. Longest Nice Subarray
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array 'nums' consisting of positive integers. we call a subarray of
 * 'nums' nice if the bitwise AND of every pair of elements that are in
 * different positions in the subarray is equal to 0. return the length of the
 * longest nice subarray. a subarray is contiguous part of an array. note that
 * subarrays of length 1 are always considered nice.
 */

bool check(int *bit, int n) {
  for (int i = 0; i < n; i++)
    if (bit[i] > 1)
      return false;
  return true;
}

int longestNiceSubarray(int *nums, int nums_size) {
  int *bit = calloc(32, sizeof(int));
  int left = 0, right = 0;
  while (right < nums_size) {
    int k = nums[right], pos = 0;
    while (k) {
      if (k % 2 == 1)
        bit[pos]++;
      k /= 2;
      pos++;
    }
    right++;
    if (!check(bit, 32)) {
      k = nums[left];
      pos = 0;
      while (k) {
        if (k % 2 == 1)
          bit[pos]--;
        k /= 2;
        pos++;
      }
      left++;
    }
  }
  return right - left;
}

int main() {
  int n1[] = {1, 3, 8, 48, 10}, ns1 = 5;
  int n2[] = {3, 1, 5, 11, 13}, ns2 = 5;
  printf("%d\n", longestNiceSubarray(n1, ns1)); // expect: 3
  printf("%d\n", longestNiceSubarray(n2, ns2)); // expect: 1
}
