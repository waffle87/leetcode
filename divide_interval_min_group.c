// 2406. Divide Intervals Into Minimum Number of Groups
#include "leetcode.h"

/*
 * you are given a 2d integer array 'intervals' where 'intervals[i] = [left,
 * right]' represents the inclusive interval '[left, right]'. you have to divide
 * the intervals into one or more groups such that each interval is in exactly
 * one group, and no two intervals that are in the same group intersect each
 * other. return the minimum number of groups you need to make. two intervals
 * intersect if there is at least one common number between them.
 */

int minGroups(int **intervals, int intervalsSize, int *intervalsColSize) {
  int max_val = 0;
  for (int i = 0; i < intervalsSize; i++)
    if (intervals[i][1] > max_val)
      max_val = intervals[i][1];
  int *arr = (int *)calloc(max_val + 2, sizeof(int));
  for (int i = 0; i < intervalsSize; i++) {
    arr[intervals[i][0]]++;
    arr[intervals[i][1] + 1]--;
  }
  int ans = 0, curr = 0;
  for (int i = 0; i <= max_val; i++) {
    curr += arr[i];
    if (curr > ans)
      ans = curr;
  }
  free(arr);
  return ans;
}

int main() {
  int i1[5][2] = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}}, ics1 = 5;
  int i2[4][2] = {{1, 3}, {5, 6}, {8, 10}, {11, 13}}, ics2 = 4;
  printf("%d\n", minGroups((int **)i1, ARRAY_SIZE(i1), &ics1)); // expect: 3
  printf("%d\n", minGroups((int **)i2, ARRAY_SIZE(i2), &ics2)); // expect: 1
}
