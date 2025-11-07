// 698. Partition to K Equal Sum Subsets
#include "leetcode.h"

/*
 * given an integer array 'nums' and an integer 'k', return 'true' if it is
 * possible to divide this array into 'k' non-empty subsets whose sums are all
 * equal.
 */

int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }

bool dfs(int *nums, bool *vis, int curr, int n, int k, int group,
         long long target, long long sum) {
  if (group == k)
    return true;
  if (sum > target)
    return false;
  if (sum == target)
    return dfs(nums, vis, group, n, k, group + 1, target, 0);
  int prev = -1;
  for (int i = curr; i < n; i++) {
    if (vis[i])
      continue;
    if (nums[i] == prev)
      continue;
    vis[i] = true;
    if (dfs(nums, vis, i + 1, n, k, group, target, sum + nums[i]))
      return true;
    vis[i] = false;
    prev = nums[i];
  }
  return false;
}

bool canPartitionKSubsets(int *nums, int numsSize, int k) {
  long long sum = 0;
  for (int i = 0; i < numsSize; i++)
    sum += nums[i];
  if (sum % k)
    return false;
  long long target = sum / k;
  qsort(nums, numsSize, sizeof(int), cmp);
  if (nums[0] > target)
    return false;
  bool vis[16] = {false};
  return dfs(nums, vis, 0, numsSize, k, 0, target, 0);
}

int main() {
  int n1[] = {4, 3, 2, 3, 5, 2, 1}, n2[] = {1, 2, 3, 4};
  printf("%d\n", canPartitionKSubsets(n1, ARRAY_SIZE(n1), 4)); // expect: 1
  printf("%d\n", canPartitionKSubsets(n2, ARRAY_SIZE(n2), 3)); // expect: 0
}
