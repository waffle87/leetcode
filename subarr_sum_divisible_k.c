// 974. Subarray Sums Divisible by K
#include <stdio.h>
#include <stdlib.h>

/*
 * given: integer array 'nums' and integer 'k'
 * return: number of non-empty subarrays that
 * have a sum divisible by 'k'.
 * a subarray is a contiguous part of an array
 */

int subarrayDivByK(int *nums, int numsSize, int k) {
  if (numsSize == 0)
    return 0;
  else if (numsSize == 1) {
    if (nums[0] % k == 0)
      return 1;
    else
      return 0;
  }
  int ans = 0, *n, *hash;
  n = malloc(numsSize * sizeof(int));
  hash = malloc(k * sizeof(int));
  for (int i = 0; i < k; i++)
    hash[i] = 0;
  n[0] = nums[0] % k;
  if (n[0] < 0)
    n[0] = n[0] + k;
  hash[n[0]]++;
  for (int i = 1; i < numsSize; i++) {
    nums[i] = nums[i] + nums[i - 1];
    n[i] = nums[i] % k;
    if (n[i] < 0)
      n[i] = n[i] + k;
    hash[n[i]]++;
  }
  ans += hash[0];
  for (int i = 0; i < k; i++)
    if (hash[i] > 1)
      ans += hash[i] * (hash[i] - 1) >> 1;
  return ans;
}

int main() {
  int nums1[] = {4, 5, 0, -2, -3, 1}, nums2[] = {5};
  printf("%d\n", subarrayDivByK(nums1, 6, 5)); // expect: 7
  printf("%d\n", subarrayDivByK(nums2, 1, 9)); // expect: 0
}
