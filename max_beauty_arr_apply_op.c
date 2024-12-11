// 2779. Maximum Beauty of an Array After Applying Operation
#include "leetcode.h"

/*
 * you are given a 0-indexed array 'nums' and a non-negative integer 'k'. in one
 * operation you can do the following: choose an index 'i' that hasn't been
 * chosen before from the range '[0, nums.len - 1]', replace 'nums[i]' with any
 * integer from the range '[nums[i] - k, nums[i] + k]'. the beauty of the array
 * is the length of the longest subsequence consisting of equal elements. return
 * the maximum possible beauty of the array 'nums' after applying the operation
 * any number of times. note that you can apply the operation to each index only
 * once. a subsequence of an array is a new array generate from the original
 * array by deleting some elements (possibly none) without changing the order of
 * the remaining elements.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int maximumBeauty(int *nums, int numsSize, int k) {
  int i = 0, j;
  qsort(nums, numsSize, sizeof(int), cmp);
  for (j = 0; j < numsSize; j++)
    if (nums[j] - nums[i] > k * 2)
      i++;
  return j - i;
}

int main() {
  int n1[] = {4, 6, 1, 2}, n2[] = {1, 1, 1, 1};
  printf("%d\n", maximumBeauty(n1, ARRAY_SIZE(n1), 2));  // expect: 3
  printf("%d\n", maximumBeauty(n2, ARRAY_SIZE(n2), 10)); // expect: 4
}
