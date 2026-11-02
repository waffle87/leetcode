// 462. Minimum Moves to Equal Array Elements II
#include "leetcode.h"

/*
 * given an integer array 'nums' of size 'n', return the minimum number of moves
 * required to make all array elements equal. in one move, you can increment or
 * decrement an element of the array by 1.
 */

int cmp(const void *a, const void *b) {
  int aa = *(const int *)a;
  int bb = *(const int *)b;
  return (aa > bb) - (aa < bb);
}

int minMoves2(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int median = nums[numsSize / 2];
  int cnt = 0;
  for (int i = 0; i < numsSize; i++)
    cnt += abs(nums[i] - median);
  return cnt;
}

int main() {
  int n1[] = {1, 2, 3}, n2[] = {1, 10, 2, 9};
  int r1 = minMoves2(n1, ARRAY_SIZE(n1));
  int r2 = minMoves2(n2, ARRAY_SIZE(n2));
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 16);
}
