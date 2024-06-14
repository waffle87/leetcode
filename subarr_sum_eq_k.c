// 560. Subarray Sum Equals K
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array of integers 'nums' and an integer 'k', return the total number
 * of subarrays whose sum equals to 'k'. a subarray is a contiguous non-empty
 * sequence of elements within an array.
 */

int subarraySum(int *nums, int nums_size, int k) {
  int i, j, base = nums_size * 1000, prefix = 0;
  int *hash_map = calloc(base * 2 + 1, sizeof(int));
  hash_map[base]++;
  int ans = 0;
  for (int i = 1; i <= nums_size; i++) {
    prefix += nums[i - 1];
    int rem = prefix - k;
    ans += hash_map[rem + base];
    hash_map[base + prefix]++;
  }
  free(hash_map);
  return ans;
}

int main() {
  int n1[] = {1, 1, 1}, n2[] = {1, 2, 3};
  printf("%d\n", subarraySum(n1, 3, 2)); // expect: 2
  printf("%d\n", subarraySum(n2, 3, 3)); // expect: 2
}
