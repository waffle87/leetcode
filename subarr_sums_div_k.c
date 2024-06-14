// 974. Subarray Sums Divisible by K
#include "leetcode.h"

/*
 * given an integer array 'nums' and an integer 'k', return the number of non
 * empty subarrays that have a sum divisible by 'k'. a subarray is contiguous
 * part of an array.
 */

int subarraysDivByK(int *nums, int numsSize, int k) {
  int n = numsSize, sum = 0, ans = 0;
  int *hash = (int *)calloc(k, sizeof(int));
  hash[0] = 1;
  for (int i = 0; i < n; i++) {
    sum += nums[i];
    int val = sum + 10000 * k;
    while (val < 0)
      val += k;
    ans += hash[val % k];
    hash[val % k]++;
  }
  free(hash);
  return ans;
}

int main() {
  int n1[] = {4, 5, 0, -2, -3, 1}, n2[] = {5};
  printf("%d\n", subarraysDivByK(n1, ARRAY_SIZE(n1), 5)); // expect: 7
  printf("%d\n", subarraysDivByK(n2, ARRAY_SIZE(n2), 9)); // expect: 0
}
