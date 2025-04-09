// 3375. Minimum Operations to Make Array Values Equal to K
#include "leetcode.h"

/*
 * you are given an integer array 'nums' and an integer 'k'. an integer 'h' is
 * called valid if all values in the array that are strictly greater than 'h'
 * are identical. for example, if 'nums = [10, 8, 10, 8]', a valid integer is 'h
 * = 9' because all 'nums[i] > 9' are equal to 10, but 5 is not a valid integer.
 * you are allowed to perform the following operation on 'nums': select an
 * integer 'h' that is valid for the current value in 'nums', for each index 'i'
 * where 'nums[i] > h', set 'nums[i]' to 'h'. return the minimum number of
 * operations required to make every element in 'nums' equal to 'k'. if it is
 * impossible, return -1
 */

int minOperations(int *nums, int numsSize, int k) {
  ulong bits[2] = {0};
  int distinct = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] < k)
      return -1;
    if (!(bits[nums[i] / 64] & (ulong)1 << (nums[i] % 64)) && nums[i] > k) {
      distinct++;
      bits[nums[i] / 64] |= (ulong)1 << (nums[i] % 64);
    }
  }
  return distinct;
}

int main() {
  int n1[] = {5, 2, 5, 4, 5}, n2[] = {2, 1, 2}, n3[] = {9, 7, 5, 3};
  printf("%d\n", minOperations(n1, ARRAY_SIZE(n1), 2)); // expect: 2
  printf("%d\n", minOperations(n2, ARRAY_SIZE(n2), 2)); // expect: -1
  printf("%d\n", minOperations(n3, ARRAY_SIZE(n3), 1)); // expect: 4
}
