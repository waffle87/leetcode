// 1590. Make Sum Divisible by P
#include "leetcode.h"

/*
 *given an array of positive integers 'nums', remove the smallest subarray
 *(possibly empty) such that the sum of the remaining elements is divisible by
 *'p'. it is not allowed to remove the whole array. return the length of the
 *smallest subarray that you need to remove, or -1 if it is impossible. a
 *subarray is defined as a contiguous block of elements in the array.
 */

int minSubarray(int *nums, int numsSize, int p) {
  long sum = 0, prefix = 0;
  for (int i = 0; i < numsSize; i++)
    sum += nums[i];
  long target = sum % p;
  if (!target)
    return 0;
  int *map = (int *)malloc(p * sizeof(int));
  for (int i = 0; i < p; i++)
    map[i] = -2;
  memset(map, -2, p * sizeof(int));
  map[0] = -1;
  int ans = numsSize;
  for (int i = 0; i < numsSize; i++) {
    prefix = (prefix + nums[i]) % p;
    int need = (prefix - target + p) % p;
    if (map[need] != -2)
      ans = (i - map[need] < ans ? i - map[need] : ans);
    map[prefix] = i;
  }
  free(map);
  return ans == numsSize ? -1 : ans;
}

int main() {
  int n1[] = {3, 1, 4, 2}, n2[] = {6, 3, 5, 2}, n3[] = {1, 2, 3};
  printf("%d\n", minSubarray(n1, ARRAY_SIZE(n1), 6)); // expect: 1
  printf("%d\n", minSubarray(n2, ARRAY_SIZE(n2), 9)); // expect: 2
  printf("%d\n", minSubarray(n3, ARRAY_SIZE(n3), 3)); // expect: 0
}
