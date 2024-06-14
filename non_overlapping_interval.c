// 435. Non-overlapping Intervals
#include <stdbool.h>
#include <stdlib.h>

/*
 * given an array of intervals 'intervals' where 'intervals[i] = [start[i],
 * end[i]]', return the minimum number of intervals you need to remove to make
 * the rest of the intervals non-overlapping
 */

int cmp(const void **a, const void **b) {
  int *a1 = *(int **)a;
  int *b1 = *(int **)b;
  if (a1[1] == b1[1])
    return a1[0] - b1[0];
  return a1[1] - b1[1];
}

int eraseOverlapIntervals(int **intervals, int intervals_size,
                          int *intervals_col_size) {
  qsort(intervals, intervals_size, sizeof(int *), cmp);
  int k = intervals[0][1], ans = 0;
  for (int i = 1; i < intervals_size; i++) {
    if (intervals[i][0] < k)
      ans++;
    else
      k = intervals[i][1];
  }
  return ans;
}
