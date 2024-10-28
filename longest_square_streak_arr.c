// 2501. Longest Square Streak in an Array
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. a subsequence of 'nums' is called a
 * square streak if the length of the subsequence is at least 2 and after
 * sorting the subsequence, each element (except the first element) is the
 * square of the previous number. return the length of the longest square streak
 * in 'nums', or '-1' otherwise. a subsequence is an array that can be derived
 * from another array by deleting some or no elements without changing the order
 * of the remaining elements.
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

bool search(long long *nums, int numsSize, long long target) {
  int l = 0, h = numsSize - 1;
  while (l <= h) {
    int m = l + (h - l) / 2;
    if (nums[m] == target)
      return true;
    if (nums[m] < target)
      l = m + 1;
    else
      h = m - 1;
  }
  return false;
}

int longestSquareStreak(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), cmp);
  long long *stk = (long long *)malloc(numsSize * sizeof(long long));
  for (int i = 0; i < numsSize; ++i)
    stk[i] = nums[i];
  long long ans = -1;
  for (int i = 0; i < numsSize; ++i) {
    long long val = (long long)nums[i], cnt = 1;
    while (search(stk, numsSize, val * val)) {
      val *= val;
      cnt++;
    }
    if (cnt > 1 && ans < cnt)
      ans = cnt;
  }
  free(stk);
  return (int)ans;
}

int main() {
  int n1[] = {4, 3, 6, 16, 8, 2}, n2[] = {2, 3, 5, 6, 7};
  printf("%d\n", longestSquareStreak(n1, ARRAY_SIZE(n1))); // expect: 3
  printf("%d\n", longestSquareStreak(n2, ARRAY_SIZE(n2))); // expect: -1
}
