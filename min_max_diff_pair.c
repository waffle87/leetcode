// 2616. Minimize the Maximum Difference of Pairs
#include <stdio.h>
#include <stdlib.h>

/*
 * given a 0-indexed integer array 'nums' and an integer 'p'. find 'p' pairs of
 * indices of 'nums' such that the maximum difference amongst all the pairs is
 * minimised. also, ensure no index appears more than once amongst that 'p'
 * pairs. note that for a pair of elements at the index 'i' and 'j'. the
 * difference of this pair is '|nums[i] - nums[j]|', where '|x|' represents the
 * absolute value of 'x'. return the minimum maximum difference among all 'p'
 * pairs. we define the maximum of an empty set to be zero.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int minimizeMax(int *nums, int nums_size, int p) {
  qsort(nums, nums_size, sizeof(int), cmp);
  int i, j, left = 0, right = nums[nums_size - 1] - nums[0];
  while (left < right) {
    int mid = (left + right) / 2;
    int cnt = 0;
    for (int i = 0; i + 1 < nums_size; ++i)
      if (mid >= nums[i + 1] - nums[i])
        ++cnt, ++i;
    if (cnt >= p)
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}

int main() {
  int n1[] = {10, 1, 2, 7, 1, 3}, n2[] = {4, 2, 1, 2};
  printf("%d\n", minimizeMax(n1, 6, 2)); // expect: 1
  printf("%d\n", minimizeMax(n2, 4, 1)); // expect: 0
}
