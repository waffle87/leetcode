// 453. Minimum Moves to Equal Array Elements
#include "leetcode.h"

/*
 * given an integer array 'nums' of size 'n', return the minimum number of moves
 * required to make all array elements equal. in one move you can increment 'n -
 * 1' elements of the array by 1
 */

int cmp(const void *a, const void *b) {
  int aa = *(const int *)a;
  int bb = *(const int *)b;
  return (aa > bb) - (aa < bb);
}

int minMoves(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int cnt = 0;
  for (int i = numsSize - 1; i > 0; i--)
    cnt += nums[i] - nums[0];
  return cnt;
}

int main() {
  int n1[] = {1, 2, 3}, n2[] = {1, 1, 1};
  int r1 = minMoves(n1, ARRAY_SIZE(n1));
  int r2 = minMoves(n2, ARRAY_SIZE(n2));
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 0);
}
