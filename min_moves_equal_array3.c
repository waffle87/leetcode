// 3736. Minimum Moves to Equal Array Elements III
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. in one move, you may increase the
 * value of any single element 'nums[i]' by 1. return the minimum total number
 * of moves required so that all elements in 'nums' become equal.
 */

int minMoves(int *nums, int numsSize) {
  int max = nums[0], ans = 0;
  for (int i = 1; i < numsSize; i++)
    max = fmax(max, nums[i]);
  for (int i = 0; i < numsSize; i++)
    ans += max - nums[i];
  return ans;
}

int main() {
  int n1[] = {2, 1, 3}, n2[] = {4, 4, 5};
  int r1 = minMoves(n1, ARRAY_SIZE(n1));
  int r2 = minMoves(n2, ARRAY_SIZE(n2));
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 2);
}
