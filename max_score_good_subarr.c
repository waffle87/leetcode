// 1793. Maximum Score of a Good Subarray
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array of integers 'nums' (0-indexed) and an integer 'k'. the score
 * of a subarray '(i, j)' is defined as 'min(nums[i], nums[i + 1], ..., nums[j])
 * * (j - i + 1)'. a good subarray is a subarray where 'i <= k <= j'. return the
 * maximum possible score of a good subarray.
 */

int maximumScore(int *nums, int nums_size, int k) {
  int ans = 0, n = nums_size, left = k - 1, right = k + 1, min_val = nums[k];
  long long sum = nums[k];
  while (left >= 0 || right < n) {
    if (left >= 0 && nums[left] >= min_val) {
      sum += nums[left];
      left--;
    } else if (right < n && nums[right] >= min_val) {
      sum += nums[right];
      right++;
    } else {
      ans = fmax(ans, min_val * (right - left - 1));
      if (left >= 0 && right < n)
        min_val = fmax(nums[left], nums[right]);
      else if (left >= 0)
        min_val = nums[left];
      else
        min_val = nums[right];
    }
  }
  ans = fmax(ans, min_val * (right - left - 1));
  return ans;
}

int main() {
  int n1[] = {1, 4, 3, 7, 4, 5}, n2[] = {5, 5, 4, 5, 4, 1, 1, 1};
  printf("%d\n", maximumScore(n1, 6, 3)); // expect: 15
  printf("%d\n", maximumScore(n1, 8, 0)); // expect: 20
}
