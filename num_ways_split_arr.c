// 2270. Number of Ways to Split Array
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums' of lenght 'n'. 'nums' contains
 * a valid split at index 'i' if the following are true: the sum of the first 'i
 * + 1' elements is greater than or equal to the sum of the last 'n - i - 1'
 * elements, and there is at least one element to the right of 'i'. return the
 * number of valid splits in 'nums'.
 */

int waysToSplitArray(int *nums, int numsSize) {
  long long end = 0, start = 0;
  for (int i = 0; i < numsSize; i++)
    end += nums[i];
  int ans = 0;
  for (int i = 0; i < numsSize - 1; i++) {
    start += nums[i];
    end -= nums[i];
    if (start >= end)
      ans++;
  }
  return ans;
}

int main() {
  int n1[] = {10, 4, -8, 7}, n2[] = {2, 3, 1, 0};
  printf("%d\n", waysToSplitArray(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", waysToSplitArray(n2, ARRAY_SIZE(n2))); // expect: 2
}
