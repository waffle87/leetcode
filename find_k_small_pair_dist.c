// 719. Find K-th Smallest Pair Distance
#include "leetcode.h"

/*
 * the distance of a pair of integers 'a' and 'b' is defined as the absolute
 * different between 'a' and 'b'. given an integer array 'nums' and an integer
 * 'k', return the smallest k'th distance among all the pairs 'nums[i]' and
 * 'nums[j]' where '0 <= i < j < nums.len'.
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int smallestDistancePair(int *nums, int numsSize, int k) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int n = nums[numsSize - 1] + 1, ans;
  int *hash = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < numsSize - 1; i++)
    for (int j = i + 1; j < numsSize; j++)
      hash[nums[j] - nums[i]]++;
  for (ans = 0; ans < n; ans++)
    if (hash[ans]) {
      k -= hash[ans];
      if (k <= 0)
        break;
    }
  return ans;
}

int main() {
  int n1[] = {1, 3, 1}, n2[] = {1, 1, 1}, n3[] = {1, 6, 1};
  printf("%d\n", smallestDistancePair(n1, ARRAY_SIZE(n1), 1)); // expect: 0
  printf("%d\n", smallestDistancePair(n2, ARRAY_SIZE(n2), 2)); // expect: 0
  printf("%d\n", smallestDistancePair(n3, ARRAY_SIZE(n3), 3)); // expect: 5
}
