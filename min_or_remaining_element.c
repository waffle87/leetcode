// 3022. Minimize OR of Remaining Elements Using Operations
#include "leetcode.h"

/*
 * given a 0 indexed integer array 'nums' and an integer 'k'. in one operation,
 * you can pick any index 'i' of 'nums' such that '0 <= i < nums.len - 1' and
 * replace 'nums[i]' and 'nums[i + 1]' with a single occurence of 'nums[i] &
 * nums[i + 1]' where & represents the bitwise and operation. return the minimum
 * possible value of the bitwise or of the remaining elements of 'nums' after
 * applying at most 'k' operations.
 */

int minOrAfterOperations(int *nums, int numsSize, int k) {
  int max_elem = nums[0], v = (1 << 30) - 1, mask = 0;
  for (int i = 1; i < numsSize; i++)
    if (nums[i] > max_elem)
      max_elem = nums[i];
  for (int i = 29; i >= 0; --i) {
    int curr = 1 << i;
    mask |= curr;
    if (curr > max_elem)
      continue;
    int tmp = numsSize;
    bool vis = false;
    for (int j = 0; j < numsSize && tmp > k; --tmp) {
      int c = nums[i++];
      for (; i < tmp && c & mask; c &= nums[i++])
        ;
      if (c & mask)
        break;
      vis = true;
    }
    if (!vis || tmp > k)
      mask ^= curr;
  }
  return v ^ mask;
}

int main() {
  int n1[] = {3, 5, 3, 2, 7}, n2[] = {7, 3, 15, 14, 2, 8},
      n3[] = {10, 7, 10, 3, 9, 14, 9, 4};
  printf("%d\n", minOrAfterOperations(n1, ARRAY_SIZE(n1), 2));  // expect: 3
  printf("%d\n", minOrAfterOperations(n2, ARRAY_SIZE(n2), 4));  // expect: 2
  printf("%d\n", minOrAfterOperations(n3, ARRAY_SIZE(n3), 15)); // expect: 15
}
