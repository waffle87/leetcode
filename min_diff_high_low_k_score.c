// 1984. Minimum Difference Between Highest and Lowest of K Scores
#include "leetcode.h"

/*
 * you are given a 0 indexed integer array 'nums' where 'nums[i]' represents the
 * score of the i'th student. you are also given an integer 'k'. pick the scores
 * of any 'k' students from the array so that the difference betweenn the
 * highest and the lowest of the 'k' scores is minimised. return the minimum
 * possible difference.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int minimumDifference(int *nums, int numsSize, int k) {
  if (k == 1)
    return 0;
  qsort(nums, numsSize, sizeof(int), cmp);
  int ans = INT_MAX;
  for (int i = 0; i <= numsSize - k; i++)
    ans = fmin(ans, nums[i + k - 1] - nums[i]);
  return ans;
}

int main() {
  int n1[] = {90}, n2[] = {9, 4, 1, 7};
  printf("%d\n", minimumDifference(n1, ARRAY_SIZE(n1), 1)); // expect: 0
  printf("%d\n", minimumDifference(n2, ARRAY_SIZE(n2), 2)); // expect: 2
}
