// 3066. Minimum Operations to Exceed Threshold Value II
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums', and an integer 'k'. in one
 * operation, you will take the two smallest integers 'x' and 'y' in 'nums',
 * remove 'x' and 'y' from 'nums', and add 'min(x, y) * 2 + max(x, y)' anywhere
 * in the array. note that you can only apply the described operation if 'nums'
 * contains at least two elements. return the minimum number of operations
 * needed so that all elements of the array are greater than or equal to 'k'.
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int minOperations(int *nums, int numsSize, int k) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int *arr = (int *)malloc(numsSize * sizeof(int));
  for (int i = 0, j = 0, m = 0, cnt = 0, x, y;; ++cnt) {
    x = i < numsSize && (j >= m || nums[i] <= arr[j]) ? nums[i++] : arr[j++];
    if (x >= k) {
      free(arr);
      return cnt;
    }
    y = i < numsSize && (j >= m || nums[i] <= arr[j]) ? nums[i++] : arr[j++];
    long tmp = 2L * x + y;
    arr[m++] = tmp < k ? (int)tmp : k;
  }
  free(arr);
  return -1;
}

int main() {
  int n1[] = {2, 11, 10, 1, 3}, n2[] = {1, 1, 2, 4, 9};
  printf("%d\n", minOperations(n1, ARRAY_SIZE(n1), 10)); // expect: 2
  printf("%d\n", minOperations(n2, ARRAY_SIZE(n2), 20)); // expect: 4
}
