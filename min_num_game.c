// 2974. Minimum Number Game
#include "leetcode.h"

/*
 * given a 0-indexed array 'ums' of even length and there is also an empty array
 * 'arr'. alice and bob decided to play a game where in every round alice and
 * bob will do one move. the rules of the game are as follows: every round,
 * first alice will remove the minimum element from 'nums', and then bob does
 * the same. now, first bob will append the removed element in the array 'arr'
 * and alice does the same. the game continues until 'nums' becomes empty.
 * return the resulting array 'arr'.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int *numberGame(int *nums, int numsSize, int *returnSize) {
  int *arr = (int *)malloc(sizeof(int) * numsSize);
  qsort(nums, numsSize, sizeof(int), cmp);
  for (int i = 0; i < numsSize; i += 2) {
    arr[i] = nums[i + 1];
    arr[i + 1] = nums[i];
  }
  *returnSize = numsSize;
  return arr;
}

int main() {
  int n1[] = {5, 4, 2, 3}, n2[] = {2, 5};
  int rs1 = 0, rs2 = 0;
  int *ng1 = numberGame(n1, ARRAY_SIZE(n1), &rs1);
  int *ng2 = numberGame(n2, ARRAY_SIZE(n2), &rs2);
  for (int i = 0; i < ARRAY_SIZE(n1); i++)
    printf("%d ", ng1[i]);
  printf("\n");
  for (int i = 0; i < ARRAY_SIZE(n2); i++)
    printf("%d ", ng2[i]);
  printf("\n");
  free(ng1), free(ng2);
}
