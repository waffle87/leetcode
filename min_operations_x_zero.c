// 1658. Minimum Operations to Reduce X to Zero
#include "leetcode.h"

/*
 * given an integer array 'nums' and an integer 'x'. in one operation, you can
 * either remove the leftmost or the rightmost element from the array 'nums' and
 * subtract its value from 'x'. note that this modifies the array for future
 * operations. return the minimum number of operations to reduce 'x' to exactly
 * 0. if it is possible, otherwise return -1
 */

int minOperations(int *nums, int numsSize, int x) {
  int sum = 0;
  for (int i = 0; i < numsSize; i++)
    sum += nums[i];
  int target = sum - x, curr_sum = 0;
  int max_len = 0, start = 0;
  bool found = false;
  for (int end = 0; end < numsSize; end++) {
    curr_sum += nums[end];
    while (start <= end && curr_sum > target)
      curr_sum -= nums[start++];
    if (curr_sum == target) {
      found = true;
      max_len = fmax(max_len, end - start + 1);
    }
  }
  return found ? numsSize - max_len : -1;
}

int main() {
  int n1[] = {1, 1, 4, 2, 3};
  int n2[] = {5, 6, 7, 8, 9};
  int n3[] = {3, 2, 20, 1, 1, 3};
  int r1 = minOperations(n1, ARRAY_SIZE(n1), 5);
  int r2 = minOperations(n2, ARRAY_SIZE(n2), 4);
  int r3 = minOperations(n3, ARRAY_SIZE(n3), 10);
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == -1);
  printf("%d\n", r3);
  assert(r3 == 5);
}
