// 1524. Number of Sub-arrays With Odd Sum
#include "leetcode.h"

/*
 * given an array of integers 'arr', return the number of subarrays with an odd
 * sum. since the answer can be very large, return it modulo 10e9+7.
 */

int numOfSubarrays(int *arr, int arrSize) {
  int curr = 0, ans = 0, cnt[] = {1, 0}, mod = 1e9 + 7;
  for (int i = 0; i < arrSize; i++) {
    curr ^= arr[i] & 1;
    ans = (ans + cnt[1 - curr]) % mod;
    cnt[curr]++;
  }
  return ans;
}

int main() {
  int a1[] = {1, 3, 5}, a2[] = {2, 4, 6}, a3[] = {1, 2, 3, 4, 5, 6, 7};
  printf("%d\n", numOfSubarrays(a1, ARRAY_SIZE(a1))); // expect: 4
  printf("%d\n", numOfSubarrays(a2, ARRAY_SIZE(a2))); // expect: 0
  printf("%d\n", numOfSubarrays(a3, ARRAY_SIZE(a3))); // expect: 16
}
