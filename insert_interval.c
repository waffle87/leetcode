// 57. Insert Interval
#include "leetcode.h"

/*
 * return array of arrays of size '*returnSize'
 * the sizes of the arrays are returned as '*returnColumnSizes' array
 * note both returned array and '*columnSizes' array must be malloced (assume
 * caller free()'s memory)
 */

int **insert(int **intervals, int intervalsSize, int *intervalsColSize,
             int *newInterval, int newIntervalSize, int *returnSize,
             int **returnColumnSizes) {
  *returnSize = 0;
  int left = newInterval[0], right = newInterval[1];
  bool placed = false;
  int **ans = malloc(sizeof(int *) * (intervalsSize + 1));
  *returnColumnSizes = malloc(sizeof(int *) * (intervalsSize + 1));
  for (int i = 0; i < intervalsSize; i++) {
    int *intval = intervals[i];
    if (intval[0] > right) {
      if (!placed) {
        int *tmp = malloc(sizeof(int) * 2);
        tmp[0] = left;
        tmp[1] = right;
        (*returnColumnSizes)[*returnSize] = 2;
        ans[(*returnSize)++] = tmp;
        placed = true;
      }
      int *tmp = malloc(sizeof(int) * 2);
      memcpy(tmp, intval, sizeof(int) * 2);
      (*returnColumnSizes)[*returnSize] = 2;
      ans[(*returnSize)++] = tmp;
    } else if (intval[1] < left) {
      int *tmp = malloc(sizeof(int) * 2);
      memcpy(tmp, intval, sizeof(int) * 2);
      (*returnColumnSizes)[*returnSize] = 2;
      ans[(*returnSize)++] = tmp;
    } else {
      left = fmin(left, intval[0]);
      right = fmax(right, intval[1]);
    }
  }
  if (!placed) {
    int *tmp = malloc(sizeof(int) * 2);
    tmp[0] = left;
    tmp[1] = right;
    (*returnColumnSizes)[*returnSize] = 2;
    ans[(*returnSize)++] = tmp;
  }
  return ans;
}
