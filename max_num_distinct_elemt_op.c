// 3397. Maximum Number of Distinct Elements After Operations
#include "leetcode.h"

/*
 * you are given an integer array 'nums' and an integer 'k'. you are allowed to
 * perform the following operation on each element of the array at most once:
 * add a single integer in the range '[-k, k]' to the element. return the
 * maximum possible number of distinct elements in 'nums' after performing the
 * operation.
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int maxDistinctElements(int *nums, int numsSize, int k) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int ans = 0, prev = INT_MIN;
  for (int i = 0; i < numsSize; i++) {
    int j = fmax(nums[i] - k, prev + 1);
    if (j <= nums[i] + k) {
      prev = j;
      ans++;
    }
  }
  return ans;
}

int main() {
  int n1[] = {1, 2, 2, 3, 3, 4}, n2[] = {4, 4, 4, 4};
  printf("%d\n", maxDistinctElements(n1, ARRAY_SIZE(n1), 2)); // expect: 6
  printf("%d\n", maxDistinctElements(n2, ARRAY_SIZE(n2), 1)); // expect: 3
}
