// 2563. Count the Number of Fair Pairs
#include "leetcode.h"

/*
 * given a 0 indexed integer array 'nums' of size 'n', and two integers 'lower'
 * and 'upper', return the number of fair pairs. pair '(i, j)' is fair is '0 <=
 * i < j < n' and 'lower <= nums[i] + nums[j] <= upper'
 */

int cmp(const void *a, const void *b) {
  return (*(int *)a > *(int *)b) - (*(int *)b > *(int *)a);
}

long long countFairPairs(int *nums, int numsSize, int lower, int upper) {
  qsort(nums, numsSize, sizeof(int), cmp);
  long long ans = 0;
  int i = 0, j = numsSize - 1;
  while (i < j)
    if (nums[i] + nums[j] < lower)
      ans -= j - i++;
    else
      j--;
  i = 0, j = numsSize - 1;
  while (i < j)
    if (nums[i] + nums[j] <= upper)
      ans += j - i++;
    else
      j--;
  return ans;
}

int main() {
  int n1[] = {0, 1, 7, 4, 4, 5}, n2[] = {1, 7, 9, 2, 5};
  printf("%lld\n", countFairPairs(n1, ARRAY_SIZE(n1), 3, 6));   // expect: 6
  printf("%lld\n", countFairPairs(n2, ARRAY_SIZE(n2), 11, 11)); // expect: 1
}
