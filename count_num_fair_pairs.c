// 2563. Count the Number of Fair Pairs
#include "leetcode.h"

/*
 * given a 0 indexed integer array 'nums' of size 'n', and two integers 'lower'
 * and 'upper', return the number of fair pairs. pair '(i, j)' is fair is '0 <=
 * i < j < n' and 'lower <= nums[i] + nums[j] <= upper'
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int bs_lower(int *nums, int n, int left, int right, int lower) {
  int l = left, r = right;
  if (nums[r] < lower)
    return -1;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (nums[m] < lower)
      l = m + 1;
    else
      r = m;
  }
  return l;
}

int bs_upper(int *nums, int n, int left, int right, int upper) {
  int l = left, r = right;
  if (nums[l] > upper)
    return -1;
  while (l < r) {
    int m = r - (r - l) / 2;
    if (nums[m] > upper)
      r = m - 1;
    else
      l = m;
  }
  return l;
}

long long countFairPairs(int *nums, int numsSize, int lower, int upper) {
  int n = numsSize;
  long long ans = 0;
  qsort(nums, n, sizeof(int), cmp);
  for (int i = 0; i < n - 1; i++) {
    int left = bs_lower(nums, n, i + 1, n - 1, lower - nums[i]);
    int right = bs_upper(nums, n, i + 1, n - 1, upper - nums[i]);
    if (left != -1 && right != -1)
      ans += right - left + 1;
  }
  return ans;
}

int main() {
  int n1[] = {0, 1, 7, 4, 4, 5}, n2[] = {1, 7, 9, 2, 5};
  printf("%lld\n", countFairPairs(n1, ARRAY_SIZE(n1), 3, 6));   // expect: 6
  printf("%lld\n", countFairPairs(n2, ARRAY_SIZE(n2), 11, 11)); // expect: 1
}
