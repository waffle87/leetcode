// 532. K-diff Pairs in an Array
#include "leetcode.h"

/*
 * given an array of integers 'nums' and an integer 'k', return the number of
 * unique pair '(nums[i], nums[j])' where the following are true: '0 <= i, j <
 * nums.len', 'i != j', and '| nums[i] - nums[j] == k'.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

bool check(int *nums, int numsSize, int val) {
  int left = 0, right = numsSize - 1, mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (nums[mid] == val)
      return 1;
    if (val > nums[mid])
      left = mid + 1;
    else
      right = mid - 1;
  }
  return 0;
}

int findPairs(int *nums, int numsSize, int k) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int ans = 0;
  for (int i = 0; i < numsSize - 1; i++) {
    if (i && nums[i] == nums[i - 1])
      continue;
    if (check(&nums[i + 1], numsSize - i - 1, k + nums[i]))
      ans++;
  }
  return ans;
}

int main() {
  int n1[] = {3, 1, 4, 1, 5}, n2[] = {1, 2, 3, 4, 5}, n3[] = {1, 3, 1, 5, 4};
  printf("%d\n", findPairs(n1, ARRAY_SIZE(n1), 2)); // expect: 2
  printf("%d\n", findPairs(n2, ARRAY_SIZE(n2), 4)); // expect: 4
  printf("%d\n", findPairs(n3, ARRAY_SIZE(n3), 1)); // expect: 1
}
