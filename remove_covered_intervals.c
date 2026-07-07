// 1288. Remove Covered Intervals
#include "leetcode.h"

/*
 * given an array 'intervals' where 'intervals[i] = '[l_i, r_i]' represent the
 * interval. remove all intervals that are covered by another interval in the
 * list. the interval '[a, b)' is covered by the interval '[c, d)' if and only
 * if 'c <= a' and 'b <= d'. return the number of remaining intervals.
 */

int cmp(const void *a, const void *b) {
  int *aa = *(int **)a, *bb = *(int **)b;
  if (aa[0] == bb[0])
    return bb[1] - aa[1];
  return aa[0] - bb[0];
}

int removeCoveredIntervals(int **intervals, int intervalsSize,
                           int *intervalsColSize) {
  qsort(intervals, intervalsSize, sizeof(int *), cmp);
  int ans = intervalsSize, k = INT_MIN;
  for (int i = 0; i < intervalsSize; i++) {
    if (k < intervals[i][1])
      k = intervals[i][1];
    else
      ans--;
  }
  return ans;
}

int main() {
  int i1i[3][2] = {{1, 4}, {3, 6}, {2, 8}};
  int i2i[2][2] = {{1, 4}, {2, 3}};
  struct two_d_arr *i1 =
      two_d_arr_init(ARRAY_SIZE(i1i), ARRAY_SIZE(i1i[0]), i1i);
  struct two_d_arr *i2 =
      two_d_arr_init(ARRAY_SIZE(i2i), ARRAY_SIZE(i2i[0]), i2i);
  int r1 = removeCoveredIntervals(i1->arr, i1->row_size, i1->col_size);
  int r2 = removeCoveredIntervals(i2->arr, i2->row_size, i2->col_size);
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 1);
  two_d_arr_free(i1);
  two_d_arr_free(i2);
}
