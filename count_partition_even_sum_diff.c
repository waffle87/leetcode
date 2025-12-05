// 3432. Count Partitions with Even Sum Difference
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n'. a partition is defined
 * as an index 'i' where '0 <= i < n - 1', splitting the array into two
 * non-empty subarrays such that left subarray contains indices '[0, i]' and the
 * right subarray contains indices '[i + 1, n - 1]'. return the number of
 * partitions where the difference between the sum of the left and right
 * subarrays is even.
 */

int countPartitions(int *nums, int numsSize) {
  int n = 1;
  for (int i = 0; i < numsSize; i++)
    n ^= nums[i];
  return (n & 1) * (numsSize - 1);
}

int main() {
  int n1[] = {10, 10, 3, 7, 6}, n2[] = {1, 2, 2}, n3[] = {2, 4, 6, 8};
  printf("%d\n", countPartitions(n1, ARRAY_SIZE(n1))); // expect: 4
  printf("%d\n", countPartitions(n2, ARRAY_SIZE(n2))); // expect: 0
  printf("%d\n", countPartitions(n3, ARRAY_SIZE(n3))); // expect: 3
}
