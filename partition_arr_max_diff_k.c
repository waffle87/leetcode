// 2294. Partition Array Such That Maximum Difference Is K
#include "leetcode.h"

/*
 * you are given an integer array 'nums' and an integer 'k'. you may partition
 * 'nums' into one or more subsequences such that each element in 'nums' appears
 * in exactly one of the subsequences. return the minimum number of subsequences
 * needed such that the difference between the maximum and minimum values in
 * each subsequence is at most 'k'. a subsequence is a sequence that can be
 * derived from another sequence by deleting some or no elements without
 * changing the order of the remaining elements.
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int partitionArray(int *nums, int numsSize, int k) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int ans = 1, j = 0;
  for (int i = 1; i < numsSize; i++)
    if (nums[i] - nums[j] > k) {
      ans++;
      j = i;
    }
  return ans;
}

int main() {
  int n1[] = {3, 6, 1, 2, 5}, n2[] = {1, 2, 3}, n3[] = {2, 2, 4, 5};
  printf("%d\n", partitionArray(n1, ARRAY_SIZE(n1), 2)); // expect: 2
  printf("%d\n", partitionArray(n2, ARRAY_SIZE(n2), 1)); // expect: 2
  printf("%d\n", partitionArray(n3, ARRAY_SIZE(n3), 0)); // expect: 3
}
