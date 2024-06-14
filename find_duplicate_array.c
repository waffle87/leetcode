// 442. Find All Duplicates in an Array
#include "leetcode.h"

/*
 * given an integer array 'nums' of length 'n' where all the integers of 'nums'
 * are in the range '[1, n]' and each integer appears once or twice, return an
 * array of all the integers that appear twice. you must write an algorithm that
 * runs in 'O(n)' time and uses only constant extra space.
 */

int *findDuplicates(int *nums, int numsSize, int *returnSize) {
  *returnSize = 0;
  if (!nums || numsSize < 2)
    return 0;
  int *ans = NULL;
  for (int i = 0; i < numsSize; i++) {
    int n = abs(nums[i]) - 1;
    if (nums[n] < 0) {
      (*returnSize)++;
      ans = realloc(ans, sizeof(int) * *returnSize);
      ans[*returnSize - 1] = abs(nums[i]);
    } else
      nums[n] = -1 * nums[n];
  }
  return ans;
}

int main() {
  int n1[] = {4, 3, 2, 7, 8, 2, 3, 1}, n2[] = {1, 1, 2}, n3[] = {1}, rs1, rs2,
      rs3;
  int *fd1 = findDuplicates(n1, ARRAY_SIZE(n1), &rs1);
  int *fd2 = findDuplicates(n2, ARRAY_SIZE(n2), &rs2);
  int *fd3 = findDuplicates(n3, ARRAY_SIZE(n3), &rs3);
  if (fd1)
    for (int i = 0; i < rs1; i++)
      printf("%d ", fd1[i]);
  else
    printf("NULL");
  printf("\n");
  if (fd2)
    for (int i = 0; i < rs2; i++)
      printf("%d ", fd2[i]);
  else
    printf("NULL");
  printf("\n");
  if (fd3)
    for (int i = 0; i < rs3; i++)
      printf("%d ", fd3[i]);
  else
    printf("NULL");
  printf("\n");
  free(fd1), free(fd2), free(fd3);
}
