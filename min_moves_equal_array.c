// 453. Minimum Moves to Equal Array Elements
#include "leetcode.h"

/*
 * given an integer array 'nums' of size 'n', return the minimum number of moves
 * required to make all array elements equal. in one move you can increment 'n -
 * 1' elements of the array by 1
 */

int minMoves(int *nums, int numsSize) {
  int sum = 0, min = nums[0];
  for (int i = 0; i < numsSize; i++) {
    sum += nums[i];
    min = fmin(min, nums[i]);
  }
  return sum - numsSize * min;
}

int main() {
  int n1[] = {1, 2, 3}, n2[] = {1, 1, 1};
  printf("%d\n", minMoves(n1, ARRAY_SIZE(n1))); // expect: 3
  printf("%d\n", minMoves(n2, ARRAY_SIZE(n2))); // expect: 0
}
