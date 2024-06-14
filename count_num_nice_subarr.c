// 1248. Count Number of Nice Subarrays
#include "leetcode.h"

/*
 * given an array of integers 'nums' and an integers 'k'. a continuous subarray
 * is called nice if there are 'k' odd numbers on it. return the number of nice
 * subarrays.
 */

int process(int *nums, int numsSize, int k) {
  int odd_cnt = 0, r = 0, l = 0, ans = 0;
  for (; r < numsSize; r++) {
    if (nums[r] % 2)
      odd_cnt++;
    while (odd_cnt > k) {
      if (nums[l] % 2)
        odd_cnt--;
      l++;
    }
    ans += r - l + 1;
  }
  return ans;
}

int numberOfSubarrays(int *nums, int numsSize, int k) {
  return process(nums, numsSize, k) - process(nums, numsSize, k - 1);
}

int main() {
  int n1[] = {1, 1, 2, 1, 1}, n2[] = {2, 4, 6},
      n3[] = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
  printf("%d\n", numberOfSubarrays(n1, ARRAY_SIZE(n1), 3)); // expect: 2
  printf("%d\n", numberOfSubarrays(n2, ARRAY_SIZE(n2), 1)); // expect: 0
  printf("%d\n", numberOfSubarrays(n3, ARRAY_SIZE(n3), 2)); // expect: 16
}
