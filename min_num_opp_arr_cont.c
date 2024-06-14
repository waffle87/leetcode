// 2009. Minimum Number of Operations to Make Array Continuous
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * you are given an integer array 'nums'. in one operation, you can replace any
 * element in 'nums' with any integer. 'nums' is considered continuous if both
 * of the following conditions are fulfilled:
 * - all elements in 'nums' are unique
 * - the difference between the maximum element and the minimum element in
 * 'nums' equals 'nums.len - 1' return the minimum number of operations to make
 * 'nums' continuous.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int minOperations(int *nums, int nums_size) {
  int n = nums_size, idx = 1, ans = INT_MAX, j = 0;
  qsort(nums, n, sizeof(int), cmp);
  int *arr = malloc(n * sizeof(int));
  arr[0] = nums[0];
  for (int i = 1; i < n; i++)
    if (nums[i] != nums[i - 1]) {
      arr[idx] = nums[i];
      idx++;
    }
  for (int i = 0; i < idx; i++)
    while (j < idx && arr[j] - arr[i] + 1 <= n) {
      ans = fmin(ans, n - (j - i + 1));
      j++;
    }
  return ans;
}

int main() {
  int n1[] = {4, 2, 5, 3}, n2[] = {1, 2, 3, 5, 6}, n3[] = {1, 10, 100, 1000};
  printf("%d\n", minOperations(n1, 4)); // expect: 0
  printf("%d\n", minOperations(n2, 5)); // expect: 1
  printf("%d\n", minOperations(n3, 4)); // expect: 3
}
