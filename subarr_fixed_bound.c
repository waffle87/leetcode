// 2444. Count Subarrays With Fixed Bounds
#include <math.h>
#include <stdio.h>

/*
 * given integer array 'nums' and two integers 'min_k' and 'max_k'. a fixed
 * bound subarr of 'nums' is a subarray that satisfies the following conditions:
 * minimum value in subarray is equal to 'min_k'. the max value in subarray is
 * equal to 'max_k'. return number of fixed-bound subarrays.
 */

long long countSubarrays(int *nums, int nums_size, int min_k, int max_k) {
  long long ans = 0;
  int last_min_k = -1, last_max_k = -1, start = 0;
  for (int i = 0; i < nums_size; i++) {
    if (nums[i] > max_k || nums[i] < min_k)
      start = i + 1;
    if (nums[i] == max_k)
      last_max_k = i;
    if (nums[i] == min_k)
      last_min_k = i;
    int pos = fmin(last_max_k, last_min_k);
    if (start > pos)
      continue;
    ans += pos - start + 1;
  }
  return ans;
}

int main() {
  int n1[] = {1, 3, 5, 2, 7, 5}, n2[] = {1, 1, 1, 1};
  printf("%lld\n", countSubarrays(n1, 6, 1, 5)); // expect: 2
  printf("%lld\n", countSubarrays(n2, 4, 1, 1)); // expect: 10
}
