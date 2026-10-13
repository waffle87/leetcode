// 3727. Maximum Alternating Sum of Squares
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. you may rearrange the elements in any
 * order. return an integer denoting the maximum possible alternating score of
 * 'nums' after rearranging its elements.
 */

int cmp(const void *a, const void *b) {
  int aa = abs(*(int *)a);
  int bb = abs(*(int *)b);
  return aa - bb;
}

long long maxAlternatingSum(int *nums, int numsSize) {
  long long ans = 0;
  int n = numsSize / 2;
  qsort(nums, numsSize, sizeof(int), cmp);
  for (int i = n; i < numsSize; i++)
    ans += (nums[i] * nums[i]);
  for (int i = 0; i < n; i++)
    ans -= (nums[i] * nums[i]);
  return ans;
}

int main() {
  int n1[] = {1, 2, 3};
  int n2[] = {1, -1, 2, -2, 3, -3};
  long long r1 = maxAlternatingSum(n1, ARRAY_SIZE(n1));
  long long r2 = maxAlternatingSum(n2, ARRAY_SIZE(n2));
  printf("%lld\n", r1);
  assert(r1 == 12);
  printf("%lld\n", r2);
  assert(r2 == 16);
}
