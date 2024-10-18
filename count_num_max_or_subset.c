// 2044. Count Number of Maximum Bitwise-OR Subsets
#include "leetcode.h"

/*
 * given an integer array 'nums', find the maximum possible bitwise OR of a
 * subset of 'nums' and return the number of different non-empty subsets with
 * the maximum bitwise OR. an array 'a' is a subset of an array 'b' if 'a' can
 * be obtained from 'b' by deleting some (possibly 0) elements of 'b'. two
 * subsets are considered different if the indices of the elements chosen are
 * different. the bitwose OR of an array 'a' is equal to 'a[0] | a[1] | ... |
 * a[n]' (0-indexed)
 */

void backtrack(int *nums, int numsSize, int target, int idx, int pos,
               int *res) {
  if (pos == numsSize)
    return;
  for (int i = pos; i < numsSize; i++) {
    int tmp = idx | nums[i];
    if (tmp == target)
      (*res)++;
    backtrack(nums, numsSize, target, tmp, i + 1, res);
  }
}

int countMaxOrSubsets(int *nums, int numsSize) {
  int max = 0, ans = 0;
  for (int i = 0; i < numsSize; i++)
    max |= nums[i];
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == max)
      ans++;
    backtrack(nums, numsSize, max, nums[i], i + 1, &ans);
  }
  return ans;
}

int main() {
  int n1[] = {3, 1}, n2[] = {2, 2, 2}, n3[] = {3, 2, 1, 5};
  printf("%d\n", countMaxOrSubsets(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", countMaxOrSubsets(n2, ARRAY_SIZE(n2))); // expect: 7
  printf("%d\n", countMaxOrSubsets(n3, ARRAY_SIZE(n3))); // expect: 6
}
