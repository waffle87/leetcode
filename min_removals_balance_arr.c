// 3634. Minimum Removals to Balance Array
#include "leetcode.h"

/*
 * you are given an integer array 'nums' and an integer 'k'. an array is
 * considered balance if the value of its maximum element is at most 'k' times
 * the minimum element. you may remove any number of elements from 'nums'
 * without making it empty. return the minimum number of elements so that the
 * remaining array is balanced. note an array of size 1 is considered to be
 * balance as its maximum and minimum are equal, and the condition always holds
 * true.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int minRemoval(int *nums, int numsSize, int k) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int left = 0, ans = 0;
  for (int right = 0; right < numsSize; ++right) {
    while ((long long)nums[right] > (long long)k * nums[left])
      left++;
    ans = fmax(ans, right - left + 1);
  }
  return numsSize - ans;
}

int main() {
  int n1[] = {2, 1, 5}, n2[] = {1, 6, 2, 9}, n3[] = {4, 6};
  int r1 = minRemoval(n1, ARRAY_SIZE(n1), 2);
  int r2 = minRemoval(n2, ARRAY_SIZE(n2), 3);
  int r3 = minRemoval(n3, ARRAY_SIZE(n3), 2);
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == 0);
}
