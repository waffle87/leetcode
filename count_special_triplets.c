// 3583. Count Special Triplets
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. a special triplet is defined as a
 * triplet of indices '(i, j, k)' such that '0 <= i < j < k < n' where 'n =
 * len(nums)', 'nums[i] == nums[j] * 2', 'nums[k] == nums[j] * 2'. return the
 * total number of special triplets in the array. since the answer may be very
 * large, return it modulo 10^9 + 7.
 */

int specialTriplets(int *nums, int numsSize) {
  static int mod = 1e9 + 7;
  int max = 0;
  for (int i = 0; i < numsSize; ++i)
    if (max < nums[i])
      max = nums[i];
  int max_size = 2 * max + 1;
  long long *left = (long long *)calloc(max_size, sizeof(long long));
  long long *right = (long long *)calloc(max_size, sizeof(long long));
  for (int i = 0; i < numsSize; ++i)
    right[nums[i]]++;
  long long ans = 0;
  for (int i = 0; i < numsSize; i++) {
    right[nums[i]]--;
    int val = nums[i] * 2;
    long long lval = left[val], rval = right[val];
    ans = (ans + (lval * rval)) % mod;
    left[nums[i]]++;
  }
  free(left);
  free(right);
  return (int)ans;
}

int main() {
  int n1[] = {6, 3, 6}, n2[] = {0, 1, 0, 0}, n3[] = {8, 4, 2, 8, 4};
  printf("%d\n", specialTriplets(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", specialTriplets(n2, ARRAY_SIZE(n2))); // expect: 1
  printf("%d\n", specialTriplets(n3, ARRAY_SIZE(n3))); // expect: 2
}
