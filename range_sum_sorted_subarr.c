// 1508. Range Sum of Sorted Subarray Sums
#include "leetcode.h"

/*
 * you are given the array 'nums' consisting of 'n' positive integers. you
 * computed the sum of all non empty continuous subarrays from the array and
 * then sorted them in non decreasing order, creating a new array of 'n * (n +
 * 1) / 2' numbers. return the sum of the numbers from index 'left' to index
 * 'right' inclusive, in the new array. since the answer may be very large,
 * return it modulo 1e9+7
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int rangeSum(int *nums, int numsSize, int n, int left, int right) {
  int size = n * (n + 1) / 2, cnt = 0, idx = 0, mod = 1e9 + 7;
  int *arr = (int *)malloc(size * sizeof(int));
  for (int i = 0; i < numsSize; i++) {
    cnt = 0;
    for (int j = i; j < numsSize; j++) {
      cnt += nums[j];
      arr[idx++] = cnt;
    }
  }
  qsort(arr, size, sizeof(int), cmp);
  long long ans = 0;
  for (int i = left - 1; i < right; i++)
    ans = (ans + arr[i]) % mod;
  return ans;
}

int main() {
  int n1[] = {1, 2, 3, 4}, n2[] = {1, 2, 3, 4}, n3[] = {1, 2, 3, 4};
  printf("%d\n", rangeSum(n1, ARRAY_SIZE(n1), 4, 1, 5));  // expect: 13
  printf("%d\n", rangeSum(n2, ARRAY_SIZE(n2), 4, 3, 4));  // expect: 6
  printf("%d\n", rangeSum(n3, ARRAY_SIZE(n3), 4, 1, 10)); // expect: 50
}
