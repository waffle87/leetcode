// 1498. Number of Subsequences That Satisfy the Given Sum Condition
#include "leetcode.h"

/*
 * given an array of integers 'nums' and an integer 'target'
 * return the numbe of non-empty subsequences of 'nums' such
 * that the sum of the minimum and maximum element on it is
 * less or equal to 'target'. return modulo 10^9+7
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int numSubseq(int *nums, int numsSize, int target) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int ans = 0, l = 0, r = numsSize - 1, mod = 1e9 + 7;
  int *pows = (int *)malloc(numsSize * sizeof(int));
  pows[0] = 1;
  for (int i = 1; i < numsSize; ++i)
    pows[i] = (pows[i - 1] << 1) % mod;
  while (l <= r) {
    if (nums[l] + nums[r] > target) {
      --r;
      continue;
    }
    ans = (ans + pows[r - l]) % mod;
    ++l;
  }
  free(pows);
  return ans;
}

int main() {
  int n1[] = {3, 5, 6, 7};
  int n2[] = {3, 3, 6, 8};
  int n3[] = {2, 3, 3, 4, 6, 7};
  printf("%d\n", numSubseq(n1, ARRAY_SIZE(n1), 9));  // expect: 4
  printf("%d\n", numSubseq(n2, ARRAY_SIZE(n2), 10)); // expect: 6
  printf("%d\n", numSubseq(n3, ARRAY_SIZE(n3), 12)); // expect: 61
}
